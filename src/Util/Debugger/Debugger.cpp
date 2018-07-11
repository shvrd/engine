//
// Created by thekatze on 6/05/18.
//

#include "Debugger.h"

#include <boost/predef.h>

#if BOOST_OS_WINDOWS

#include <windows.h>

#elif BOOST_OS_LINUX



#elif BOOST_OS_MACOS



#endif

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

// https://stackoverflow.com/questions/63166/how-to-determine-cpu-and-memory-consumption-from-inside-a-process

void Debugger::logRAM() {
#if BOOST_OS_WINDOWS

#elif BOOST_OS_LINUX

#elif BOOST_OS_MACOS

#endif
}
