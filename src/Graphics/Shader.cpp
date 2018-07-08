//
// Created by thekatze on 04/04/18.
//

#include "Shader.h"
#include "../Util/Logger.h"

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

    if (!defaultShader->isCompiled()) {
        Logger::error("Default Shaders could not be compiled, terminating!");
        Logger::terminate(~GLSLProgram::SHADER_COMPILE_FAILED);
    }

    if (!defaultShader->isLinked()) {
        Logger::error("Default Shaderprogram could not be linked, terminating!");
        Logger::terminate(~GLSLProgram::COMPILE_SUCCESS);
    }

    return defaultShader;
}