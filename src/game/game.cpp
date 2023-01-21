#include "game.hpp"

namespace fr0sty {
    void Game::init() {
        if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1 && IMG_Init( IMG_INIT_JPG | IMG_INIT_PNG ) == -1) {
            write("COULD NOT INITIALIZE SDL", true);
        }

        if (initVars() == false) {
            write("COULD NOT INITIALIZE VARIABLES", true);
        }        
        if (initWindow() == false) {
            write("COULD NOT INITIALIZE WINDOW", true);
        }
    }

    bool Game::initVars() {

        return running = true;
    }

    bool Game::initWindow() {
        window = SDL_CreateWindow(S_TITLE, CENTER, CENTER, S_WIDTH, S_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_INPUT_FOCUS);
        if (window == nullptr) {
            write("COULD NOT INITIALIZE SDL WINDOW", true);
            return false;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer == nullptr) {
            write("COULD NOT INITIALIZE RENDERER", true);
            return false;
        }
        

        return true;
    }

    void Game::quit() {
        running = false;
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
        IMG_Quit();
    }

    void Game::update(float dt) { 
        
    }

    void Game::preRender() {
        SDL_SetRenderDrawColor(renderer, BG_COLOR);
        SDL_RenderClear(renderer);
    }

    void Game::render() {

    }

    void Game::postRender() {
        SDL_RenderPresent(renderer);
    }

    void Game::events() {
        SDL_PollEvent(&event);

        switch (event.type) {
            case SDL_QUIT:
                quit();
                break;
        }
    }

} // 		 !fr0sty