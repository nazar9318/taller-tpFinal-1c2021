#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QWindow>
#include <syslog.h>
#include <string>

#define TITLE "Counter Strike"
#define USER_NAME_PAGE 5
#define PRINCIPAL_PAGE 0
#define MAPS_FOR_CREATE_PAGE 1
#define MATCHES_FOR_JOIN_PAGE 2
#define JOIN_MATCH_WAITING 3
#define CREATE_MATCH_WAITING 4
#define MIN_NAME_LENGTH 4


MainWindow::MainWindow(Socket& skt, bool &started,
		 ModelRecieverThread& rcv, EventSenderThread& snd,
		 ProtectedQueue<Event>& m_events,
		 ProtectedQueue<std::unique_ptr<Event>>& c_events,
		 std::map<char, PlayerInformation>& users,
		 QWidget *parent)
 		: socket(skt), game_started(started), receiver(rcv),
 		 sender(snd), model_events(m_events),
 		 client_events(c_events), players(users), QMainWindow(parent),
 		 ui(new Ui::MainWindow) {
   	ui->setupUi(this);
	this->setStyleSheet("background-color: white;");
	ui->stackedWidget->setCurrentIndex(USER_NAME_PAGE);
	setWindowTitle(TITLE);
	players_joined_timer = new QTimer(this);
    connect(players_joined_timer, SIGNAL(timeout()), this, SLOT(update_players()));
	matches_timer = new QTimer(this);
    connect(matches_timer, SIGNAL(timeout()), this, SLOT(update_matches()));
}


// POST: Boton de la primera pantalla mostrada.
//       Se pide un nombre de usuario.
void MainWindow::on_buttonBox_accepted() {
	user_name = ui->textEdit->toPlainText().toStdString();
	if (user_name.length() < MIN_NAME_LENGTH) {
		show_error("El nombre es demasiado corto");
		return;
	}
	SendUserNameEvent user_event(user_name);
	protocol.send_event(socket, user_event.get_msg());
	ui->stackedWidget->setCurrentIndex(PRINCIPAL_PAGE);
}


// POST: Abre una ventana de error con el mensaje
//       correspondiente.
void MainWindow::show_error(const QString& message) {
	QMessageBox msgBox;
	msgBox.setWindowTitle(TITLE);
	msgBox.setText(message);
	msgBox.setStandardButtons(QMessageBox::Ok);
	msgBox.exec();
}

void MainWindow::show_error(const QString& message,
					 const Event& event) {
	// SI NOS MANDAN UN EVENTO DE TIPO ERROR
	// IMPRIMIMOS EL ERROR.
	show_error(message);
}



/******************************************************/
/******************SECUENCIA DE CREATE*****************/
/******************************************************/



// POST: Cuando se aprieta el boton de crear,
//       se piden los mapas al servidor y se
//       abre una nueva pagina con los mismos.
void MainWindow::on_createButton_clicked() {
	ReceiveMapsEvent recv_maps;
	protocol.send_event(socket, recv_maps.get_msg());
	Event maps_received = protocol.recv_event(socket);
	if (maps_received.get_type() != ModelTypeEvent::SEND_MAPS) {
		show_error("error al intentar recibir los mapas actuales", maps_received);
		return;
	}
	show_maps(maps_received);
	ui->stackedWidget->setCurrentIndex(MAPS_FOR_CREATE_PAGE);
}


void MainWindow::show_maps(Event& maps_received) {
	std::vector<char> msg = maps_received.get_msg();
	unsigned i = 1;
	QStringList maps;
	while (i < maps_received.get_size()) {
		std::string map_name(&msg[i]);
		QString str = QString::fromUtf8(map_name.c_str());
		maps << str;
		i += map_name.length() + 1;
	}
	MapsWidget* maps_buttons = new MapsWidget(maps, this);
	ui->mapList->addWidget(maps_buttons);
}


// POST: Al apretar el boton de crear el match con el nombre,
//       se crea una partida con ese mapa.
void MainWindow::createMatch(const QString& map_name) {
	QString qname = QInputDialog::getText(this, "entrada", "Ingrese un"
										" nombre para la partida");
    std::string match_name = qname.toStdString();
    if (match_name.length() < MIN_NAME_LENGTH) {
		show_error("El nombre es demasiado corto");
		return;
	}
    CreateMatchEvent create(match_name, map_name.toStdString());
    protocol.send_event(socket, create.get_msg());
    Event is_successful = protocol.recv_event(socket);
	if (is_successful.get_type() == ModelTypeEvent::SUCCESSFUL_ENTRY) {
		syslog(LOG_INFO, "[%s:%i]: Se creo la partida %s"
			, __FILE__, __LINE__, match_name.c_str());
		// seria la posicion 2 en el protocolo. 
		char id = is_successful.get_msg()[1];
		PlayerInformation this_player(user_name, true);
		players[id] = std::move(this_player);
	    ui->stackedWidget->setCurrentIndex(CREATE_MATCH_WAITING);
	    receiver.start();
	    players_joined_timer->start(1000);
	} else {
		show_error("error al intentar crear la partida."
					"falta aclarar cual es el error");
	}
}

