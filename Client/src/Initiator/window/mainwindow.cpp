#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QWindow>
#include <syslog.h>
#include <string>

#define TITLE "Counter Strike"
#define SOCKET_PAGE 0
#define USER_NAME_PAGE 1
#define SKINS_PAGE 2
#define PRINCIPAL_PAGE 3
#define MAPS_FOR_CREATE_PAGE 4
#define MATCHES_FOR_JOIN_PAGE 5
#define JOIN_MATCH_WAITING 6
#define CREATE_MATCH_WAITING 7

#define MIN_NAME_LENGTH 4

MainWindow::MainWindow(Socket& skt, bool &started,
         ModelRecieverThread& rcv, EventSenderThread& snd,
         ProtectedQueue<Event>& m_events,
         ProtectedQueue<std::unique_ptr<Event>>& c_events,
         std::map<char, std::string>& users, char& id, bool& active,
         bool& user_name_charged, std::string& name,
				 std::string& port, std::string& host,
         QWidget *parent)
        : socket(skt), game_started(started), receiver(rcv),
         sender(snd), model_events(m_events),
         client_events(c_events), players(users), self_id(id),
          match_started(false), active(active),
          user_name_charged(user_name_charged), user_name(name), chosed_skins(0),
					port(port), host(host), QMainWindow(parent),
          ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
    active = false;
    if (!user_name_charged) {
        ui->stackedWidget->setCurrentIndex(SOCKET_PAGE);
    } else {
				socket.connect_to(host, port);
        SendUserNameEvent user_event(user_name);
        protocol.send_event(socket, user_event.get_msg());
        ui->stackedWidget->setCurrentIndex(SKINS_PAGE);
    }
    setWindowTitle(TITLE);
    players_joined_timer = new QTimer(this);
    connect(players_joined_timer, SIGNAL(timeout()), this, SLOT(update_players()));
    matches_timer = new QTimer(this);
    connect(matches_timer, SIGNAL(timeout()), this, SLOT(update_matches()));
    ui->lineEdit->setPlaceholderText("Ingrese su nombre");
    this->ui->host->setPlaceholderText("Ingrese host");
    this->ui->port->setPlaceholderText("Ingrese port");
    connect(this->ui->ARTIC_AVENGER, SIGNAL(clicked()), this, SLOT(select_terrorist_skin()));
    connect(this->ui->PHOENIX, SIGNAL(clicked()), this, SLOT(select_terrorist_skin()));
    connect(this->ui->L337KREW, SIGNAL(clicked()), this, SLOT(select_terrorist_skin()));
    connect(this->ui->GUERRILLA, SIGNAL(clicked()), this, SLOT(select_terrorist_skin()));
    connect(this->ui->SEAL_FORCE, SIGNAL(clicked()), this, SLOT(select_counter_skin()));
    connect(this->ui->GERMAN_GSG9, SIGNAL(clicked()), this, SLOT(select_counter_skin()));
    connect(this->ui->UKSAS, SIGNAL(clicked()), this, SLOT(select_counter_skin()));
    connect(this->ui->FRENCH_GIGN, SIGNAL(clicked()), this, SLOT(select_counter_skin()));
		connect(this->ui->acceptSkins, SIGNAL(clicked()), this, SLOT(on_acceptSkins_clicked()));
		loadSkinsIcons();
}

