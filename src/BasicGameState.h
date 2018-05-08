//
// Created by thekatze on 21/03/18.
//

#ifndef SDLOGL_BASICGAMESTATE_H
#define SDLOGL_BASICGAMESTATE_H

#include "GameState.h"

/**
 * My testing gamestate
 */

class BasicGameState : public GameState {
    void onEnter() override;

    void onLeave() override;

    void update(const int &delta, const Input *input) override;

    void render(const Graphics *graphics) override;
};


#endif //SDLOGL_BASICGAMESTATE_H
