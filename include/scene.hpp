#ifndef SCENE_HPP
#define SCENE_HPP

#include <SDL/SDL.h>

namespace fr0sty {
    class Scene {
        private:
            

        public:
            Scene() = default;

            virtual void update() = 0;
            virtual void render(SDL_Renderer *renderer) = 0;

        };	// 		 !Scene
}	// 		 !fr0sty
#endif // 		 !SCENE_HPP