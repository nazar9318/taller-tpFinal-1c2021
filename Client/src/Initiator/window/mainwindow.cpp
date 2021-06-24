#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QWindow>
#include <syslog.h>
#include <string>

#define TITLE "Counter Strike"



MainWindow::MainWindow(Socket& skt, bool &started,
		 ModelRecieverThread& rcv, EventSenderThread& snd,
		 ProtectedQueue<Event>& m_events, 
		 ProtectedQueue<Event>& c_events, 
		 QWidget *parent)
 		: socket(skt), game_started(started), receiver(rcv),
 		 sender(snd), model_events(m_events), 
 		 client_events(c_events), QMainWindow(parent), 
 		 ui(new Ui::MainWindow) {
   	ui->setupUi(this); 
	this->setStyleSheet("background-color: white;");
	ui->stackedWidget->setCurrentIndex(5);
	setWindowTitle(TITLE);

}


// POST: Boton de la primera pantalla mostrada. 
//       Se pide un nombre de usuario. 
void MainWindow::on_buttonBox_accepted() {
	std::string user_name = ui->textEdit->toPlainText().toStdString();
	if (user_name.length() < 3) {
		show_error("El nombre es demasiado corto");
		return;
	}
	SendUserNameEvent user_event(user_name);
	protocol.send_event(socket, user_event.get_msg());
	ui->stackedWidget->setCurrentIndex(0);
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
		show_error("error al intentar recibir los mapas actuales");
		return;
	}
	std::vector<char> msg = maps_received.get_msg();
	unsigned i = 1;
	// IMPRIMO LOS MAPAS
	while (i < maps_received.get_size()) {
		std::string map_name(&msg[i]);
		QPushButton* listed_map = new QPushButton();
		QString str = QString::fromUtf8(map_name.c_str());
		listed_map->setText("Mapa: " + str);
		ui->mapList->addWidget(listed_map);
		connect(listed_map, SIGNAL(pressed()), this, SLOT(createMatch(map_name)));
		i += map_name.length() + 1;
	}
	ui->stackedWidget->setCurrentIndex(1);
}

// POST: Al apretar el boton de crear el match con el nombre, 
//       se crea una partida con ese mapa.      
void MainWindow::createMatch(std::string map_name) {
	QString qname = QInputDialog::getText(this, "entrada", "Ingrese un nombre");
    std::string match_name = qname.toStdString();
    if (match_name.length() < 3) {
		show_error("El nombre es demasiado corto");
		return;
	}
    CreateMatchEvent create(match_name, map_name);
    protocol.send_event(socket, create.get_msg());
    Event is_successfull = protocol.recv_event(socket);
	if (is_successfull.get_type() == ModelTypeEvent::CREATE_SUCCESSFULL) {
		syslog(LOG_INFO, "[%s:%i]: Se unio a la partida %s"
			, __FILE__, __LINE__, match_name.c_str());
	    ui->stackedWidget->setCurrentIndex(3);
	    receiver.start();
	} else {
		show_error("error al intentar unirse a la partida."
					"falta aclarar cual es el error");
	}
}

// POST: Al apretar el boton de iniciar la partida, se
//       cierra qt para comenzar sdl.
void MainWindow::on_pushButton_clicked() {
	StartGameEvent starter; 
	protocol.send_event(socket, starter.get_msg());
	bool not_started = true; 
	while (not_started) {
		Event model_event = model_events.blocking_pop();
		switch (model_event.get_type()) {
			case ModelTypeEvent::PLAYER_JOINED:
			{
				// podriamos que el PLAYER_JOINED haga que se agregue a 
				// map con id, nombre. 
				std::string player_name(&(model_event.get_msg()[1]));
				ui->players_create->addItem(QString::fromStdString(player_name));
				break;
			}
			case ModelTypeEvent::GAME_STARTED: 
			{
				not_started = false;
				sender.start();
				this->close();
				break;
			}
			default:
				syslog(LOG_CRIT, "[%s:%i]: Se recibio un mensaje inesperado"
				, __FILE__, __LINE__); 
		}
	}
}



// POST: Se hace un reload de los jugadores en la 
//       lista. 
void MainWindow::on_pushButton_2_clicked() {
    bool players_waiting = true;
    while(players_waiting) {
    	try {
    		Event model_event = model_events.pop();
			if (model_event.get_type() == ModelTypeEvent::PLAYER_JOINED) {
					// podriamos que el PLAYER_JOINED haga que se agregue a 
					// map con id, nombre. 
					std::string player_name(&(model_event.get_msg()[1]));
					ui->players_create->addItem(QString::fromStdString(player_name));
			} else {
				syslog(LOG_CRIT, "[%s:%i]: Se recibe un tipo inesperado."
				, __FILE__, __LINE__);
			}
		} catch (ExceptionEmptyQueue& e) {
			syslog(LOG_INFO, "[%s:%i]: No hay jugadores para recargar."
				, __FILE__, __LINE__);
		}	
    }
}



