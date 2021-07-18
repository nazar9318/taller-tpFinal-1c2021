#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <string>
#include "Renderer.h"
#include "SDLException.h"

struct Color {
    uint8_t r, g, b;
};

enum TextType { SOLID_TEXT, BLENDED_TEXT };

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

    void loadFromSurface(Renderer& renderer, SDL_Surface* surface, Color key, SDL_BlendMode blending, uint8_t alpha);

    void loadFromRenderedText(Renderer& renderer, TTF_Font* font, std::string text, SDL_Color color, TextType type);

    SDL_Texture* getTexture() const;

    int get_w();

    int get_h();

    void setColor(Color& color);

    //Libera la textura
    void free();

    ~Texture();

    Texture(Texture&& other) = default;
    Texture& operator=(Texture&& other) = default;

};

#endif
