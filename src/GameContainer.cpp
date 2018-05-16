//
// Created by thekatze on 31/01/18.
//

#include "GameContainer.h"

#include "Util/Logger.h"
#include "Util/Constants.h"
#include "Resources/ResourceManager.h"

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
    SDL_GL_SwapWindow(window);
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

    // sprites.push_back(new Sprite(-1, -1, 1, 1, assetPath + "devTile.png"));
    // sprites.push_back(new Sprite(0, 0, 1, 1, assetPath + "devTile.png"));

    graphics = new Graphics();
    input = new Input();

    currentGameState->onEnter();

    //Gameloop
    //TODO: Threaded update and render?

    do {
        gameLoop();
    } while (!input->closeRequested());

    Logger::info("Close signal received");

    currentGameState->onLeave();

    Logger::info("Left gameloop");
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

GameContainer::~GameContainer() {
    Logger::info("Shutting down SDL systems");

    SDL_DestroyWindow(window);
    SDL_Quit();

    Logger::info("Exiting engine");
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
 * Changes the window title
 * @param title The new window title
 */

const void GameContainer::setWindowTitle(std::string title) {
    SDL_SetWindowTitle(window, title.c_str());
}


/**
 * The wrapper function for all systems that have to be initialized
 */

void GameContainer::initializeSystems() {
    initializeSDL();
    initializeOpenGL();
    initializeShaders();
    initializeSound();
}

void GameContainer::initializeSDL() {
    Logger::info("Initializing SDL");

    //Initialize Graphics
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        Logger::error("Initializing SDL_VIDEO failed.");
        Logger::error(SDL_GetError());

        exit(Constants::STATUS_FAILED);
    }

    //Create Window

    Logger::info("Creating Window");

    //Enable Doublebuffering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetSwapInterval(1); //VSync on

    window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED_DISPLAY(0), SDL_WINDOWPOS_CENTERED_DISPLAY(0), 1280, 960,
                              SDL_WINDOW_OPENGL);

    if (window == nullptr) {
        Logger::error("Initializing Window failed.");
        Logger::error(SDL_GetError());

        exit(Constants::STATUS_FAILED);
    }

    //Create Context

    Logger::info("Creating SDL_GL Context");

    context = SDL_GL_CreateContext(window);

    if (context == nullptr) {
        Logger::error("Initializing OpenGL Context failed.");
        Logger::error(SDL_GetError());

        exit(Constants::STATUS_FAILED);
    }
}

void GameContainer::initializeOpenGL() {
    Logger::info("Initializing GLEW");

    int glewError = glewInit();

    if (glewError != GLEW_OK) {
        Logger::error("Initializing GLEW failed");
        Logger::error(std::to_string(glewError).append(" - GLEW Error Code."));
        exit(Constants::STATUS_FAILED);
    }

    Logger::info("Initializing OpenGL");

    const GLubyte *glVersion = glGetString(GL_VERSION);

    std::string glVersionString = reinterpret_cast<char const *>(glVersion);

    Logger::info("OpenGL Version: " + glVersionString);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    GLenum glError = glGetError();
    if (glError != GL_NO_ERROR) {
        Logger::error("Initializing OpenGL Failed");
        Logger::error(std::to_string(glError).append(" - OpenGL Error Code."));

        exit(Constants::STATUS_FAILED);
    }
}

void GameContainer::initializeShaders() {
    Logger::info("Initializing Shaders");

    colorProgram.compileShaders("../../Assets/Shaders/colorShading.vert", "../../Assets/Shaders/colorShading.frag");
    colorProgram.addAttribute("vertexPostion");
    colorProgram.addAttribute("vertexColor");
    colorProgram.addAttribute("vertexUV");
    colorProgram.linkShaders();
}

#include <AL/al.h>
#include <alc.h>

void GameContainer::initializeSound() {
    Logger::info("Initializing Audio");

    // https://www.openal.org/documentation/OpenAL_Programmers_Guide.pdf

//    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0) {
//        Logger::error("Failed Initializing Audio");
//    }
}
