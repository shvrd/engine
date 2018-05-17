//
// Created by thekatze on 09/04/18.
//

#ifndef SDLOGL_INPUT_H
#define SDLOGL_INPUT_H

#include "Types/Vector2.h"

/**
 * Used as a wrapper for SDL_Events. This provides information about the mouse, keyboard and controller.
 * There will be a higher level wrapper for abstract key-bindings which will enable remappable keybindings.
 */

class Input {

    bool isCloseRequested = false;
    bool mouseMoved;

    /**
     * Information about the location and movement of the mouse
     */
    struct Mouse {
        Vector2 position;
        Vector2 delta;
    } mouse;

public:
    Input();

    ~Input();

    void update();

    void const requestClose() {isCloseRequested = true;}
    bool const closeRequested() {return isCloseRequested;}

    struct Window {
        bool shouldClose;

    };

    /**
     * Gets the absolute mouse position from the top-left corner of the screen.
     * @return Returns the current mouse position.
     */
    const Vector2 getMousePosition() const {
        return mouse.position;
    }

    /**
     * Gets the relative mouse motion
     * @return Returns the last mousedelta if the mouse has been moved.
     */
    const Vector2 getMouseDelta() const {
        return (mouseMoved) ? mouse.delta : Vector2{0, 0};
    }


};


#endif //SDLOGL_INPUT_H
