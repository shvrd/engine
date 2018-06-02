# Windows Prerequesites

Since the building process on Windows is considerably harder it is separately described in this file. Thanks for that Microsoft.

## Install MinGW

Download [MingGW](https://sourceforge.net/projects/mingw/files/) from its download site and install it preferably in its default installation location `C:/MingGW`.  
Then install the base packages, the C-compiler and the C++-compiler from the MinGW package manager.

## Install CMake

Download [CMake](https://cmake.org/download/) from its site and install it. There shouldn't be any special configuration reqiured.

## Set environment variables

Set the `CXX` compiler variable to your MinGW g++ compiler, located in its default installation at `C:/MinGW/bin/g++`

## Install PkgConfig

Download [pkgconfig-lite](https://sourceforge.net/projects/pkgconfiglite/) from its Sourceforge website and extract the archive into your MinGW folder, so the `bin` and `share` folders are merged.

## SDL2

## OpenAL

## glew

## glm

## boost

## spdlog


