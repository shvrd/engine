//
// Created by thekatze on 21/03/18.
//

#ifndef SDLOGL_GAMESTATE_H
#define SDLOGL_GAMESTATE_H

class GameContainer;

#include "Input.h"
#include "Graphics/Graphics.h"

/**
 * The interface (pure virtual class) for creating gamestates
 * which functions will be called by the gamecontainer.
 */

class GameState {

public:

    GameState() = default;

    ~GameState() = default;

    /**
     * This will be called when entering the gamestate. This should bind the resourcemanager, initialize resources and
     * the gameobjects for this gamestate.
     */
    virtual void onEnter() {
        //Initialize shaders
    };

    /**
     * This will be called when exiting the gamestate, also when exiting the game as it is leaving the gamestate.
     * This should be used to clean up resources and manage saving the game.
     */
    virtual void onLeave() {
        //Free Resources
    };

    /**
     * The function responsible for game logic.
     * @param delta The time passed since the last frame.
     * @param input The input wrapper, for more documentation consult the documentation of the input class
     */
    virtual void update(const int &delta, Input *input, GameContainer *gameContainer) {};

    /**
     * The function responsible for rendering the game objects.
     * @param graphics The graphics wrapper, for more documentation consult the documentation of the graphics class
     */
    virtual void render(Graphics const *graphics) {};
};


#endif //SDLOGL_GAMESTATE_H
