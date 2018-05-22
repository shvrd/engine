//
// Created by thekatze on 18/03/18.
//

#include "ResourceManager.h"


static ResourceManager *resourceManager;

ResourceManager::ResourceManager() : boundTexture(0) {}

ResourceManager::~ResourceManager() = default;


/**
 * Gets a texture from the selected texturemanager
 * @param filePath The texture to load
 * @return The GLTexture struct for the requested texture
 */
GLTexture ResourceManager::getTexture(const std::string &filePath) {
    return textureCache.getTexture(filePath);
}

ResourceManager *ResourceManager::getInstance() {
    if (resourceManager == nullptr) {
        resourceManager = new ResourceManager();
    }

    return resourceManager;
}


