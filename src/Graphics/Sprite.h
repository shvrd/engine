//
// Created by thekatze on 06/02/18.
//

#ifndef SHVRDENGINE_SRC_SPRITE_H
#define SHVRDENGINE_SRC_SPRITE_H

#include <GL/glew.h>
#include <string>
#include "GLTexture.h"
#include "../Types/Vector2.h"

/**
 * A rectangular sprite consisting of a texture, its position, width and height
 */
class Sprite {
    static const int VERTICES = 6;

    Vector2 location;

    Vector2 dimensions;

    GLTexture texture;

    //This might get me into trouble, but i think its better like this
    GLuint vboID;

    void init(float x, float y, float width, float height, const std::string &texturePath);

public:
    Sprite(float x, float y, float width, float height, std::string texturePath);

    Sprite();

    ~Sprite();

    void render();

    GLTexture getGLTexture() { return this->texture; }
};


#endif //SHVRDENGINE_SRC_SPRITE_H
