#ifndef __ATTACK_H__
#define __ATTACK_H__

#define TICKS_TO_RENDER 30

class Attack {

  private:
    char id_receiver;
    char id_attacker;
    int ticks;

  public:
    Attack(char id_receiver, char id_attacker);

    bool addTick();

    char getReceiverId();

    char getAttackerId();

    ~Attack();

    Attack(Attack&& other) = default;
    Attack& operator=(Attack&& other) = default;

  private:
    Attack(const Attack &other) = delete;
    Attack& operator=(const Attack &other) = delete;

};

#endif
