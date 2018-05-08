//
// Created by thekatze on 07/02/18.
//

#include "IOManager.h"
#include "Logger.h"
#include <fstream>

/**
 * Reads a file as binary data (unsigned char) into a buffer
 * @param filePath The filepath of the file to read
 * @param buffer The buffer to read into
 * @return Returns a success code: false if the file has not been found
 */
bool IOManager::readFileToBuffer(std::string filePath, std::vector<unsigned char> &buffer) {
    //Read binary
    std::ifstream file(filePath, std::ios::binary);

    if (file.fail()) {
        perror(filePath.c_str());
        Logger::warning("Didn't find file " + filePath);
        return false;
    }

    //seek to the end
    file.seekg(0, std::ios::end);

    //get filesize
    int fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    //Ignore fileheader, might not matter according to ben
    fileSize -= file.tellg();

    buffer.resize(fileSize);

    //Casts dont really matter since its binary data
    file.read((char *) &(buffer[0]), fileSize);

    file.close();

    return true;
}
