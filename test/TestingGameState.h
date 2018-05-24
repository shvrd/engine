//
// Created by thekatze on 8/05/18.
//

#ifndef SHVRDENGINE_TEST_TESTINGGAMESTATE_H
#define SHVRDENGINE_TEST_TESTINGGAMESTATE_H

#include <GameState.h>
#include <Util/Logger.h>

class TestingGameState : public GameState {
public:
    bool entered, updated, rendered, left;

    void onEnter() override {
        //Initialize shaders
        Logger::info("Entered TestingGameState");
        entered = true;
    };

    void onLeave() override {
        //Free Resources
        left = true;
    };

    void update(const int &delta, Input *input, GameContainer *gameContainer) override {
        Logger::info("Updated TestingGameState");
        updated = true;
        input->requestClose();
    };

    void render(Graphics *graphics) override {
        rendered = true;
        Logger::info("Rendered TestingGameState");
    };
};

#endif //SHVRDENGINE_TEST_TESTINGGAMESTATE_H
