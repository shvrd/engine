//
// Created by thekatze on 04/04/18.
//

#include "Shader.h"

Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath) {
    boundGLSLProgram = new GLSLProgram();

    boundGLSLProgram->compileShaders(vertexShaderPath, fragmentShaderPath);
    boundGLSLProgram->addAttribute("vertexPostion");
    boundGLSLProgram->addAttribute("vertexColor");
    boundGLSLProgram->addAttribute("vertexUV");

    boundGLSLProgram->linkShaders();
}

Shader *Shader::getDefaultShader() {
    std::string assetPath = "../../Assets/";

    static Shader *defaultShader = new
            Shader(assetPath + "Shaders/basicShading.vert",
                   assetPath + "Shaders/basicShading.frag");

    return defaultShader;
}