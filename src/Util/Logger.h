//
// Created by thekatze on 31/01/18.
//

#ifndef SHVRDENGINE_SRC_LOGGER_H
#define SHVRDENGINE_SRC_LOGGER_H

#include <string>

class Logger {
public:
    static void initialize(std::string filePath, bool consoleLogging);


    static void error(std::string message);

    static void warning(std::string message);

    static void info(std::string message);

    static void terminate(int errorCode);

    static void close();
};


#endif //SHVRDENGINE_SRC_LOGGER_H