void MainWindow::loadSkinsIcons() {
	QPixmap pixARTIC_AVENGER(SPRITE_NPC_ARTIC_AVENGER_PATH);
	QIcon iconARTIC_AVENGER(pixARTIC_AVENGER);
	this->ui->ARTIC_AVENGER->setIcon(iconARTIC_AVENGER);
	this->ui->ARTIC_AVENGER->setIconSize(pixARTIC_AVENGER.rect().size());
	QPixmap pixPHOENIX(SPRITE_NPC_PHOENIX_PATH);
	QIcon iconPHOENIX(pixPHOENIX);
	this->ui->PHOENIX->setIcon(iconPHOENIX);
	this->ui->PHOENIX->setIconSize(pixPHOENIX.rect().size());
	QPixmap pixL337KREW(SPRITE_NPC_L337_KREW_PATH);
	QIcon iconL337KREW(pixL337KREW);
	this->ui->L337KREW->setIcon(iconL337KREW);
	this->ui->L337KREW->setIconSize(pixL337KREW.rect().size());
	QPixmap pixGUERRILLA(SPRITE_NPC_GUERRILLA_PATH);
	QIcon iconGUERRILLA(pixGUERRILLA);
	this->ui->GUERRILLA->setIcon(iconGUERRILLA);
	this->ui->GUERRILLA->setIconSize(pixGUERRILLA.rect().size());
	QPixmap pixSEAL_FORCE(SPRITE_NPC_SEAL_FORCE_PATH);
	QIcon iconSEAL_FORCE(pixSEAL_FORCE);
	this->ui->SEAL_FORCE->setIcon(iconSEAL_FORCE);
	this->ui->SEAL_FORCE->setIconSize(pixSEAL_FORCE.rect().size());
	QPixmap pixGERMAN_GSG9(SPRITE_NPC_GERMAN_GSG9_PATH);
	QIcon iconGERMAN_GSG9(pixGERMAN_GSG9);
	this->ui->GERMAN_GSG9->setIcon(iconGERMAN_GSG9);
	this->ui->GERMAN_GSG9->setIconSize(pixGERMAN_GSG9.rect().size());
	QPixmap pixUKSAS(SPRITE_NPC_UKSAS_PATH);
	QIcon iconUKSAS(pixUKSAS);
	this->ui->UKSAS->setIcon(iconUKSAS);
	this->ui->UKSAS->setIconSize(pixUKSAS.rect().size());
	QPixmap pixFRENCH_GIGN(SPRITE_NPC_FRENCH_GIGN_PATH);
	QIcon iconFRENCH_GIGN(pixFRENCH_GIGN);
	this->ui->FRENCH_GIGN->setIcon(iconFRENCH_GIGN);
	this->ui->FRENCH_GIGN->setIconSize(pixFRENCH_GIGN.rect().size());
}

void MainWindow::select_terrorist_skin() {
    QPushButton* terrorist_skin = (QPushButton*)QObject::sender();
    std::string name = terrorist_skin->objectName().toStdString();
    if (name.compare("ARTIC_AVENGER") == 0) {
        CCF::terrorist_skin = TerroristSkin::ARTIC_AVENGER;
    } else if (name.compare("PHOENIX") == 0) {
        CCF::terrorist_skin = TerroristSkin::PHOENIX;
    } else if (name.compare("L337KREW") == 0) {
        CCF::terrorist_skin = TerroristSkin::L337KREW;
    } else if (name.compare("GUERRILLA") == 0) {
        CCF::terrorist_skin = TerroristSkin::GUERRILLA;
    }
    this->chosed_skins++;
}

void MainWindow::select_counter_skin() {
    QPushButton* terrorist_skin = (QPushButton*)QObject::sender();
    std::string name = terrorist_skin->objectName().toStdString();
    if (name.compare("SEAL_FORCE") == 0) {
        CCF::counter_skin = CounterSkin::SEAL_FORCE;
    } else if (name.compare("GERMAN_GSG9") == 0) {
        CCF::counter_skin = CounterSkin::GERMAN_GSG9;
    } else if (name.compare("UKSAS") == 0) {
        CCF::counter_skin = CounterSkin::UKSAS;
    } else if (name.compare("FRENCH_GIGN") == 0) {
        CCF::counter_skin = CounterSkin::FRENCH_GIGN;
    }
    this->chosed_skins++;
}

void MainWindow::on_acceptSkins_clicked() {
    if (this->chosed_skins >= 2) { ui->stackedWidget->setCurrentIndex(PRINCIPAL_PAGE); }
    else {
        QString err("Para avanzar, debe elegir una skin de cada equipo.");
        show_error(err);
    }
}

