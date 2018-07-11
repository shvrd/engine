//
// Created by thekatze on 21/03/18.
//

#include <vector>

#include "BasicGameState.h"

#include "Util/Logger.h"
#include "Util/Debugger/Debugger.h"
#include "GameContainer.h"

Debugger *debugger;

Shader *basicShader;

std::vector<Sprite*> *sprites;

void BasicGameState::onEnter() {
    debugger = Debugger::getInstance();

    Logger::info("Entered Basic Gamestate");

    sprites = new std::vector<Sprite*>;

    for (int y = 0 ; y <= 10; y++) {

        for (int x = 0 ; x <= 20; x++) {
            sprites->push_back(new Sprite(x * 100, y * 100, 100, 100, "../../Assets/devTile.png"));
        }
    }

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

    Vector2 center = {1280/2, 960/2};

    graphics->getCamera()->rotate(.3f);


    graphics->drawSpriteArray(sprites);
}