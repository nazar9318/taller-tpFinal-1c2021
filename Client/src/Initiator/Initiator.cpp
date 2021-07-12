#include "Initiator.h"

Initiator::Initiator(ModelRecieverThread& rcv, EventSenderThread& snd,
		 ProtectedQueue<Event>& m_events, ProtectedQueue<std::unique_ptr<Event>>& c_events):
		 receiver(rcv), sender(snd),
		 model_events(m_events), client_events(c_events) {
}

void Initiator::launch(Socket& socket, int argc,
		char** argv, bool &game_started,
		std::map<char, std::string>& players, char& self_id) {
	QApplication a(argc, argv);
	MainWindow w(socket, game_started, receiver,
			sender, model_events, client_events, players, self_id);
	w.show();
	a.exec();
}

Initiator::~Initiator() {}


/*
bool Initiator::launch(Socket& socket) {
	std::cout << "No me la Counter Strike" << std::endl;
	Protocol protocol;
	Parser parser;
	bool not_started = true;
	std::string name;
	while (not_started) {
		std::string line;
		std::getline(std::cin, line);
		TypeOfLine type = parser.type_of_line(line);
		switch (type) {
			case Configuration:
				{
					std::cout << "Aca deberiamos poder elegir"
								 "los colores de los chaboncitos";
					break;
				}
			case Create:
				{
					name = line.substr(NAME_POS_CREATE);
					protocol.send_create(socket, name);
					std::cout << "Envio crear" << '\n';
					//harcodeo tipo
					char w_map[] = "map1";
					socket.send_message(w_map, 5);
					// termino harcodeo
					std::cout << "Press key any" << std::endl;
					std::getline(std::cin, line);

					StartGameEvent evento;
					Event event = evento.get_event();

					protocol.send_event(socket, event.get_msg());

					std::cout << "Envio startgame event" << '\n';
					not_started = false;
					break;
				}
			case Join:
				{

					name = line.substr(NAME_POS_JOIN);
					protocol.send_join(socket, name);
					not_started = false;
					break;
				}
			default:
				{
					std::cout << "Se ingreso un texto indefinido." << std::endl;
				}
		}
		if (!not_started) {
			try {
				Event starter_event = protocol.recv_event(socket);
				if (starter_event.get_type() != START_GAME)
					throw Exception("No se pudo arrancar la partida");
				map.create(starter_event);
			} catch(ExceptionInvalidCommand& e) {
				std::cout << "El comando enviado es invalido. "
							 "Es posible que haya enviado un nombre incorrecto."
						  << std::endl;
				not_started = true;
			}
		}

	}


	return true;



}
*/
// returns true if player is logged in.
//bool Initiator::launch(Socket& socket) {

	// CONEXION SINCRONICA: SEND-RECV
	// LOGICA DE BIENVENIDA
	// QAPPLICATION
	// ETAPA INICIAL DE ELECCION DE COLORES PARA LOS BANDOS
	// botonCrear, botonUnirse


/*


	|
	|    crear ->    |   MAPA1, MAPA2, MAPA3, | COMENZAR PARTIDA |
	|    UNISE ->    |   PARTIDAS PARA UNIRSE |  ESPERANDO A COMIENZO |
	|    Configuration(no hay comunicacion)
	|
	|
	|
*/
/*


	Parser parser;
	Protocol protocol;
	bool not_started = true;
	std::string name;
	while (not_started) {

		std::string line;
		std::getline(std::cin, line);
		TypeOfLine type = parser.type_of_line(line);
		switch (type) {
			case List:
				{

					protocol.get_list(socket, line);
					std::cout << line;
					break;
				}
			case Create:
				{

					name = line.substr(NAME_POS_CREATE);
					protocol.send_create(socket, name);
					std::cout << "Envio crear" << '\n';
					//harcodeo tipo
					GameWorldType w_type = GameWorldType::DEFAULT;
					socket.send_message((char*)&w_type, 1);
					// termino harcodeo
					std::cout << "Press key any" << std::endl;
					std::getline(std::cin, line);

					StartGameEvent evento;
					Event event = evento.get_event();

					protocol.send_event(socket, event.get_msg());

					std::cout << "Envio startgame event" << '\n';
					not_started = false;
					break;
				}
			case Join:
				{

					name = line.substr(NAME_POS_JOIN);
					protocol.send_join(socket, name);
					not_started = false;
					break;
				}
			default:
				{
					std::cout << "Se ingreso un texto indefinido." << std::endl;
				}
		}
		if (!not_started) {
			try {
				Event starter_event = protocol.recv_event(socket);
				if (starter_event.get_type() != START_GAME)
					throw Exception("No se pudo arrancar la partida");
				map.create(starter_event);
			} catch(ExceptionInvalidCommand& e) {
				std::cout << "El comando enviado es invalido. "
							 "Es posible que haya enviado un nombre incorrecto."
						  << std::endl;
				not_started = true;
			}
		}

	}


	return true;
}
*/
