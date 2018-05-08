//
// Created by thekatze on 31/01/18.
//

#ifndef SDLOGL_LOGGER_H
#define SDLOGL_LOGGER_H

#include <string>

class Logger {

public:

    static void initialize(std::string filePath, bool consoleLogging);


    static void error(std::string message);

    static void warning(std::string message);

    static void info(std::string message);

    static void terminate(int errorCode);
};


#endif //SDLOGL_LOGGER_H
