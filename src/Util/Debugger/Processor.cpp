//
// Created by thekatze on 6/05/18.
//

#include "Processor.h"

#include "boost/predef.h"

#if BOOST_OS_WINDOWS
#include <windows.h>
#include <psapi.h>
#elif BOOST_OS_MACOS

#elif BOOST_OS_LINUX

#else

#endif

long Processor::getUsage() {
    long usage = 0;

#if BOOST_OS_WINDOWS

#elif BOOST_OS_MACOS

#elif BOOST_OS_LINUX

#else

#endif

    return usage;
}
