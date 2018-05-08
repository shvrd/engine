//
// Created by thekatze on 31/01/18.
//

#ifndef SDLOGL_GAMECONTAINER_H
#define SDLOGL_GAMECONTAINER_H

class GameState;

class Graphics;

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include "Input.h"
#include "Graphics/Sprite.h"
#include "Graphics/GLSLProgram.h"
#include "Graphics/GLTexture.h"
#include "GameState.h"

/**
 * The managing class for the engine. This class is responsible for the initialization and the gameloop.
 */
class GameContainer {

    SDL_Window *window = nullptr;
    SDL_GLContext context = nullptr;

    const std::string assetPath = "../Assets/";

    bool gameShouldClose = false;

    GameState *currentGameState;

    Graphics *graphics;
    Input *input;

    void initializeSystems();

    void initializeSDL();

    void initializeOpenGL();

    void initializeShaders();

    void initializeSound();

    void calculateFPS();

    void gameLoop();

    void update();

    void render();

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

    void enterGameState(GameState *newGameState);

    void setWindowTitle(std::string title);

    void close();

};


#endif //SDLOGL_GAMECONTAINER_H
