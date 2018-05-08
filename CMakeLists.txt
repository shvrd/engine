cmake_minimum_required(VERSION 3.3)
project(shvrdengine_test)

set(CMAKE_CXX_STANDARD 11)


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

add_subdirectory(src)
add_subdirectory(test)