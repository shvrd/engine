//
// Created by thekatze on 17/05/18.
//

#ifndef SHVRDENGINE_SRC_WINDOW_H
#define SHVRDENGINE_SRC_WINDOW_H

#include <SDL2/SDL_video.h>

class Window {
    SDL_Window *window = nullptr;
    SDL_GLContext context = nullptr;

    void initialize(const char *title, int windowWidth, int windowHeight);

public:
    Window(const char *title, int windowWidth, int windowHeight);
    ~Window();

    SDL_Window *getWindow() {return window;}
    SDL_GLContext getContext() {return context;}

    void setTitle(const char *title);
};

#endif //SHVRDENGINE_SRC_WINDOW_H
