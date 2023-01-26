#include "game.hpp"

namespace fr0sty {
    void Game::init() {
        if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1 && IMG_Init( IMG_INIT_JPG | IMG_INIT_PNG ) == -1) {
            write("COULD NOT INITIALIZE SDL", true);
        }

        if (initWindow() == false) {
            write("COULD NOT INITIALIZE WINDOW", true);
        }

        if (initVars() == false) {
            write("COULD NOT INITIALIZE VARIABLES", true);
        }        
        
    } //    ! init()


    bool Game::initVars() {
        gameState = PLAY_STATE;

        //icon = loader->loadSurface("assets/sprite/hockey_icon.png");
        //surface = loader->loadSurface("assets/sprite/hockey_sprite.png");
        //texture = loader->loadTexture("assets/sprite/hockey_sprite.png", renderer);

        icon = loader->loadSurface("assets/sprite/hockey_icon.png");
        if (icon == NULL) {
            std::cout << "Could not load icon: " << SDL_GetError() << std::endl;
            return running = false;
        }

        spriteSheet = loader->loadSurface("assets/sprite/hockey_sprite.png");
        if (spriteSheet == NULL) {
            std::cout << "Could not load spriteSheet" << SDL_GetError() << std::endl;
            return running = false;
        }

        pSurface = loader->cropSprite( spriteSheet, 0, 0, 1, 1 );
        if (pSurface == NULL) {
            std::cout << "Could not load playerSurface" << SDL_GetError() << std::endl;
            return running = false;
        }

        playerTex = SDL_CreateTextureFromSurface(renderer, pSurface);
        if (playerTex == NULL) {
            std::cout << "Could not load playerTexture" << SDL_GetError() << std::endl;
            return running = false;
        }


        SDL_SetWindowIcon(window, icon);

        return running = true;
    } //    ! initVars()


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
    } //    ! initWindow()


    void Game::quit() {
        running = false;
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
        IMG_Quit();
    } //    ! quit()


    void Game::update(float dt) { 
        


    } //    ! update()


    void Game::preRender() {
        SDL_SetRenderDrawColor(renderer, BG_COLOR);
        SDL_RenderClear(renderer);
    } //    ! preRender()


    void Game::render() {
        SDL_Rect rect{ 250, 700, 128, 128 };
        SDL_RenderCopy(renderer, playerTex, NULL, &rect);
        

    } //    ! render()


    void Game::postRender() {
        SDL_RenderPresent(renderer);
    } //    ! postRender()


    void Game::events() {
        SDL_PollEvent(&event);

        switch (event.type) {
            case SDL_QUIT:
                quit();
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    quit();
                    break;
                }
        }
    } //    ! events()


    float Game::clamp(float value, float min, float max) {
        if (value < min) {
            return min;
        }

        else if (value > max) {
            return max;
        }
        
        return value;
    } //    ! clamp()

} // 		 !fr0sty
