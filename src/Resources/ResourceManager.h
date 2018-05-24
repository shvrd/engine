//
// Created by thekatze on 18/03/18.
//

#ifndef SHVRDENGINE_SRC_RESOURCEMANAGER_H
#define SHVRDENGINE_SRC_RESOURCEMANAGER_H

#include "TextureCache.h"
#include "string"

/**
 * This is the singleton for resource managing. It can hold various sub-managers for graphics, sound and shaders.
 */
class ResourceManager {
    //TODO: Add an arbitrary amount of caches and make caches selectable
    TextureCache textureCache;

    ResourceManager();

    ~ResourceManager();

public:
    static ResourceManager *getInstance();

    GLTexture getTexture(const std::string &filePath);

    GLuint boundTexture;
};


#endif //SHVRDENGINE_SRC_RESOURCEMANAGER_H
