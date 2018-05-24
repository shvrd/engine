//
// Created by thekatze on 21/03/18.
//

#ifndef SHVRDENGINE_SRC_BASICGAMESTATE_H
#define SHVRDENGINE_SRC_BASICGAMESTATE_H

#include "GameState.h"

/**
 * My testing gamestate
 */

class BasicGameState : public GameState {
    void onEnter() override;

    void onLeave() override;

    void update(const int &delta, Input *input, GameContainer *gameContainer) override;

    void render(Graphics *graphics) override;
};


#endif //SHVRDENGINE_SRC_BASICGAMESTATE_H
