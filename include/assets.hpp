#ifndef ASSETS_HPP
#define ASSETS_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <iostream>

namespace fr0sty {
    class Assets {
        private:
            

        public:
            Assets() {}

            SDL_Texture *loadTexture(const char *path, SDL_Renderer *renderer);
            SDL_Surface *loadSurface(const char *path);

            SDL_Surface *cropSprite(SDL_Surface *surface, int x, int y, int c, int r);

    }; // 		 !Assets
}	// 		 !fr0sty
#endif // 		 !ASSETS_HPP
