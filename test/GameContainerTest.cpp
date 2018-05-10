//
// Created by thekatze on 8/05/18.
//

#include "gtest/gtest.h"
#include "TestingGameState.h"

TEST(GameContainerTest, TestInitialGameState) {
    auto *tgs = new TestingGameState();

    new GameContainer(tgs);

    EXPECT_EQ(tgs->entered, true) << "Entered Gamestate";
    EXPECT_EQ(tgs->updated, true) << "Updated Gamestate";
    EXPECT_EQ(tgs->rendered, true) << "Rendered Gamestate";
    EXPECT_EQ(tgs->left, true) << "Left Gamestate";

}
