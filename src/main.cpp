#include <iostream>

#include "game.hpp"

int main(int argc, char* args[]) {
    
    fr0sty::Game game;

    game.init();

    while (game.getRunning()) {
        game.events();
        game.update();
        game.preRender();
        game.render();
        game.postRender();
    }
    
    

    return 0;
}