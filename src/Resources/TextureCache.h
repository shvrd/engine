//
// Created by thekatze on 18/03/18.
//

#ifndef SDLOGL_TEXTURECACHE_H
#define SDLOGL_TEXTURECACHE_H

#include <map>
#include "../Graphics/GLTexture.h"

/**
 * The texturecache saves loaded images in a map for fast access.
 */
class TextureCache {
    std::map<std::string, GLTexture> textureMap;

public:
    GLTexture getTexture(const std::string &filePath);
    //TODO: Add freeing of resources
};


#endif //SDLOGL_TEXTURECACHE_H
