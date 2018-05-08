//
// Created by thekatze on 06/02/18.
//

#include "GLSLProgram.h"
#include "../Util/Logger.h"
#include "../Util/Constants.h"

#include <fstream>
#include <vector>

GLSLProgram::GLSLProgram() : programID(0), vertexShaderID(0), fragmentShaderID(0), numAttributes(0) {

}

GLSLProgram::~GLSLProgram() = default;


/**
 * Creates a GLSL Shaderprogram using a vertex- and a fragmentshader source file.
 * @param vertexShaderPath Relative file path to the vertex shader source file
 * @param fragmentShaderPath Relative file path to the fragment shader source file
 */
void GLSLProgram::compileShaders(const std::string &vertexShaderPath, const std::string &fragmentShaderPath) {

    programID = glCreateProgram();

    vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    if (vertexShaderID == 0) {
        Logger::error("Creating vertex shader failed.");
        Logger::terminate(Constants::STATUS_FAILED);
    }

    fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    if (fragmentShaderID == 0) {
        Logger::error("Creating fragment shader failed.");
        Logger::terminate(Constants::STATUS_FAILED);
    }

    compileShader(vertexShaderPath, vertexShaderID);
    compileShader(fragmentShaderPath, fragmentShaderID);

}

/**
 * Links the shader source files. Requires the shaders to be compiled first.
 */
void GLSLProgram::linkShaders() {

    if (vertexShaderID == 0 || fragmentShaderID == 0) {
        Logger::error("Shaders have no id, thus are not successfully compiled.");
        return;
    }

    //Attach shaders
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);

    glLinkProgram(programID);

    //Error Checking

    GLint isLinked = 0;
    glGetProgramiv(programID, GL_LINK_STATUS, &isLinked);

    if (isLinked == GL_FALSE) {
        GLint maxLength = 0;
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<char> errorLog(maxLength);
        glGetProgramInfoLog(programID, maxLength, &maxLength, &errorLog[0]);

        Logger::error("Shaderprogram failed to link shaders");
        Logger::error(std::string(errorLog.begin(), errorLog.end()));


        //Prevent Leaking
        glDeleteProgram(programID);
        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);
    }

    //Detach Shaders after successful link

    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

}

/**
 * Helper function that reads a shaderfile and compiles it.
 * @param filePath Filepath for the shaderfile
 * @param shaderID The ID to bind the shader to
 */
void GLSLProgram::compileShader(const std::string &filePath, GLuint shaderID) {
    //Read the file
    std::ifstream shaderFile(filePath);
    if (shaderFile.fail()) {
        perror(filePath.c_str());
        Logger::error("Failed to open " + filePath);
        Logger::terminate(Constants::STATUS_FAILED);
    }

    std::string fileContents;
    std::string line;

    while (std::getline(shaderFile, line)) {
        fileContents += line + "\n";
    }
    shaderFile.close();

    //Compile the shader

    //Jank - You can't pass the contents in one line
    const char *contentsPtr = fileContents.c_str();
    glShaderSource(shaderID, 1, &contentsPtr, nullptr);

    glCompileShader(shaderID);

    GLint success = 0;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

    if (success == GL_FALSE) {
        GLint maxLength;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<char> errorLog(maxLength);
        glGetShaderInfoLog(shaderID, maxLength, &maxLength, &errorLog[0]);

        Logger::error(std::string(errorLog.begin(), errorLog.end()));
        Logger::error("Shader failed to compile");
        glDeleteShader(shaderID);
    }
}


/**
 * Adds a vertex attribute
 * @param attributeName The attribute identifier
 */
void GLSLProgram::addAttribute(const std::string &attributeName) {
    glBindAttribLocation(programID, numAttributes++, attributeName.c_str());
}

/**
 * Binds the GLSLProgram (Shader)
 */
void GLSLProgram::bind() {
    glUseProgram(programID);
    for (int i = 0; i < numAttributes; i++) {
        glEnableVertexAttribArray(i);
    }
}

/**
 * Unbinds the GLSLProgram
 */

void GLSLProgram::unbind() {
    glUseProgram(0);
    for (int i = 0; i < numAttributes; i++) {
        glDisableVertexAttribArray(i);
    }
}

/**
 * Finds a uniform variable in a shaderprogram and returns its location.
 * @param uniformName The uniform string to find.
 * @return Returns the identifier for the Uniform.
 */

GLint GLSLProgram::getUniformLocation(const std::string &uniformName) {
    GLint location = glGetUniformLocation(programID, uniformName.c_str());
    if (location == GL_INVALID_INDEX) {
        Logger::warning("Uniform " + uniformName + " not found in shader!");
    }
    return location;
}
