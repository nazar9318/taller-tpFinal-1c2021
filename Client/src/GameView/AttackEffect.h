#ifndef __ATTACK_EFFECT_H__
#define __ATTACK_EFFECT_H__

#include <SDL2/SDL.h>
#include <map>
#include <list>

#include "Renderer.h"
#include "Texture.h"
#include "Camera.h"
#include "ClientPlayer.h"
#include "ClientCharacter.h"
#include "Attack.h"

#define BLOOD_WIDTH 64
#define BLOOD_HEIGHT 64

class AttackEffect {

  private:
    Renderer& renderer;
    Camera& camera;
    ClientPlayer& player;
    std::map<char, ClientCharacter>& characters;

    std::list<Attack> attacks;

    Texture blood;

    char player_id;


  public:
    AttackEffect(Renderer& renderer, Camera& camera, char player_id, ClientPlayer& player, std::map<char, ClientCharacter>& characters);

    void loadMedia();

    void createAttack(char id_receiver, char id_attacker);

    void render();

    ~AttackEffect();

  private:
    void renderBlood();
    AttackEffect(const AttackEffect &other) = delete;
    AttackEffect& operator=(const AttackEffect &other) = delete;

};

#endif
