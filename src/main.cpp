//
// Created by thekatze on 8/05/18.
//

#include "GameContainer.h"
#include "BasicGameState.h"

int main() {

    std::string windowTitle = "Engine";

    new GameContainer(new BasicGameState());

    return 0;
}