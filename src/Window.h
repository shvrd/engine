//
// Created by thekatze on 17/05/18.
//

#ifndef SHVRDENGINE_TEST_WINDOW_H
#define SHVRDENGINE_TEST_WINDOW_H

#include <SDL2/SDL_video.h>

class Window {
    SDL_Window *window = nullptr;
    SDL_GLContext context = nullptr;

    void initialize();

public:
    Window();
    ~Window();

    SDL_Window *getWindow() {return window;}
    SDL_GLContext getContext() {return context;}

    void setTitle(char *title);
};

#endif //SHVRDENGINE_TEST_WINDOW_H