void MainWindow::on_startButton_clicked() {
    host = this->ui->host->text().toStdString();
    port = this->ui->port->text().toStdString();
    try {
         socket.connect_to(host, port);
         this->ui->stackedWidget->setCurrentIndex(USER_NAME_PAGE);
    } catch(ExceptionSocketClosed& e) {
         QString exception("Ha ocurrido un problema con la comunicación.");
         show_error(exception);
         QWidget::close();
    } catch(Exception& e) {
         QString exception("No se ha podido conectar, ha ingresado un host o puerto incorrecto.");
         show_error(exception);
    } catch(std::exception& e) {
         QString exception("Ha ocurrido un problema desconocido.");
         show_error(exception);
         QWidget::close();
    } catch(...) {
         QString exception("Ha ocurrido un problema desconocido.");
         show_error(exception);
         QWidget::close();
    }
}

// POST: Boton de la primera pantalla mostrada.
//       Se pide un nombre de usuario.
void MainWindow::on_OK_clicked() {
    try {
        user_name = ui->lineEdit->text().toStdString();
        if (user_name.length() < MIN_NAME_LENGTH) {
            show_error("El nombre es demasiado corto");
            return;
        }
        user_name_charged = true;
        SendUserNameEvent user_event(user_name);
        protocol.send_event(socket, user_event.get_msg());
        ui->stackedWidget->setCurrentIndex(SKINS_PAGE);
    } catch(ExceptionSocketClosed& e) {
        QString exception("Ha ocurrido un problema con la comunicación.");
        show_error(exception);
        QWidget::close();
    } catch(std::exception& e) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    } catch(...) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    }
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

void MainWindow::show_error(const QString& message, Event& event) {
    QString error_msg(message);
    if (event.get_type() == ModelTypeEvent::ERROR) {
        switch (event.get_msg()[1]) {
            case ServerError::MATCH_FULL : {
                error_msg.append(" La partida ha llegado"
                                " al limite de jugadores");
                break;
            }
            case ServerError::NOT_ENOUGH_PLAYERS : {
                error_msg.append(" Falta que se"
                "  unan más jugadores");
                break;
            }
            case ServerError::MATCH_ALREADY_STARTED : {
                error_msg.append(" La partida ya ha comenzado.");
                break;
            }
            case ServerError::INVALID_TYPE_EVENT : {
                error_msg.append(" Se envio un mensaje"
                                " inesperado al servidor.");
                break;
            }
            case ServerError::MATCH_NOT_FOUND : {
                error_msg.append(" No se ha podido"
                                " encontrar la partida.");
                break;
            }
            case ServerError::MATCH_ALREADY_EXISTS : {
                error_msg.append(" Ya existe una partida con este nombre");
                break;
            }
            case ServerError::CREATOR_ABANDONS_MATCH : {
                error_msg.append(" El creador ha abandonado la partida.");
                active = true;
                sender.start();
                players_joined_timer->stop();
                QWidget::close();
                break;
            }
            default : error_msg.append("Error desconocido.");
        }
    }
    show_error(error_msg);
}



/******************************************************/
/******************SECUENCIA DE CREATE*****************/
/******************************************************/



// POST: Cuando se aprieta el boton de crear,
//       se piden los mapas al servidor y se
//       abre una nueva pagina con los mismos.
void MainWindow::on_createButton_clicked() {
    try {
        ReceiveMapsEvent recv_maps;
        protocol.send_event(socket, recv_maps.get_msg());
        Event maps_received = protocol.recv_event(socket);
        if (maps_received.get_type() != ModelTypeEvent::SEND_MAPS) {
            show_error("error al intentar recibir"
                            " los mapas actuales", maps_received);
            return;
        }
        show_maps(maps_received);
        ui->stackedWidget->setCurrentIndex(MAPS_FOR_CREATE_PAGE);
    } catch(ExceptionSocketClosed& e) {
        QString exception("Ha ocurrido un problema con la comunicación.");
        show_error(exception);
        QWidget::close();
    } catch(std::exception& e) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    } catch(...) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    }
}


