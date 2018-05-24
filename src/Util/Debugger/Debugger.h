//
// Created by thekatze on 6/05/18.
//

#ifndef SHVRDENGINE_SRC_DEBUGGER_H
#define SHVRDENGINE_SRC_DEBUGGER_H

#include "../Logger.h"

class Debugger {
    Debugger();

public:
    static Debugger *getInstance();

    void logRAM();
};


#endif //SHVRDENGINE_SRC_DEBUGGER_H
