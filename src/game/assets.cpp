#include "assets.hpp"

namespace fr0sty {

    SDL_Texture *Assets::loadTexture(const char *path, SDL_Renderer *renderer) {

        SDL_Texture *texture;
        texture = IMG_LoadTexture(renderer, path);

        if (texture == NULL) {
          std::cout << "LOCUST: " << "Could not initialize texture" << std::endl;
        }

        return texture;
    }

    SDL_Surface *Assets::loadSurface(const char *path) {
        SDL_Surface *surface;

        surface = IMG_Load(path);

        if (surface == NULL) {
            std::cout << "LOCUST: " << "Could not initialize surface" << std::endl;
        }

        return surface;
    }

} //    ! fr0sty
