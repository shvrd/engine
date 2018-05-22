//
// Created by thekatze on 6/05/18.
//

#include "Debugger.h"

#include <boost/predef.h>

static Debugger *instance;

Debugger::Debugger() {
#if BOOST_OS_WINDOWS
    Logger::info("Initialized debugger for Windows");
#elif BOOST_OS_LINUX
    Logger::info("Initialized debugger for Linux");
#elif BOOST_OS_MACOS
    Logger::info("Initialized debugger for MacOS");
#else
    Logger::info("The debugger could not detect an os");
#endif
}

Debugger *Debugger::getInstance() {
    if (instance == nullptr) {
        instance = new Debugger();
    }

    return instance;
}

// https://github.com/hyperic/sigar

void Debugger::logRAM() {}
