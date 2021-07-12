#ifndef __BOMB_EFFECT_H__
#define __BOMB_EFFECT_H__

#include <SDL2/SDL.h>
#include "Renderer.h"
#include "Texture.h"
#include "Camera.h"

#include "BombState.h"
#include "ClientPlayer.h"

class ClientBomb {

  private:
    Renderer& renderer;
    Camera& camera;
    ClientPlayer& player;

    Texture progress_bar;
    SDL_Rect progress_bar_clips[10];

    Texture explosion;
    SDL_Rect explosion_clips[10];

    Texture bomb_in_ground;

    char state;
    char id_owner;
    char player_id;
    bool has_owner;

    int x;
    int y;
    int percentage;


  public:
    ClientBomb(Renderer& renderer, Camera& camera, char player_id, ClientPlayer& player);

    void loadMedia();

    void set_normal_state(bool has_owner, char id_owner, int x_pos, int y_pos);

    void set_activating_state(char id_owner, int percentage);

    void set_deactivating_state(char id_owner, int percentage);

    void set_activated_state(char id_owner, int x, int y, int time_until_explote);

    void set_exploted_state();

    void set_deactivated_state();

    void render();

    ~ClientBomb();

  private:
    void render_bomb_in_ground();
    void render_activating_bomb();
    void render_deactivating_bomb();
    void render_explosion();
    void loadBarClips();
    void loadExplosionClips();
    ClientBomb(const ClientBomb &other) = delete;
    ClientBomb& operator=(const ClientBomb &other) = delete;

};

#endif