/******************************************************/
/******************SECUENCIA DE JOIN*******************/
/******************************************************/

// POST: Cuando se aprieta en join, se reciben las partidas
// actuales y se las agrega a la lista de partidas. 
void MainWindow::on_joinButton_clicked() {
	ui->stackedWidget->setCurrentIndex(2);
	ReceiveMatchesEvent recv_matches;
	protocol.send_event(socket, recv_matches.get_msg());
	Event matches_received = protocol.recv_event(socket);
	if (matches_received.get_type() != ModelTypeEvent::SEND_MATCHES) {
		show_error("error al intentar recibir las partidas actuales");
		return;
	}
	std::vector<char> msg = matches_received.get_msg();
	unsigned i = 1;
	while (i < matches_received.get_size()) {
		std::string match_name(&msg[i]);
		QPushButton* listed_match = new QPushButton();
		QString str = QString::fromUtf8(match_name.c_str());
		listed_match->setText("Partida: " + str);
		ui->matchsList->addWidget(listed_match);
		connect(listed_match, SIGNAL(pressed()), this, SLOT(joinMatch(match_name)));
		i+= match_name.length() + 1;
	}
}

void MainWindow::on_reload_games_clicked() {
	//ui->matchsList->clean();
	// Modularizar en una funcion para estoo. 
	
	// NO PUEDO HACER ESTA FUNCIOON.
	ReceiveMatchesEvent recv_matches;
	protocol.send_event(socket, recv_matches.get_msg());
	Event matches_received = protocol.recv_event(socket);
	if (matches_received.get_type() != ModelTypeEvent::SEND_MATCHES) {
		show_error("error al intentar recibir las partidas actuales");
		return;
	}
	std::vector<char> msg = matches_received.get_msg();
	unsigned i = 1;
	while (i < matches_received.get_size()) {
		std::string match_name(&msg[i]);
		QPushButton* listed_match = new QPushButton();
		QString str = QString::fromUtf8(match_name.c_str());
		listed_match->setText("Partida: " + str);
		ui->matchsList->addWidget(listed_match);
		connect(listed_match, SIGNAL(pressed()), this, SLOT(joinMatch(match_name)));
		i+= match_name.length() + 1;
	}
}


// POST: Al apretar el boton de la partida en particular
//       se une a la partida. 
void MainWindow::joinMatch(std::string match_name) {
	JoinMatchEvent joiner_event(match_name);
	protocol.send_event(socket, joiner_event.get_msg());
	Event is_successfull = protocol.recv_event(socket);
	if (is_successfull.get_type() != ModelTypeEvent::JOIN_SUCCESSFULL) {
		show_error("error al intentar unirse a la partida."
					"falta aclarar cual es el error");
	}
	syslog(LOG_INFO, "[%s:%i]: Se unio a la partida %s"
			, __FILE__, __LINE__, match_name.c_str());

	ui->stackedWidget->setCurrentIndex(3);
	load_players(is_successfull);
	bool not_started = true;
	while (not_started) {
		Event event = protocol.recv_event(socket);
		switch (event.get_type()) {
			case ModelTypeEvent::PLAYER_JOINED:
			{
				std::string player_name(&(event.get_msg()[1]));
				ui->players_join->addItem(QString::fromStdString(player_name));
				break;
			}
			case ModelTypeEvent::GAME_STARTED: 
			{
				receiver.start();
				sender.start();
				not_started = false;
				this->close();
				break;
			}
			default:
				syslog(LOG_CRIT, "[%s:%i]: Se recibio un mensaje inesperado"
				, __FILE__, __LINE__);
		}
	}


}


void MainWindow::load_players(Event& join_successfull) {
	// join_successfull tiene la lista de los jugadores
	// desde la posicion 1. 
	std::vector<char> msg = join_successfull.get_msg();
	unsigned i = 1;
	while (i < join_successfull.get_size()) {
		std::string player_name(&msg[i]);
		ui->players_join->addItem(QString::fromStdString(player_name));
		i += player_name.length() + 1;
	}

}


MainWindow::~MainWindow() { 
	delete ui; 
}
