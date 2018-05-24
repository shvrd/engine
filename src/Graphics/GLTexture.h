//
// Created by thekatze on 07/02/18.
//

#ifndef SHVRDENGINE_SRC_GLTEXTURE_H
#define SHVRDENGINE_SRC_GLTEXTURE_H

#include <GL/glew.h>

/**
 * The struct containing the OpenGL id, width and height for textures loaded onto the graphics card.
 */
struct GLTexture {
    GLuint id;
    int width;
    int height;

    bool equals(GLTexture glTexture) {
        return (this->id == glTexture.id);
    }
};

#endif //SHVRDENGINE_SRC_GLTEXTURE_H
