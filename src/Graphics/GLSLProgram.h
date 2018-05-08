//
// Created by thekatze on 06/02/18.
//

#ifndef SDLOGL_GLSLPROGRAM_H
#define SDLOGL_GLSLPROGRAM_H

#include <string>
#include <GL/glew.h>

/**
 * An interface for vertex- and fragmentshaders.
 */
class GLSLProgram {

    GLuint programID;
    GLuint vertexShaderID;
    GLuint fragmentShaderID;

    int numAttributes;

    void compileShader(const std::string &filePath, GLuint shaderID);


public:
    GLSLProgram();

    ~GLSLProgram();

    void compileShaders(const std::string &vertexShaderPath, const std::string &fragmentShaderPath);

    void linkShaders();

    void addAttribute(const std::string &attributeName);

    GLint getUniformLocation(const std::string &uniformName);

    void bind();

    void unbind();
};


#endif //SDLOGL_GLSLPROGRAM_H
