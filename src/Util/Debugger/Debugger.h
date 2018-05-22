//
// Created by thekatze on 6/05/18.
//

#ifndef SDLOGL_DEBUGGER_H
#define SDLOGL_DEBUGGER_H

#include "../Logger.h"

class Debugger {
    Debugger();

public:
    static Debugger *getInstance();

    void logRAM();
};


#endif //SDLOGL_DEBUGGER_H
