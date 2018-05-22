//
// Created by thekatze on 8/05/18.
//

#include "gtest/gtest.h"
#include "TestingGameState.h"
#include "GameContainer.h"

class GameContainerTest : public ::testing::Test {
protected:
    TestingGameState* tgs;

    virtual void SetUp() {
        tgs = new TestingGameState();
        new GameContainer(tgs);
    }

    virtual void TearDown() {

    }
};

TEST_F(GameContainerTest, EnteredGamestateTest) {
    ASSERT_EQ(tgs->entered, true) << "Entered Gamestate";
}

TEST_F(GameContainerTest, UpdatedGamestateTest) {
    ASSERT_EQ(tgs->updated, true) << "Updated Gamestate";
}

TEST_F(GameContainerTest, RenderedGamestateTest) {
    ASSERT_EQ(tgs->rendered, true) << "Rendered Gamestate";
}

TEST_F(GameContainerTest, LeftGamestateTest) {
    ASSERT_EQ(tgs->left, true) << "Left Gamestate";
}


/*
TEST(GameContainerTest, TestInitialGameState) {
    auto *tgs = new TestingGameState();

    new GameContainer(tgs);

    EXPECT_EQ(tgs->entered, true) << "Entered Gamestate";
    EXPECT_EQ(tgs->updated, true) << "Updated Gamestate";
    EXPECT_EQ(tgs->rendered, true) << "Rendered Gamestate";
    EXPECT_EQ(tgs->left, true) << "Left Gamestate";
}
*/