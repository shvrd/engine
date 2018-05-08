//
// Created by thekatze on 06/02/18.
//

#include "Sprite.h"
#include "Vertex.h"
#include "../Resources/ResourceManager.h"

Sprite::Sprite(float x, float y, float width, float height, std::string texturePath) : vboID(0) {
    this->init(x, y, width, height, texturePath);
}

Sprite::Sprite() = default;

Sprite::~Sprite() {
    if (vboID != 0) {
        glDeleteBuffers(1, &vboID);
    }
}

/**
 * Draws this sprite at its current location
 */
void Sprite::render() {

    glBindTexture(GL_TEXTURE_2D, texture.id);

    glBindBuffer(GL_ARRAY_BUFFER, vboID);

    glEnableVertexAttribArray(0);

    //Position Attribute Pointer
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) offsetof(Vertex, position));

    //Color Attribute Pointer

    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void *) offsetof(Vertex, color));

    //UV Attribute Pointer
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) offsetof(Vertex, uv));

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/**
 * Initializes the sprite with its location, dimensions and texture path
 */
void Sprite::init(float x, float y, float width, float height, const std::string &texturePath) {
    this->location.set(x, y);
    this->dimensions.set(width, height);

    this->texture = ResourceManager::getInstance()->getTexture(texturePath);


    /* Code in tutorial, i set vboid in header

    vboID = 0; //In Constructor

     //In Sprite::init();
    if (vboID == 0) {
        glGenBuffers(1, &vboID);
    }

    */

    glGenBuffers(1, &vboID);

    //Initialize Square
    // two triangles so 6 vertices
    Vertex vertexData[VERTICES];

    vertexData[0].position.set(x + width, y + height);
    vertexData[0].uv.set(1.0f, 1.0f);

    vertexData[1].position.set(x, y + height);
    vertexData[1].uv.set(0.0f, 1.0f);

    vertexData[2].position.set(x, y);
    vertexData[2].uv.set(0.0f, 0.0f);

    //Second Triangle

    vertexData[3].position.set(x, y);
    vertexData[3].uv.set(0.0f, 0.0f);

    vertexData[4].position.set(x + width, y);
    vertexData[4].uv.set(1.0f, 0.0f);

    vertexData[5].position.set(x + width, y + height);
    vertexData[5].uv.set(1.0f, 1.0f);

    for (int i = 0; i < VERTICES; i++) {
        vertexData[i].color.set(255, 255, 255, 255);
    }

    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
