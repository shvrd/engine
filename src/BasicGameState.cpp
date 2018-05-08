//
// Created by thekatze on 21/03/18.
//

#include <iostream>
#include "BasicGameState.h"

#include "Util/Logger.h"
#include "Util/Debugger/Debugger.h"

Debugger *debugger;

void BasicGameState::onEnter() {

    debugger = Debugger::getInstance();

    Logger::info("Entered Basic Gamestate");
}

void BasicGameState::onLeave() {
    Logger::info("Left Basic Gamestate");
}

void BasicGameState::update(const int &delta, const Input *input, GameContainer *gameContainer) {
    debugger->logRAM();
}

void BasicGameState::render(const Graphics *graphics) {



    /*
    colorProgram.bind();
    glActiveTexture(GL_TEXTURE0);
    // glBindTexture(GL_TEXTURE_2D, testTexture.id);

    glUniform1i(colorProgram.getUniformLocation("sampler"), 0);

    GLint timeLocation = colorProgram.getUniformLocation("time");

    glUniform1f(timeLocation, time);

    for (Sprite *sprite : sprites) {
        sprite->render();
    }

    colorProgram.unbind();
     */
}