void MainWindow::update_players() {
	bool players_waiting = true;
    while(players_waiting) {
    	try {
    		Event model_event = model_events.pop();
			switch (model_event.get_type()) {
				case ModelTypeEvent::PLAYERS_ID_LIST:
					{
						update_players_list(model_event);
						break;
					}
				case ModelTypeEvent::GAME_STARTED:
					{
						players_waiting = false;
						sender.start();
						players_joined_timer->stop();
						game_started = true;
						this->close();
						break;
					}
				default:
					{
						syslog(LOG_CRIT, "[%s:%i]: Se recibe un tipo inesperado."
						, __FILE__, __LINE__);	
					}
			}
		} catch (ExceptionEmptyQueue& e) {
			players_waiting = false;
		}	
    }
}



// POST: Al apretar el boton de iniciar la partida, se
//       cierra qt para comenzar sdl.
void MainWindow::on_pushButton_clicked() {
	StartGameEvent starter;
	protocol.send_event(socket, starter.get_msg());

}



/******************************************************/
/******************SECUENCIA DE JOIN*******************/
/******************************************************/



// POST: Cuando se aprieta en join, se reciben las partidas
// actuales y se las agrega a la lista de partidas.
void MainWindow::on_joinButton_clicked() {
	matches_timer->start(1000);
	ui->stackedWidget->setCurrentIndex(MATCHES_FOR_JOIN_PAGE);
}


void MainWindow::update_matches() {
	ReceiveMatchesEvent recv_matches;
	protocol.send_event(socket, recv_matches.get_msg());
	Event matches_received = protocol.recv_event(socket);
	if (matches_received.get_type() != ModelTypeEvent::SEND_MATCHES) {
		show_error("error al intentar recibir las partidas actuales");
		return;
	}
	clean_matches();
	show_matches(matches_received);
}



void MainWindow::show_matches(Event& matches_received) {
	std::vector<char> msg = matches_received.get_msg();
	unsigned i = 1;
	QStringList matches;
	while (i < matches_received.get_size()) {
		std::string match_name(&msg[i]);
		syslog(LOG_INFO, "[%s:%i]: Se lee de show matches el match %s"
			, __FILE__, __LINE__, match_name.c_str());
		QString str = QString::fromUtf8(match_name.c_str());
		matches << str;
		i += match_name.length() + 1;
	}
	MatchesWidget* matches_buttons = new MatchesWidget(matches, this);
	ui->matchsList->addWidget(matches_buttons);
}


void MainWindow::clean_matches() {
	while (ui->matchsList->count()) {
		QWidget* widget = ui->matchsList->itemAt(0)->widget();
		if (widget) {
			ui->matchsList->removeWidget(widget);
			delete widget;
		}
	}
}

// POST: Al apretar el boton de la partida en particular
//       se une a la partida.
void MainWindow::joinMatch(const QString &text) {
	std::string match_name = text.toStdString();
	JoinMatchEvent joiner_event(match_name);
	protocol.send_event(socket, joiner_event.get_msg());
	Event is_successful = protocol.recv_event(socket);
	if (is_successful.get_type() != ModelTypeEvent::SUCCESSFUL_ENTRY) {
		show_error("error al intentar unirse a la partida."
					"falta aclarar cual es el error");
		return;
	}
	char id = is_successful.get_msg()[1];
	PlayerInformation this_player(user_name, true);
	players[id] = std::move(this_player);
	matches_timer->stop();
	ui->stackedWidget->setCurrentIndex(JOIN_MATCH_WAITING);
	syslog(LOG_INFO, "[%s:%i]: Se unio a la partida %s"
			, __FILE__, __LINE__, match_name.c_str());

	receiver.start();
	players_joined_timer->start();
}

void MainWindow::update_players_list(Event& players_list) {
	syslog(LOG_INFO, "[%s:%i]: Por cargar lista de jugadores"
		, __FILE__, __LINE__);
	ui->players_join->clear();
	ui->players_create->clear();
	std::vector<char> msg = players_list.get_msg();
	unsigned i = 1;
	// se que el mensaje es del tipo id_1Nombre_1id_2Nombre_2...
    std::map<char, PlayerInformation> new_players;
	while (i < players_list.get_size()) {
		char player_id = msg[i];
		i++;
		std::string player_name(&msg[i]);
		syslog(LOG_INFO, "[%s:%i]: Por cargar jugador con id %d y nombre %s"
					, __FILE__, __LINE__, player_id, player_name.c_str());
		if (players.find(player_id) != players.end()) {
			new_players[player_id] = std::move(players[player_id]);
		} else {
			PlayerInformation player(player_name);
			new_players[player_id] = std::move(player);
			//new_players.emplace(std::make_pair(player_id, player));
		}
		ui->players_join->addItem(QString::fromStdString(player_name));
		ui->players_create->addItem(QString::fromStdString(player_name));
		i += player_name.length() + 1;
	}
	players.swap(new_players);
}


MainWindow::~MainWindow() {
	delete ui;
}
