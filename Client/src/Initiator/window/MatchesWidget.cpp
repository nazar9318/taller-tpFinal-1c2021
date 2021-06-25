#include "MatchesWidget.h"

MatchesWidget::MatchesWidget(QStringList texts, MainWindow* main_w,
 QWidget *parent): QWidget(parent), main(main_w) {
	signalMapper = new QSignalMapper(this);
	QGridLayout* gridLayout = new QGridLayout;
	for (int i = 0; i < texts.size(); ++i) {
		QPushButton *button = new QPushButton(texts[i]);
		connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
		signalMapper->setMapping(button, texts[i]);
		gridLayout->addWidget(button, i / 3, i % 3);
	}

	connect(signalMapper, static_cast<void(QSignalMapper::*)
		(const QString &)>(&QSignalMapper::mapped), [=](const QString &text) { 
			main->joinMatch(text);
		});
	setLayout(gridLayout);
}
