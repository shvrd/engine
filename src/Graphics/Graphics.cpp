//
// Created by thekatze on 04/04/18.
//

#include <vector>
#include <algorithm>
#include "Graphics.h"
#include "../Util/Logger.h"

/**
 * Sets the next object to be drawn. Improves performance if used correctly.
 * @param sprite The next sprite object to be drawn.
 */
void Graphics::startSpriteBatch(Sprite *sprite) {
    glActiveTexture(GL_TEXTURE0);

    glUniform1i(currentGLSLProgram->getUniformLocation("image"), 0);
    glBindTexture(GL_TEXTURE_2D, sprite->getGLTexture().id);

    currentTexture = sprite->getGLTexture();
}

/**
 * Binds a shader to use for the next batch of sprites that are drawn.
 * @param shader The shader to be bound.
 */
void Graphics::bindShader(Shader *shader) {
    if (this->currentGLSLProgram != nullptr)
        this->currentGLSLProgram->unbind();

    this->currentGLSLProgram = shader->getGLSLProgram();
    this->currentGLSLProgram->bind();

    //Add camera
    glUniformMatrix4fv(currentGLSLProgram->getUniformLocation("projection"),
                       1,
                       GL_FALSE,
                       &(camera->getCameraMatrix()[0][0]));
}
/*
colorProgram.bind();


GLint timeLocation = colorProgram.getUniformLocation("time");

glUniform1f(timeLocation, time);

for (Sprite *sprite : sprites) {
    sprite->render();
}

colorProgram.unbind();
 */

/**
 * The Constructor for the graphics subsystem. Initializes the camera and sets the currentGLSLProgram to nullptr.
 */

Graphics::Graphics() : currentTexture({0, 0, 0}), camera(new Camera2D(1280, 960)), currentGLSLProgram(nullptr) {
    Logger::info("Initializing Graphics System");
}

/**
 * Cleans up used resources.
 */
Graphics::~Graphics() {
    Logger::info("Shutting down Graphics System");
}

/**
 * Draws a sprite at its location.
 * @param sprite Pointer to the sprite to be drawn.
 */
void Graphics::drawSprite(Sprite *sprite) {
    if (!currentTexture.equals(sprite->getGLTexture())) {
        this->startSpriteBatch(sprite);
    }

    sprite->render();
}

/**
 * Draws a sprite array of the same type of sprites, while only setting the sprite texture once
 * @param spriteArray The vector of sprites to be drawn.
 */
void Graphics::drawSpriteArray(std::vector<Sprite*> *spriteArray) {
    if (!currentTexture.equals(spriteArray->front()->getGLTexture())) {
        Logger::info("Starting Spritebatch");
        this->startSpriteBatch(spriteArray->front());
    }

    for (long i = 0; i < spriteArray->size(); i++) {
        spriteArray->at(i)->render();
    }
}

