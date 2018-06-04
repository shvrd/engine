# SHɅRD Engine

![Logo](http://shvrd.erdlof.org/shvrdheader.png "SHARD - Logo")

---

A low-level, yet easy to use cross-platform 2d game engine for medium to big game projects.
Written in c++ with platform independency in mind, this engine offers high performance for visually appealing two-dimensional games for Windows, macOS and Linux.

## Code Status
[![CodeFactor](https://www.codefactor.io/repository/github/shvrd/shvrdengine/badge/master)](https://www.codefactor.io/repository/github/shvrd/shvrdengine/overview/master)

## Features

* Cross-platform
* Simple game-state based system
* Easy to use graphics abstraction
* Custom shader support
* Included Sound System

## Known Issues

* **The Windows build is still undergoing work. If you have experience using MinGW your help would be much appreciated! :)**

## Installation

As this engine still is in heavy development, there are no release verions yet. However, you can build it from source
by cloning this repository following these steps:  
Building from source on Windows requires a few extra steps, if you want to do so follow the instructions in INSTALL_WINDOWS.md before continuing.

### Install required development libraries

The required development libraries are:

* OpenGL
* SDL2
* OpenAL
* glew
* glm
* boost
* spdlog

These can be installed from the package manager of your Linux distribution, homebrew on Mac or (thanks for that) manually on Windows.

### Download "DownloadProject"

For automated installation and building of the [google-test](https://github.com/google/googletest) framework this engine uses the [DownloadProject](https://github.com/Crascit/DownloadProject) CMake module. 
The module has to be cloned into the `.repo/DownloadProject` folder. This can be done using the following command from project root:  

`git clone https://github.com/Crascit/DownloadProject.git .repo/DownloadProject/`

### Generate makefiles

Since this engine is built with CMake, the makefiles have to be generated. This can simply be done using the following command at project root.

`cmake CMakeLists.txt`

### Building the library

Building the library is simply done by running the following command.

`make shvrdengine`

The built engine file `libshvrdengine` with your platform-specific library file extension can then be found inside the `src/` directory.

## Contributing

If you want to contribute to this project please follow the guidelines provided in CONTRIBUTING.MD.

## Special Thanks

* [MakingGamesWithBen](https://www.youtube.com/playlist?list=PLSPw4ASQYyymu3PfG9gxywSPghnSMiOAW) for his awesome OpenGL tutorial
* [snyderL](https://github.com/snyderl) for macOS support
