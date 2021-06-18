#ifndef MOVE_HANDLER_H
#define MOVE_HANDLER_H

#include "ClientEventHandler.h"

class MoveHandler: public ClientEventHandler{
  private:
    std::vector<char> msg;
    int id;

  public:
    MoveHandler(std::vector<char> message, int id);

    virtual void handle() override;

    ~MoveHandler();

};


#endif
