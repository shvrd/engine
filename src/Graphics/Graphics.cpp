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

    glUniform1i(currentGLSLProgram->getUniformLocation("sampler"), 0);

    glBindTexture(GL_TEXTURE_2D, sprite->getGLTexture().id);
}

/**
 * Binds a shader to use for the next batch of sprites that are drawn.
 * @param shader The shader to be bound.
 */
void Graphics::bindShader(Shader *shader) {
    this->currentGLSLProgram = shader->getGLSLProgram();

    //Enable Vertex Attrib Arrays (handled by shader object)

    //Bind uniforms (shader)

    //Do shader stuff
}

Graphics::Graphics() {
    Logger::info("Initializing Graphics System");
}

Graphics::~Graphics() {
    Logger::info("Shutting down Graphics System");
}
