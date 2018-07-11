//
// Created by thekatze on 16/06/18.
//

#ifndef SHVRDENGINE_SPRITEBATCH_H
#define SHVRDENGINE_SPRITEBATCH_H


#include <GL/glew.h>
#include "Vertex.h"

struct Glyph {
    GLuint texture;
    float depth;

    Vertex topLeft;
    Vertex bottomLeft;
    Vertex topRight;
    Vertex bottomRight;
};

class SpriteBatch {

    GLuint vboID;
    GLuint vaoID;
public:
    SpriteBatch();
    ~SpriteBatch();

    void begin();
    void end();

    void draw();

    void renderBatch();

};


#endif //SHVRDENGINE_SPRITEBATCH_H
