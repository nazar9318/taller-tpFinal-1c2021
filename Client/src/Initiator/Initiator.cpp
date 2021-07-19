#include "Initiator.h"

Initiator::Initiator(ModelRecieverThread& rcv, EventSenderThread& snd,
		 ProtectedQueue<Event>& m_events,
		 ProtectedQueue<std::unique_ptr<Event>>& c_events, bool& active,
		 std::string& port, std::string& host):
		 receiver(rcv), sender(snd),
		 model_events(m_events), client_events(c_events),
		 active(active), port(port), host(host) {
}

void Initiator::launch(Socket& socket, int argc,
		char** argv, bool &game_started,
		std::map<char, std::string>& players, char& self_id,
		bool& user_name_charged, std::string& name) {
	QApplication a(argc, argv);
	MainWindow w(socket, game_started, receiver,
			sender, model_events, client_events,
			players, self_id, active, user_name_charged, name, port, host);
	w.show();
	a.exec();
}


Initiator::~Initiator() {}
