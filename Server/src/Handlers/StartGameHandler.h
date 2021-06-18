#ifndef START_GAME_HANDLER_H
#define START_GAME_HANDLER_H

#include "ClientEventHandler.h"

class StartGameHandler: public ClientEventHandler{
  private:
    std::vector<char> msg;
    int id;

  public:

    StartGameHandler(std::vector<char> message, int id);
    virtual void handle() override;
    ~StartGameHandler();

};
#endif
