//
// Created by thekatze on 18/03/18.
//

#include "TextureCache.h"
#include "ImageLoader.h"
#include "../Util/Logger.h"

/**
 * Loads a texture from storage into memory and stores its properties. If it already has been loaded before just returns its properties.
 * @param filePath The PNG file to load.
 * @return Returns the GLTexture struct for this texture.
 */
GLTexture TextureCache::getTexture(const std::string &filePath) {

    //see if texture is in the map
    // std::map<std::string, GLTexture>::iterator -> auto
    auto mapIterator = textureMap.find(filePath);

    if (mapIterator == textureMap.end()) {
        //Texture is not in the map
        GLTexture newTexture = ImageLoader::loadPNG(filePath);

        textureMap.insert(std::make_pair(filePath, newTexture));

        Logger::info("Loaded and cached Texture " + filePath);

        return newTexture;
    }

    Logger::info("Loaded Texture " + filePath + " from cache");

    return mapIterator->second;
}
