#include "MatchesWidget.h"
/*
MatchesWidget::MatchesWidget(QStringList texts,
 QWidget *parent): QWidget(parent) {
	signalMapper = new QSignalMapper(this);

	QGridLayout *gridLayout = new QGridLayout;
	for (int i = 0; i < texts.size(); ++i) {
		QPushButton *button = new QPushButton(texts[i]);
		connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
		signalMapper->setMapping(button, texts[i]);
		gridLayout->addWidget(button, i / 3, i % 3);
	}

	connect(signalMapper, static_cast<void(QSignalMapper::*)(const QString &)>(&QSignalMapper::mapped),
		[=](const QString &text) { 
			QString qname = QInputDialog::getText(this, "entrada", "Ingrese un nombre");
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
				char id = is_successful.get_msg()[2];
				PlayerInformation this_player(user_name, true);
				//players.emplace(std::make_pair(id, this_player));
				players[id] = std::move(this_player);
				//players.insert({id, std::move(this_player)});
				ui->stackedWidget->setCurrentIndex(3);
				receiver.start();
			} else {
				show_error("error al intentar crear la partida."
							"falta aclarar cual es el error");
			} 


		});

	setLayout(gridLayout);
}
*/