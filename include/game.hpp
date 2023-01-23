#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "settings.hpp"
#include "clock.hpp"

namespace fr0sty {

    enum STATE { MENU_STATE, PLAY_STATE, SPLASH_STATE };

    class Game {
        private:
            SDL_Window *window;
            SDL_Renderer *renderer;
            SDL_Surface *surface;
            SDL_Texture *img;

            SDL_Event event;

            Clock _clock;
            float _dt;
            STATE gameState;

            bool running;

        public:
            Game() = default;

            void init();
            bool initVars();
            bool initWindow();

            void quit();
            
            void update(float dt);
            void preRender();
            void render();
            void postRender();
            void events();

            bool getRunning() { return running; }

            void setDT(float dt) { _dt = dt; }
            float getDT() { return _dt;}

            Clock* getClock() { return &_clock; }

            void write(std::string msg, bool endl) { if (endl) std::cout << msg << std::endl; else std::cout << msg; }
            void write(float msg, bool endl) { if (endl) std::cout << msg << std::endl; else std::cout << msg; }
            void write(int msg, bool endl) { if (endl) std::cout << msg << std::endl; else std::cout << msg; }

        };	// 		 !Game
}	// 		 !fr0sty
#endif // 		 !GAME_HPP
