#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include <SDL/SDL.h>

#include "settings.hpp"

namespace fr0sty {
    class Game {
        private:
            SDL_Window *window;
            SDL_Renderer *renderer;

            SDL_Event event;

            bool running;

        public:
            Game() {}

            void init();
            bool initVars();
            bool initWindow();

            void quit();
            
            void update();
            void preRender();
            void render();
            void postRender();
            void events();

             bool getRunning() { return running; }

            void write(std::string msg, bool endl) { if (endl) std::cout << msg << std::endl; else std::cout << msg; }

        };	// 		 !Game
}	// 		 !fr0sty
#endif // 		 !GAME_HPP