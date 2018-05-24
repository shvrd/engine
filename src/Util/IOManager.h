//
// Created by thekatze on 07/02/18.
//

#ifndef SHVRDENGINE_SRC_IOMANAGER_H
#define SHVRDENGINE_SRC_IOMANAGER_H

#include <vector>
#include <string>

//Make it a singleton?
class IOManager {
public:
    static bool readFileToBuffer(std::string filePath, std::vector<unsigned char> &buffer);
};


#endif //SHVRDENGINE_SRC_IOMANAGER_H
