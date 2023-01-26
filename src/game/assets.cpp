#include "assets.hpp"

namespace fr0sty {

    SDL_Texture *Assets::loadTexture(const char *path, SDL_Renderer *renderer) {

        SDL_Texture *texture;
        texture = IMG_LoadTexture(renderer, path);

        if (texture == NULL) {
          std::cout << "LOCUST: " << "Could not load texture: " << SDL_GetError() << std::endl;
        }

        return texture;
    }

    SDL_Surface *Assets::loadSurface(const char *path) {
        SDL_Surface *surface;

        surface = IMG_Load(path);

        if (surface == NULL) {
            std::cout << "LOCUST: " << "Could not load surface: " << SDL_GetError() << std::endl;
        }

        return surface;
    }

    SDL_Surface *Assets::cropSprite(SDL_Surface *spriteSheet, int x, int y, int c, int r) {
        SDL_Surface *rSurface = SDL_CreateRGBSurface(spriteSheet->flags, c*32, r*32, spriteSheet->format->BitsPerPixel, 
                                                    spriteSheet->format->Rmask, spriteSheet->format->Gmask, 
                                                    spriteSheet->format->Bmask, spriteSheet->format->Amask); 
        
        SDL_Rect rect = { x*32, y*32, c*32, r*32 };
        SDL_BlitSurface(spriteSheet, &rect, rSurface, 0);

        if(rSurface == NULL) {
            std::cout << "LOCUST: " << "Could not crop sprite sheet: " << SDL_GetError() << std::endl;
        }

        return rSurface;
    }

} //    ! fr0sty
