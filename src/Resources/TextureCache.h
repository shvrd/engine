//
// Created by thekatze on 18/03/18.
//

#ifndef SHVRDENGINE_SRC_TEXTURECACHE_H
#define SHVRDENGINE_SRC_TEXTURECACHE_H

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


#endif //SHVRDENGINE_SRC_TEXTURECACHE_H
