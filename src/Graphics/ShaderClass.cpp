#include "ShaderClass.hpp"
#include <iostream>

namespace Graphics {
    ShaderClass::ShaderClass(std::string vshName, std::string fshName) {
        programId = glCreateProgram();

        createVertexShader(vshName);
        createFragmentShader(fshName);
        glAttachShader(programId, vertexShaderId);
        glAttachShader(programId, fragmentShaderId);
        
        link();
        validate();

        glDetachShader(programId, vertexShaderId);
        glDetachShader(programId, fragmentShaderId);
        
    }

    void ShaderClass::bind() {
        glUseProgram(programId);
    }

    void ShaderClass::unbind() {
        glUseProgram(0);
    }

    void ShaderClass::link() {
        glLinkProgram(programId);
        //glValidateProgram(programId);
        int worked;
        glGetProgramiv(programId, GL_LINK_STATUS, &worked);

        if(!worked) {
            GLint maxLength = 0;
            glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> errorLog(maxLength);
            glGetProgramInfoLog(programId, maxLength, &maxLength, &errorLog[0]);

            fprintf(stderr, "failed to link program, error: %s", errorLog.data());
            // Exit with failure.
            glDeleteProgram(programId); // this thing sucks.
            return;
        }
    }

    void ShaderClass::validate() {
        glValidateProgram(programId);
        int result;
        glGetProgramiv(programId, GL_VALIDATE_STATUS, &result);

        if(!result) {
            GLint maxLength = 0;
            glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> errorLog(maxLength);
            glGetProgramInfoLog(programId, maxLength, &maxLength, &errorLog[0]);

            fprintf(stderr, "failed to validate program, error: %s", errorLog.data());
            // Exit with failure.
            glDeleteProgram(programId); // this thing sucks.
            return;
        }
    }

    void ShaderClass::createVertexShader(std::string vertexShaderFile) {
        vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
        createShader(vertexShaderId, vertexShaderFile);
    }

    void ShaderClass::createFragmentShader(std::string fragmentShaderFile) {
        fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
        createShader(fragmentShaderId, fragmentShaderFile);
    }

    void ShaderClass::createShader(int shaderId, std::string sourceFile) {
        std::string sourcePath = "src/Graphics/Shaders/"+sourceFile;
        
        std::ifstream file(sourcePath.c_str());

        if(!file) {
            printf("failed to open file: %s\n", sourcePath.c_str());
            std::cerr << "Error: " << errno << std::endl;
        }

        std::string contents((std::istreambuf_iterator<char>(file)),
                                std::istreambuf_iterator<char>());
        const char* source = contents.c_str();
        
        
        glShaderSource(shaderId, 1, (const GLchar**)&source, NULL);
        glCompileShader(shaderId);

        GLint isCompiled = 0;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isCompiled);
        if(isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> errorLog(maxLength);
            glGetShaderInfoLog(shaderId, maxLength, &maxLength, &errorLog[0]);

            fprintf(stderr, "failed to compile shader");
            fprintf(stderr, errorLog.data());
            // Exit with failure.
            glDeleteShader(shaderId); // Don't leak the shader.
            return;
        }
        
    }
}