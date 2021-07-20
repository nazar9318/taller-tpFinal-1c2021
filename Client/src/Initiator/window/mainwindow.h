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
#include <QWidget>

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
#include "ClientConfiguration.h"
#include "Paths.h"

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
    std::string& user_name;
    QTimer* matches_timer;
    QTimer* players_joined_timer;
    bool& active;
    bool& user_name_charged;
    std::string& port;
    std::string& host;
public:
    MainWindow(Socket& socket, bool& game_started,
            ModelRecieverThread& receiver,
            EventSenderThread& sender,
            ProtectedQueue<Event>& model_events,
            ProtectedQueue<std::unique_ptr<Event>>& client_events,
            std::map<char, std::string>& players,
            char& self_id, bool& active,
            bool& user_name_charged, std::string& name,
            std::string& port, std::string& host,
            QWidget *parent = nullptr);

    void createMatch(const QString& map_name);
    ~MainWindow();
    void joinMatch(const QString &text);

private slots:
    void on_createButton_clicked();
    void on_joinButton_clicked();
    void update_players();
    void update_matches();
    void on_pushButton_clicked();
    void on_OK_clicked();
    void select_terrorist_skin();
    void select_counter_skin();
    void on_startButton_clicked();
    void on_acceptSkins_clicked();

private:
    Ui::MainWindow* ui;
    Protocol protocol;
    bool match_started;
    int chosed_skins;
    void load_players(Event& join_successfull);
    void wait_until_start();
    void show_error(const QString& message);
    void show_error(const QString& message, Event& event);
    void update_players_list(Event& players_list);
    void show_maps(Event& maps_received);
    void clean_matches();
    void loadSkinsIcons();
    void show_matches(Event& matches_received);
};

#endif
