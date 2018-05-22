//
// Created by thekatze on 17/05/18.
//

#include <GL/glew.h>
#include <SDL.h>
#include "Window.h"
#include "Util/Logger.h"
#include "Util/Constants.h"

Window::Window() {
    this->initialize();
}


/**
 * Changes the window title
 * @param title The new window title
 */

void Window::setTitle(char* title) {
    SDL_SetWindowTitle(window, title);
}


void Window::initialize() {
    Logger::info("Initializing SDL");

    //Initialize Graphics
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        Logger::error("Initializing SDL_VIDEO failed.");
        Logger::error(SDL_GetError());

        exit(Constants::STATUS_FAILED);
    }

    //Create Window

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

    // Initialize OGL

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

Window::~Window() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

