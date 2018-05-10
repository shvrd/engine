//
// Created by thekatze on 10/05/18.
//

#ifndef SHVRDENGINE_TEST_GAMEENVIRONMENT_H
#define SHVRDENGINE_TEST_GAMEENVIRONMENT_H


#include <googletest/include/gtest/gtest.h>
#include <GameContainer.h>
#include "TestingGameState.h"

class GameEnvironment : public ::testing::Environment {
public:
    // Override this to define how to set up the environment.
    void SetUp() override;
    // Override this to define how to tear down the environment.
    void TearDown() override;
};


#endif //SHVRDENGINE_TEST_GAMEENVIRONMENT_H
