//
// Created by thekatze on 07/02/18.
//

#ifndef SDLOGL_IOMANAGER_H
#define SDLOGL_IOMANAGER_H

#include <vector>
#include <string>

//Make it a singleton?
class IOManager {

public:
    static bool readFileToBuffer(std::string filePath, std::vector<unsigned char> &buffer);
};


#endif //SDLOGL_IOMANAGER_H