void MainWindow::show_maps(Event& maps_received) {
    try {
        std::vector<char> msg = maps_received.get_msg();
        unsigned i = 1;
        QStringList maps;
        while (i < maps_received.get_size()) {
            std::string map_name(&msg[i]);
            QString str = QString::fromUtf8(map_name.c_str());
            maps << str;
            i += (unsigned)map_name.length() + 1;
        }
        MapsWidget* maps_buttons = new MapsWidget(maps, this);
        ui->mapList->addWidget(maps_buttons);
    } catch(ExceptionSocketClosed& e) {
        QString exception("Ha ocurrido un problema con la comunicación.");
        show_error(exception);
        QWidget::close();
    } catch(std::exception& e) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    } catch(...) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    }
}


// POST: Al apretar el boton de crear el match con el nombre,
//       se crea una partida con ese mapa.
void MainWindow::createMatch(const QString& map_name) {
    try {
        bool name_inserted = false;
        QLineEdit::EchoMode echo = QLineEdit::Normal;
        QString qname = QInputDialog::getText(this, "entrada", "Ingrese un"
                        " nombre para la partida", echo, "", &name_inserted, NULL, NULL);
        if (!name_inserted) {return;}
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
            self_id = is_successful.get_msg()[1];
            syslog(LOG_INFO, "[%s:%i]: El jugador de id %i crea  la partida", __FILE__, __LINE__, (int)self_id);
            players[self_id] = user_name;
            ui->stackedWidget->setCurrentIndex(CREATE_MATCH_WAITING);
            receiver.start();
            players_joined_timer->start(1000);
        } else {
            show_error("Error al intentar crear la partida", is_successful);
        }
    } catch(ExceptionSocketClosed& e) {
        QString exception("Ha ocurrido un problema con la comunicación.");
        show_error(exception);
        QWidget::close();
    } catch(std::exception& e) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    } catch(...) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    }
}

void MainWindow::update_players() {
    syslog(LOG_CRIT, "[%s:%i]: Timer de players en funcionamiento."
        , __FILE__, __LINE__);
    try {
        bool players_waiting = true;
        while(players_waiting) {
            try {
                Event model_event = model_events.pop();
                switch (model_event.get_type()) {
                    case ModelTypeEvent::PLAYERS_ID_LIST : {
                        syslog(LOG_INFO, "[%s:%i]: Llego mensaje de players list"
                                    , __FILE__, __LINE__);
                        update_players_list(model_event);
                        break;
                    }
                    case ModelTypeEvent::GAME_STARTED : {
                        syslog(LOG_CRIT, "[%s:%i]: Se inicia la partida.", __FILE__, __LINE__);
                        players_waiting = false;
                        sender.start();
                        players_joined_timer->stop();
                        game_started = true;
                        active = true;
                        this->close();
                        break;
                    }
                    case ModelTypeEvent::ERROR : {
                        show_error("Ha ocurrido un error inesperado.", model_event);
                        break;
                    }
                    default : {
                        syslog(LOG_CRIT, "[%s:%i]: Se recibe un tipo inesperado."
                        , __FILE__, __LINE__);
                    }
                }
            } catch (ExceptionEmptyQueue& e) {
                players_waiting = false;
            }
        }
    } catch(ExceptionSocketClosed& e) {
        QString exception("Ha ocurrido un problema con la comunicación.");
        show_error(exception);
        QWidget::close();
    } catch(std::exception& e) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    } catch(...) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    }
}


// POST: Al apretar el boton de iniciar la partida, se
//       cierra qt para comenzar sdl.
void MainWindow::on_pushButton_clicked() {
    try {
        StartGameEvent starter;
        syslog(LOG_CRIT, "[%s:%i]: Creador inicia la partida, por enviar evento.", __FILE__, __LINE__);
        protocol.send_event(socket, starter.get_msg());
    } catch(ExceptionSocketClosed& e) {
        QString exception("Ha ocurrido un problema con la comunicación.");
        show_error(exception);
        QWidget::close();
    } catch(std::exception& e) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    } catch(...) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    }
}



/******************************************************/
/******************SECUENCIA DE JOIN*******************/
/******************************************************/



