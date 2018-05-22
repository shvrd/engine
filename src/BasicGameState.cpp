//
// Created by thekatze on 21/03/18.
//

#include <iostream>
#include "BasicGameState.h"

#include "Util/Logger.h"
#include "Util/Debugger/Debugger.h"
#include "GameContainer.h"

Debugger *debugger;

void BasicGameState::onEnter() {
    debugger = Debugger::getInstance();

    Logger::info("Entered Basic Gamestate");
}

void BasicGameState::onLeave() {
    Logger::info("Left Basic Gamestate");
}

void BasicGameState::update(const int &delta, Input *input, GameContainer *gameContainer) {
    debugger->logRAM();
}

void BasicGameState::render(const Graphics *graphics) {}