//
// Created by thekatze on 07/02/18.
//

#ifndef SHVRDENGINE_SRC_IMAGELOADER_H
#define SHVRDENGINE_SRC_IMAGELOADER_H

#include <string>
#include "../Graphics/GLTexture.h"

/**
 * Loads images onto the graphics card and stores the GL Texture ID
 */
class ImageLoader {
public:
    static GLTexture loadPNG(std::string filePath);
};


#endif //SHVRDENGINE_SRC_IMAGELOADER_H
