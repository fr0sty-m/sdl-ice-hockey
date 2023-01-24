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
            STATE gameState;

            float _dt;
            
            bool running;

        public:
            Game() = default;

            /// @brief A method for initializing everything
            void init();

            /// @brief A method for initializing variables
            /// @return True if everything initialized correctly
            bool initVars();

            /// @brief A method for initializing window
            /// @return True if everything initialized correctly
            bool initWindow();

            /// @brief A method for cleaning and exiting program
            void quit();
            
            /// @brief A method for updating
            /// @param dt Delta Time
            void update(float dt);

            /// @brief A method for pre rendering
            void preRender();

            /// @brief A method for rendering
            void render();

            /// @brief A method for post rendering
            void postRender();

            /// @brief A method for polling events
            void events();

            /// @brief A getter method for getting running variable
            /// @return boolean running
            bool getRunning() { return running; }

            /// @brief A setter method for delta time
            /// @param dt Parameter for setting delta time
            void setDT(float dt) { _dt = dt; }
            /// @brief A getter method for delta time
            /// @return float dt
            float getDT() { return _dt;}

            Clock* getClock() { return &_clock; }

            /// @brief A method for console output 
            /// @param msg Parameter for output message
            /// @param endl Parameter for new line or not
            void write(std::string msg, bool endl) { if (endl) std::cout << "SYSTEM: " << msg << std::endl; else std::cout << "SYSTEM: " << msg; }
            /// @brief A method for console output 
            /// @param msg Parameter for output message
            /// @param endl Parameter for new line or not
            void write(float msg, bool endl) { if (endl) std::cout << "SYSTEM: " << msg << std::endl; else std::cout << "SYSTEM: " << msg; }
            /// @brief A method for console output 
            /// @param msg Parameter for output message
            /// @param endl Parameter for new line or not
            void write(int msg, bool endl) { if (endl) std::cout << "SYSTEM: " << msg << std::endl; else std::cout << "SYSTEM: " << msg; }

        };	// 		 !Game
}	// 		 !fr0sty
#endif // 		 !GAME_HPP
