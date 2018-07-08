//
// Created by thekatze on 06/02/18.
//

#ifndef SHVRDENGINE_SRC_GLSLPROGRAM_H
#define SHVRDENGINE_SRC_GLSLPROGRAM_H

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
    unsigned char compileStatus;

    void compileShader(const std::string &filePath, GLuint shaderID);

public:
    static const unsigned char VERTEX_SHADER_FAILED = 0x01;
    static const unsigned char FRAGMENT_SHADER_FAILED = 0x02;
    static const unsigned char SHADER_COMPILE_FAILED = 0x04;
    static const unsigned char COMPILE_SUCCESS = 0x08;

    GLSLProgram();

    ~GLSLProgram();

    void compileShaders(const std::string &vertexShaderPath, const std::string &fragmentShaderPath);

    void linkShaders();

    void addAttribute(const std::string &attributeName);

    GLint getUniformLocation(const std::string &uniformName);

    void bind();

    void unbind();

    unsigned char getCompileStatus() {return compileStatus;};
};


#endif //SHVRDENGINE_SRC_GLSLPROGRAM_H
