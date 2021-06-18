#include "Initiator.h"



Initiator::Initiator(GameMap& game_map):
		  				map(game_map) {
}


		
// returns true if player is logged in. 
bool Initiator::launch(Socket& socket) {
	// CONEXION SINCRONICA: SEND-RECV
	// LOGICA DE BIENVENIDA
	// QAPPLICATION
	// ETAPA INICIAL DE ELECCION DE COLORES PARA LOS BANDOS







 	// EJEMPLO PARA PROBAR






	std::cout << "No me la Counter Strike" << std::endl;


	enum TypeOfLine {
		Create, 
		Join,  
		List, 
		Undefined
	};
#define NAME_POS_JOIN 7
#define NAME_POS_CREATE 6
#define COLUMN_POS 6
#define ROW_POS 8
	#define CREATE "crear"
#define SIZE_CREATE 5
#define LIST "listar"
#define JOIN "unirse"
#define SIZE_JOIN 6
#define PLAY "jugar"
#define SIZE_PLAY 5
#define PLAY_LEN 9
#define BEGIN 0
#define ASCII_ONE 49
#define ASCII_THREE 51
	class Parser {
		public:
			Parser() {}

			// POST: Dependiendo de la estructura de la linea, retorna
			//       el enum correspondiente.  
			TypeOfLine type_of_line(const std::string& line) const {
		if ((line.length() > SIZE_CREATE + 2) &&
			 (line.substr(0, SIZE_CREATE) == CREATE))
			return TypeOfLine::Create;
		if (line == LIST)
			return TypeOfLine::List;
		if ((line.length() > SIZE_JOIN + 2) && (line.substr(0, SIZE_JOIN) == JOIN))
			return TypeOfLine::Join;
		return TypeOfLine::Undefined;
	}

			// POST: Si la linea contiene alguna de las frases correspondidas
			//       a la finalizacion de la partida, retorna true. Caso 
			//       contrario, retorna false. 
			~Parser() {}
		private:
			Parser(const Parser &other) = delete;
			Parser& operator=(const Parser &other) = delete;
	};
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
					//harcodeo tipo
					GameWorldType w_type = GameWorldType::DEFAULT;
					socket.send_message((char*)&w_type, 1);
					// termino harcodeo
					std::cout << "Press key any" << std::endl;
					std::getline(std::cin, line);
					ClientEvent event(START_GAME);
					protocol.send_event(socket, event);
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
				ModelEvent starter_event;
				protocol.recv_event(socket, starter_event);
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

Initiator::~Initiator() {}