//
// Created by thekatze on 04/04/18.
//

#ifndef SDLOGL_GRAPHICS_H
#define SDLOGL_GRAPHICS_H

#include "Shader.h"
#include "GLTexture.h"
#include "Sprite.h"
#include "GLSLProgram.h"

/**
 * The Graphics wrapper used for drawing objects. This is a high level abstraction of OpenGL.
 */
class Graphics {

    GLSLProgram *currentGLSLProgram;
    GLTexture currentTexture;

public:

    Graphics();

    ~Graphics();

    void bindShader(Shader *shader);

    void startSpriteBatch(Sprite *glTexture);


    GLTexture getCurrentSpriteBatch() { return currentTexture; };
};


#endif //SDLOGL_GRAPHICS_H