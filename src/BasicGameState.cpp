//
// Created by thekatze on 21/03/18.
//

#include <iostream>
#include "BasicGameState.h"

#include "Util/Logger.h"
#include "Util/Debugger/Debugger.h"
#include "GameContainer.h"

Debugger *debugger;

Shader *basicShader;

Sprite *testSprite;

void BasicGameState::onEnter() {
    debugger = Debugger::getInstance();

    Logger::info("Entered Basic Gamestate");

    testSprite = new Sprite(0.0f, 0.0f, 400.0f, 400.0f, "../../Assets/devTile.png");

    basicShader = Shader::getDefaultShader();
}

void BasicGameState::onLeave() {
    Logger::info("Left Basic Gamestate");
}

void BasicGameState::update(const int &delta, Input *input, GameContainer *gameContainer) {
    // debugger->logRAM();
}

void BasicGameState::render(Graphics *graphics) {
    graphics->bindShader(basicShader);

    graphics->getCamera()->translate({-0.f, 0.f});
    graphics->getCamera()->scale(1.00001f);

    graphics->startSpriteBatch(testSprite);
    graphics->drawSprite(testSprite);
}