//
// Created by thekatze on 07/02/18.
//

#include "ImageLoader.h"
#include "../Util/PicoPNG.h"
#include "../Util/IOManager.h"
#include "../Util/Logger.h"

/**
 * Loads a PNG file and creates a 2 dimensional OpenGL texture.
 * @param filePath The relative path to the PNG file.
 * @return Returns a GLTexture struct consisting of the id, width and height.
 */
GLTexture ImageLoader::loadPNG(std::string filePath) {
    //Optimization potential: don't create it on the stack (new GLTexture and return pointer)
    GLTexture texture = {};

    std::vector<unsigned char> inImage;
    std::vector<unsigned char> outImage;

    unsigned long width, height;

    if (!IOManager::readFileToBuffer(filePath, inImage)) {
        Logger::warning("Failed to load PNG file to buffer!");
        return texture;
    }


    int errorCode = decodePNG(outImage, width, height, &(inImage[0]), inImage.size());

    if (errorCode != 0) {
        Logger::warning("DecodePNG failed with error code " + errorCode);
    }

    glGenTextures(1, &(texture.id));

    glBindTexture(GL_TEXTURE_2D, texture.id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(outImage[0]));

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //TODO: Add selection of nearest <-> linear
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);

    texture.width = width;
    texture.height = height;


    return texture;
}
