//
// Created by thekatze on 8/05/18.
//

#include "gtest/gtest.h"
#include "GameEnvironment.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    ::testing::AddGlobalTestEnvironment(new GameEnvironment());

    return RUN_ALL_TESTS();
}