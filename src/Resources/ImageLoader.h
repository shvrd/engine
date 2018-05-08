//
// Created by thekatze on 07/02/18.
//

#ifndef SDLOGL_IMAGELOADER_H
#define SDLOGL_IMAGELOADER_H

#include <string>
#include "../Graphics/GLTexture.h"

/**
 * Loads images onto the graphics card and stores the GL Texture ID
 */
class ImageLoader {


public:
    static GLTexture loadPNG(std::string filePath);
};


#endif //SDLOGL_IMAGELOADER_H
