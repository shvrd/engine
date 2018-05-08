set(engine_base_src GameContainer.h GameContainer.cpp GameState.h BasicGameState.h BasicGameState.cpp Input.h Input.cpp Audio/Music.h Audio/Music.cpp Audio/Sound.h Audio/Sound.cpp Graphics/GLSLProgram.h Graphics/GLSLProgram.cpp Graphics/GLTexture.h Graphics/Graphics.h Graphics/Graphics.cpp Graphics/Shader.h Graphics/Shader.cpp Graphics/Sprite.h Graphics/Sprite.cpp Graphics/Vertex.h Localization/LanguageCodes.h Localization/Localizer.h Localization/Localizer.cpp Resources/ResourceManager.h Resources/ResourceManager.cpp Resources/TextureCache.h Resources/TextureCache.cpp Resources/ImageLoader.h Resources/ImageLoader.h Resources/ImageLoader.cpp Types/Color.h Types/Color.cpp Types/Vector2.h Types/Vector2.cpp Util/Debugger/Debugger.h Util/Debugger/Debugger.cpp Util/Debugger/Memory.h Util/Debugger/Memory.cpp Util/Debugger/Processor.h Util/Debugger/Processor.cpp Util/Constants.h Util/IOManager.h Util/IOManager.cpp Util/Logger.h Util/Logger.cpp Util/PicoPNG.h Util/PicoPNG.cpp)


IF(MINGW)
    MESSAGE("Building for Windows using MinGW")
    MESSAGE(${CMAKE_SYSTEM})

    # Add windows specific variable settings here

    MESSAGE("Building for Windows is not supported yet.")

    INCLUDE(FindPkgConfig)
    INCLUDE(FindOpenGL)
    INCLUDE(FindGLEW)
    #INCLUDE(FindPNG)
    INCLUDE(FindBoost)

    PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
    PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
    PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

    PKG_SEARCH_MODULE(GLM REQUIRED glm)

ELSEIF(APPLE)
    MESSAGE("Building for macOS")
    MESSAGE(${CMAKE_SYSTEM})

    # Add mac specific variable settings here
    # To install required packages run: brew install boost-python glm glib glew sdl2 sdl2_image sdl2_mixer spdlog

    INCLUDE(FindPkgConfig)
    INCLUDE(FindOpenGL)
    INCLUDE(FindGLEW)
    #INCLUDE(FindPNG)
    INCLUDE(FindBoost)

    PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
    PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
    PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

    #PKG_SEARCH_MODULE(GLM REQUIRED glm)

    find_package(spdlog CONFIG REQUIRED)
    find_package(Threads)

ELSEIF(UNIX)
    MESSAGE("Building for Linux (Unixlike-Systems)")
    MESSAGE(${CMAKE_SYSTEM})

    # Add Linux specific variable settings here


    INCLUDE(FindPkgConfig)
    INCLUDE(FindOpenGL)
    INCLUDE(FindGLEW)
    #INCLUDE(FindPNG)
    INCLUDE(FindBoost)

    PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
    PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
    PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

    PKG_SEARCH_MODULE(GLM REQUIRED glm)

    find_package(Threads)
    find_package(spdlog CONFIG REQUIRED)


ENDIF()

add_library(shvrdengine ${engine_base_src})

add_executable(shvrdengine_exec main.cpp)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS} ${SDL2MIXER_INCLUDE_DIRS} ${Boost_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(shvrdengine_exec shvrdengine spdlog::spdlog ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${PNG_LIBRARIES} ${OPENGL_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${GLEW_LIBRARIES} ${GLM_LIBRARIES} ${SDL2MIXER_LIBRARIES} ${Boost_LIBRARIES})