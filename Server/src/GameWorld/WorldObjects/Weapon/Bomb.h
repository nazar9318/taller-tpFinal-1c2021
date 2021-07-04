#ifndef BOMB_H
#define BOMB_H
/*
#include "TypesOfEvents.h"


enum BombState: char {
    NORMAL,
    ACTIVATED, 
    DEACTIVATED, 
    ACTIVAITING, 
    DEACTIVATING, 
    EXPLOTED
};

class Bomb {
    private:
        int clock_count;
        BombState state;
        bool has_owner;
        char id_owner;
        int x_pos;
        int y_pos;

    public:
        Bomb();
                
        void simulate_step() {
            switch (state) {
                case BombState::ACTIVATED:
                {
                    clock_count++;
                    if (clock_count * TIME_STEP >= TIME_BOMB_EXPLOTE)
                        state = BombState::EXPLOTED;
                }                
                case BombState::ACTIVAITING:
                {
                    clock_count++;
                    if (clock_count * TIME_STEP >= TIME_BOMB_ACTIVATE) {
                       state = BombState::ACTIVATED;
                       clock_count = 0;
                    }    
                }
                case BombState::DEACTIVATING: 
                {
                    clock_count++;
                    if (clock_count * TIME_STEP >= TIME_BOMB_DEACTIVATE)
                        state = BombState::DEACTIVATED;
                }              
            }
            
        }
        
        bool activate(char id) {
            if (has_owner && (id_owner == id)) {
                state = BombState::ACTIVATING;
                clock_count = 0;
                return true;
            }
            return false;
        }
        
        bool drop(char id, int x, int y) {
            if (id == id_owner) {
                has_owner = false;
                state = BombState::NORMAL;
                pos_x = x;
                pos_y = y;
                clock_count = 0;
                return true;
            }
            return false;
        }
        
        bool grab(char id, Team team) {
            if ((!has_owner) && (team == Team::TERRORIST)) {
                id_owner = id;
                clock_count = 0;
                has_owner = true;
                return true;
            }
            return false;
        }

        bool deactivate(Team team) {
            if (team == Team::COUNTER_ENEMY) {
                state = BombState::DEACTIVATING;
                return true;
            }
            return false;
        }

        ~Bomb();
};
*/
#endif
