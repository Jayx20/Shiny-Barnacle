#include "ShaderClass.hpp"
#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp" //glm::value_ptr

namespace Graphics {

    ShaderClass::ShaderClass() {
        initialized = false;
    }

    void ShaderClass::init(std::string vshName, std::string fshName) {
        programId = glCreateProgram();

        createVertexShader(vshName);
        createFragmentShader(fshName);
        glAttachShader(programId, vertexShaderId);
        glAttachShader(programId, fragmentShaderId);
        
        //link and validate, and only set initialized to true if the process is a success
        initialized = link() && validate();

        glDetachShader(programId, vertexShaderId);
        glDetachShader(programId, fragmentShaderId);
        
    }

    void ShaderClass::bind() {
        if(initialized)
            glUseProgram(programId);
        else
            fprintf(stderr, "Error: Attempt to bind uninitialized shader!");
        
    }

    void ShaderClass::unbind() {
        glUseProgram(0);
    }

    bool ShaderClass::link() {
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
        }
        return worked;

    }

    bool ShaderClass::validate() {
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
        }
        return result;
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
        std::string sourcePath = "./shaders/"+sourceFile;
        
        std::ifstream file(sourcePath.c_str());

        if(!file) {
            fprintf(stderr, "failed to open file: %s\n", sourcePath.c_str());
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
            fprintf(stderr, "%s\n", errorLog.data());
            // Exit with failure.
            glDeleteShader(shaderId); // Don't leak the shader.
            return;
        }
        
    }

    void ShaderClass::setProjectionMatrix(glm::mat4x4 projectionMatrix) {
        int uniformLocation = glGetUniformLocation(programId, "projectionMatrix");
        if (uniformLocation < 0) {
            fprintf(stderr, "Could not find projectionMatrix");
        }
        float matrixFloats[16] = {0.0};
        
        //https://stackoverflow.com/questions/18890084/how-to-read-the-values-from-a-glmmat4
        const float *floatSource = (const float*)glm::value_ptr(projectionMatrix);

        for (int i = 0; i<16; ++i) {
            matrixFloats[i] = floatSource[i];
        }

        glUniformMatrix4fv(uniformLocation, 1, false, matrixFloats);
    }

    void ShaderClass::setUniformMat4(std::string matrixName, glm::mat4 matrix) {
        int uniformLocation = glGetUniformLocation(programId, matrixName.c_str());
        if (uniformLocation < 0) {
            fprintf(stderr, "Could not find %s", matrixName.c_str());
        }
        float matrixFloats[16] = {0.0};
        
        const float *floatSource = (const float*)glm::value_ptr(matrix);

        for (int i = 0; i<16; ++i) {
            matrixFloats[i] = floatSource[i];
        }

        glUniformMatrix4fv(uniformLocation, 1, false, matrixFloats);
    }
}