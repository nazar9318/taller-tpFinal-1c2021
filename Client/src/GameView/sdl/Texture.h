#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>
#include "Renderer.h"
#include "SDLException.h"

struct Color {
    uint8_t r, g, b;
};

class Texture {

  private:
    SDL_Texture* texture;
    int width = 0;
    int height = 0;


  public:

    Texture();

    void loadFromFile(const Renderer& renderer, std::string filePath);
    void loadFromFile(const Renderer& renderer, std::string filePath, Color key);
    void loadFromFile(const Renderer& renderer, std::string filePath, Color key, SDL_BlendMode blending, uint8_t alpha);

    SDL_Texture* getTexture() const;

    int get_w();
    int get_h();

    //Libera la textura
    void free();

    ~Texture();

    Texture(Texture&& other) = default;
    Texture& operator=(Texture&& other) = default;

};

#endif
