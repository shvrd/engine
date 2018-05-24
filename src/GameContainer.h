//
// Created by thekatze on 31/01/18.
//

#ifndef SDLOGL_GAMECONTAINER_H
#define SDLOGL_GAMECONTAINER_H

#include <vector>
#include "Window.h"
#include "Input.h"
#include "Graphics/Sprite.h"
#include "Graphics/GLSLProgram.h"
#include "Graphics/GLTexture.h"
#include "GameState.h"

/**
 * The managing class for the engine. This class is responsible for the initialization and the gameloop.
 */
class GameContainer {
    Window* window;

    GameState *currentGameState;

    Graphics *graphics;
    Input *input;

    void initializeSystems();

    void initializeShaders();

    void initializeSound();

    void calculateFPS();

    void gameLoop();

    void update();

    void render();

    void cleanUp();

    float time;
    float timeScale;

    float fps;
    float maxFPS;
    float frameTime;

    std::vector<Sprite *> sprites;

    GLSLProgram colorProgram;

public:

    explicit GameContainer(GameState *currentGameState);

    ~GameContainer();

    const void enterGameState(GameState *newGameState);

    const void setWindowTitle(std::string title);
};

#endif //SDLOGL_GAMECONTAINER_H
