//
// Created by thekatze on 31/01/18.
//

#include <SDL.h>
#include "GameContainer.h"

#include "Util/Logger.h"

/**
 * Calls the update function of the current gamestate
 * and calculates the time passed since the last frame
 */

void GameContainer::update() {
    input->update();

    //TODO: Calculate delta
    currentGameState->update(0, input, this);
}

/**
 * Calls the render function of the current gamestate,
 * while managing the clearing of the screen and swapping the framebuffers
 */

void GameContainer::render() {
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    currentGameState->render(graphics);

    glBindTexture(GL_TEXTURE_2D, 0);
    SDL_GL_SwapWindow(window->getWindow());
}

//TODO: Separate this function to something like: gamecontainer.init(), gamecontainer.setwindowsize(), gamecontainer.launch()

/**
 * Handles the initialization of the subsystems (OpenGL, SDL), creates necessary objects and launches a set gamestate.
 * @param currentGameState The gamestate to launch the game into.
 */

GameContainer::GameContainer(GameState *currentGameState)
        : time(0.0f), timeScale(0.01f), maxFPS(60.0f), currentGameState(currentGameState) {
    Logger::initialize("log.txt", true);

    initializeSystems();

    graphics = new Graphics();
    input = new Input();

    currentGameState->onEnter();

    do {
        gameLoop();
    } while (!input->closeRequested());

    Logger::info("Close signal received");

    currentGameState->onLeave();

    Logger::info("Left gameloop");

    this->cleanUp();
}

GameContainer::~GameContainer() {
    this->cleanUp();
}

/**
 * The gameloop calls the rendering and update functions. It also limits the frames per second to a defined amount.
 */

void GameContainer::gameLoop() {
    //Used for frametime measuring
    float startTicks = SDL_GetTicks();

    update();
    time += timeScale;
    render();

    calculateFPS();

    //print only once every second
    static int frameCounter = 0;
    frameCounter++;
    if (frameCounter == 60) {
        // Logger::info(std::to_string(fps));
        frameCounter = 0;
    }

    //Limit FPS to max FPS
    float frameTicks = SDL_GetTicks() - startTicks;
    if (1000.0f / maxFPS > frameTicks) {
        SDL_Delay(1000.0f / maxFPS - frameTicks);
    }
}

/**
 * Cleaning up by quitting the subsystems
 */

void GameContainer::cleanUp() {
    Logger::info("Shutting down SDL systems");

    delete window;
    window = nullptr;

    Logger::info("Exiting engine");

    Logger::close();
}

/**
 * Helper function to calculate the mean fps over a defined amount of frames.
 */

void GameContainer::calculateFPS() {
    static const int NUM_SAMPLES = 50;
    // Like a global var just accessible in this function
    static float frameTimes[NUM_SAMPLES];
    static int currentFrame = 0;

    static float previousTicks = SDL_GetTicks();
    static float currentTicks;

    currentTicks = SDL_GetTicks();

    frameTime = currentTicks - previousTicks;

    frameTimes[currentFrame % NUM_SAMPLES] = frameTime;

    previousTicks = currentTicks;

    int count = NUM_SAMPLES;
    currentFrame++;

    if (currentFrame < NUM_SAMPLES) {
        count = currentFrame;
    }

    float frameTimeAverage = 0;
    for (int i = 0; i < count; i++) {
        frameTimeAverage += frameTimes[i];
    }

    frameTimeAverage /= count;

    if (frameTimeAverage > 0) {
        fps = 1000.0f / frameTimeAverage;
    } else {
        fps = 0;
    }
}

/**
 * Tells the engine to enter a new gamestate on the next update cycle.
 * @param newGameState A pointer to the gamestate to enter.
 */

const void GameContainer::enterGameState(GameState *newGameState) {
    currentGameState->onLeave();

    newGameState->onEnter();

    currentGameState = newGameState;
}

/**
 * The wrapper function for all systems that have to be initialized
 */

void GameContainer::initializeSystems() {
    Logger::info("Creating Window");

    this->window = new Window("Engine", 1280, 960);

    initializeShaders();
    initializeSound();
}

void GameContainer::initializeShaders() {
    Logger::info("Initializing Basic Shaders");
    Shader::getDefaultShader();
}

void GameContainer::initializeSound() {
    Logger::info("Initializing Audio");

    // https://www.openal.org/documentation/OpenAL_Programmers_Guide.pdf

//    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0) {
//        Logger::error("Failed Initializing Audio");
//    }
}
