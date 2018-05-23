//
// Created by thekatze on 31/01/18.
//

#include "Logger.h"
#include "spdlog/spdlog.h"

std::shared_ptr<spdlog::logger> logger;
bool console;
static std::string loggerName = "Engine";

/**
 * Initializes the logger and prints a first logging message
 * @param filePath The relative logging-file path from the executable for the log textfile
 * @param consoleLogging Enables console logging if true
 */
void Logger::initialize(std::string filePath, bool consoleLogging) {
    logger = spdlog::basic_logger_mt(loggerName, filePath);
    console = consoleLogging;

    Logger::info("Logger initialized");
}

/**
 * Prints an error message to the Engine-Logger
 * @param message The message to print
 */
void Logger::error(std::string message) {
    logger->error(message);

    if (console) {
        printf((message.append("\n").c_str()));
    }
}

/**
 * Prints a warning message to the Engine-Logger
 * @param message The message to print
 */
void Logger::warning(std::string message) {
    logger->warn(message);

    if (console) {
        printf((message.append("\n").c_str()));
    }
}

/**
 * Prints an info message to the Engine-Logger
 * @param message The message to print
 */
void Logger::info(std::string message) {
    logger->info(message);

    if (console) {
        printf((message.append("\n").c_str()));
    }
}

/**
 * NOT RECOMMENDED; SHOULD ONLY BE USED IN ABSOLUTE WORST CASE SCENARIOS
 * Terminates the program instantly without any cleaning up or anything.
 * @param errorCode
 */
void Logger::terminate(int errorCode) {
    logger->critical("Terminating Program with exit code " + std::to_string(errorCode));

    exit(errorCode);
}

void Logger::close() {
    Logger::info("Closing Engine Logger");

    spdlog::drop(loggerName);
}
