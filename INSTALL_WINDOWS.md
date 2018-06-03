# Windows Prerequesites

Since the building process on Windows is considerably harder it is separately described in this file. Thanks for that Microsoft.






## Install MinGW
Download the prepackaged MinGW distribution from [nuwen](https://nuwen.net/mingw.html), who took care of the hassle that is installing the boost and GLM library on Windows.  
Execute the self-extracting archive and let it install to preferrably `C:\MinGW`.
## Install CMake
Download [CMake](https://cmake.org/download/) from its site and install it. There shouldn't be any special configuration reqiured.
## Install PkgConfig
Download [pkgconfig-lite](https://sourceforge.net/projects/pkgconfiglite/) from its Sourceforge website and extract the archive into your MinGW folder, so the `bin` and `share` folders are merged.
## SDL2
Download the [MinGW SDL2](https://www.libsdl.org/download-2.0.php) development library from its site and copy the contents of the `x86_64-w64-mingw32` folder into your MinGW folder.
## glm
***NO SOLUTION YET***
## OpenAL
Download the [OpenAL SDK](https://www.openal.org/downloads/) from its website and install it anywhere. Then copy the `include` folder from your OpenAL installation to your MinGW folder.
## glew
Download the [glew Windows Binaries](http://glew.sourceforge.net/) from their site and copy the `include` folder of the archive into your MinGW folder.
For the `lib` and `bin` folders, copy the contents of their `Release\Win64` folders into their respective MinGW folders.
## spdlog
***NO SOLUTION YET***

