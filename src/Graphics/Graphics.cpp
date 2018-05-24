//
// Created by thekatze on 04/04/18.
//

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
    this->currentGLSLProgram = shader->getGLSLProgram();
    this->currentGLSLProgram->bind();

    //Bind uniform (shader)


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

Graphics::Graphics() {
    Logger::info("Initializing Graphics System");
}

Graphics::~Graphics() {
    Logger::info("Shutting down Graphics System");
}

void Graphics::drawSprite(Sprite *sprite) {
    if (currentTexture.equals(sprite->getGLTexture())) {
        this->startSpriteBatch(sprite);
    }

    glBindTexture(GL_TEXTURE_2D, sprite->getGLTexture().id);

    sprite->render();
}
