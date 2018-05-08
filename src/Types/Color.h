//
// Created by thekatze on 6/05/18.
//

#ifndef SDLOGL_COLOR_H
#define SDLOGL_COLOR_H


#include <GL/glew.h>

class Color {
public:
    GLubyte r, g, b, a;

    void set(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }
};


#endif //SDLOGL_COLOR_H
