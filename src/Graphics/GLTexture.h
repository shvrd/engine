//
// Created by thekatze on 07/02/18.
//

#ifndef SDLOGL_GLTEXTURE_H
#define SDLOGL_GLTEXTURE_H

#include <GL/glew.h>

/**
 * The struct containing the OpenGL id, width and height for textures loaded onto the graphics card.
 */
struct GLTexture {
    GLuint id;
    int width;
    int height;
};

#endif //SDLOGL_GLTEXTURE_H
