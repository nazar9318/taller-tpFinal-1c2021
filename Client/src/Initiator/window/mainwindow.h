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
#include <QSignalMapper>
#include <QTimer>

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
#include "MapsWidget.h"
#include "MatchesWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MapsWidget;
class MatchesWidget;
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Socket& socket;
    bool& game_started;
    ModelRecieverThread& receiver;
    EventSenderThread& sender;
    ProtectedQueue<std::unique_ptr<Event>>& client_events;
    ProtectedQueue<Event>& model_events;
    std::map<char, std::string>& players;
    char& self_id;
    std::string user_name;
    QTimer* matches_timer;
    QTimer* players_joined_timer;
public:
    MainWindow(Socket& socket, bool& game_started,
            ModelRecieverThread& receiver,
            EventSenderThread& sender,
            ProtectedQueue<Event>& model_events,
            ProtectedQueue<std::unique_ptr<Event>>& client_events,
            std::map<char, std::string>& players,
            char& self_id,
            QWidget *parent = nullptr);

    void createMatch(const QString& map_name);
    ~MainWindow();
    void joinMatch(const QString &text);

private slots:
    void on_createButton_clicked();

    void on_joinButton_clicked();

    void on_buttonBox_accepted();
    void update_players();
    void update_matches();
    void on_pushButton_clicked();

private:
    Ui::MainWindow* ui;
    Protocol protocol;
    void load_players(Event& join_successfull);
    void wait_until_start();
    void show_error(const QString& message);
    void show_error(const QString& message, Event& event);
    void update_players_list(Event& players_list);
    void show_maps(Event& maps_received);
    void clean_matches();
    void show_matches(Event& matches_received);


};

#endif // MAINWINDOW_H
