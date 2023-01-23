#include "game.hpp"

int main(int argc, char* args[]) {
    
    fr0sty::Game game;

    game.init();
    game.write("SYSTEMS INITIALIZED!", true);
    game.getClock()->start();
    game.write("CLOCK STARTING!", true);

    while (game.getRunning()) {
        game.events();
        game.update(game.getDT());

        game.setDT(game.getClock()->getTicks());
        game.getClock()->start();


        game.preRender();
        game.render();
        game.postRender();
    }
    
    game.quit();
    game.write("STOPPING SYSTEMS!", true);
    game.write("EXITING PROGRAM!", true);
    
    
    system("pause");
    return 0;
}