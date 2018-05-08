//
// Created by thekatze on 09/04/18.
//

#include <SDL_events.h>
#include "Input.h"
#include "Util/Logger.h"

Input::Input() {

    Logger::info("Initializing Input Wrapper");
    // SDL_SetRelativeMouseMode(SDL_TRUE);
}

Input::~Input() {
    Logger::info("Shutting down Input Wrapper");
}


void Input::update(GameContainer *gameContainer) {
    SDL_Event event = SDL_Event();

    mouseMoved = false;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                gameContainer->close();
                break;
            case SDL_KEYDOWN:
                // event.key.keysym.sym;
                // SDLK_k

                break;
            case SDL_MOUSEMOTION:
                mouse.position.x = event.motion.x;
                mouse.position.y = event.motion.y;

                mouse.delta.x = event.motion.xrel;
                mouse.delta.y = event.motion.xrel;

                mouseMoved = true;

                break;

            default:
                break;
        }
    }
}