// POST: Cuando se aprieta en join, se reciben las partidas
// actuales y se las agrega a la lista de partidas.
void MainWindow::on_joinButton_clicked() {
    try {
        matches_timer->start(1000);
        ui->stackedWidget->setCurrentIndex(MATCHES_FOR_JOIN_PAGE);
    } catch(ExceptionSocketClosed& e) {
        QString exception("Ha ocurrido un problema con la comunicación.");
        show_error(exception);
        QWidget::close();
    } catch(std::exception& e) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    } catch(...) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    }
}


void MainWindow::update_matches() {
    try {
        ReceiveMatchesEvent recv_matches;
        protocol.send_event(socket, recv_matches.get_msg());
        Event matches_received = protocol.recv_event(socket);
        if (matches_received.get_type() != ModelTypeEvent::SEND_MATCHES) {
            show_error("error al intentar recibir las partidas "
                            "actuales", matches_received);
            return;
        }
        clean_matches();
        show_matches(matches_received);
    } catch(ExceptionSocketClosed& e) {
        QString exception("Ha ocurrido un problema con la comunicación.");
        show_error(exception);
        QWidget::close();
    } catch(std::exception& e) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    } catch(...) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    }
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
        i += (unsigned)match_name.length() + 1;
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
    try {
        std::string match_name = text.toStdString();
        JoinMatchEvent joiner_event(match_name);
        protocol.send_event(socket, joiner_event.get_msg());
        Event is_successful = protocol.recv_event(socket);
        if (is_successful.get_type() != ModelTypeEvent::SUCCESSFUL_ENTRY) {
            matches_timer->stop();
            show_error("error al intentar unirse a la partida.", is_successful);
            matches_timer->start(1000);
            return;
        }
        self_id = is_successful.get_msg()[1];
        syslog(LOG_INFO, "[%s:%i]: El jugador de id %i se une a la partida", __FILE__, __LINE__, (int)self_id);
        players[self_id] = user_name;
        matches_timer->stop();
        ui->stackedWidget->setCurrentIndex(JOIN_MATCH_WAITING);
        syslog(LOG_INFO, "[%s:%i]: Se unio a la partida %s"
                , __FILE__, __LINE__, match_name.c_str());

        receiver.start();
        players_joined_timer->start(1000);
    } catch(ExceptionSocketClosed& e) {
        QString exception("Ha ocurrido un problema con la comunicación.");
        show_error(exception);
        QWidget::close();
    } catch(std::exception& e) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    } catch(...) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    }
}

void MainWindow::update_players_list(Event& players_list) {
    try {
        syslog(LOG_INFO, "[%s:%i]: Por cargar lista de jugadores"
            , __FILE__, __LINE__);
        ui->players_join->clear();
        ui->players_create->clear();
        std::vector<char> msg = players_list.get_msg();
        unsigned i = 1;
        // se que el mensaje es del tipo id_1Nombre_1id_2Nombre_2...
        std::map<char, std::string> new_players;
        while (i < players_list.get_size()) {
            char player_id = msg[i];
            i++;
            std::string player_name(&msg[i]);
            syslog(LOG_INFO, "[%s:%i]: Por cargar jugador con id %d y nombre %s"
                        , __FILE__, __LINE__, player_id, player_name.c_str());
            if (players.find(player_id) != players.end()) {
                new_players[player_id] = std::move(players[player_id]);
            } else {
                std::string player(player_name);
                new_players[player_id] = std::move(player);
                //new_players.emplace(std::make_pair(player_id, player));
            }
            ui->players_join->addItem(QString::fromStdString(player_name));
            ui->players_create->addItem(QString::fromStdString(player_name));
            i += (unsigned)player_name.length() + 1;
        }
        players.swap(new_players);
    } catch(ExceptionSocketClosed& e) {
        QString exception("Ha ocurrido un problema con la comunicación.");
        show_error(exception);
        QWidget::close();
    } catch(std::exception& e) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    } catch(...) {
        QString exception("Ha ocurrido un problema desconocido.");
        show_error(exception);
        QWidget::close();
    }
}

MainWindow::~MainWindow() { delete ui; }
