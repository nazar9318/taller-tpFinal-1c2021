#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QInputDialog>
#include <list>
#include <QLabel>
#include <QHBoxLayout>
#include <QWindow>
#include <iostream>
#include <QTextEdit>
#include <QMessageBox>
#include <map>

#include "PlayerInformation.h"
#include "CreateMatchEvent.h"
#include "JoinMatchEvent.h"
#include "ReceiveMatchesEvent.h"
#include "ReceiveMapsEvent.h"
#include "Protocol.h"
#include "Socket.h"
#include "ProtectedQueue.h"
#include "ModelRecieverThread.h"
#include "EventSenderThread.h"
#include "SendUserNameEvent.h"
#include "StartGameEvent.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Socket& socket;
    bool& game_started;
    ModelRecieverThread& receiver;
    EventSenderThread& sender;
    ProtectedQueue<Event>& client_events;
    ProtectedQueue<Event>& model_events;
    std::map<char, PlayerInformation>& players;
    std::string user_name;
public:
    MainWindow(Socket& socket, bool& game_started,
            ModelRecieverThread& receiver,
            EventSenderThread& sender,
            ProtectedQueue<Event>& model_events, 
            ProtectedQueue<Event>& client_events,
            std::map<char, PlayerInformation>& players, 
            QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_createButton_clicked();

    void on_joinButton_clicked();

    void joinMatch(std::string match_name);
	void on_buttonBox_accepted();
	void on_reload_games_clicked();



private:
    Ui::MainWindow* ui;
    Protocol protocol;
    void load_players(Event& join_successfull);
    void wait_until_start();
    void show_error(const QString& message);
    void show_error(const QString& message, const Event& event);
    void createMatch(std::string map_name);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void update_players_list(Event& players_list);
    void show_maps(Event& maps_received);

};

#endif // MAINWINDOW_H
