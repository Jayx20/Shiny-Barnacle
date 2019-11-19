#pragma once
#include <string>
#include "GL/glew.h"
#include "glm/glm.hpp"
#include <fstream>
#include <vector>

namespace Graphics {
    class ShaderClass{
        private:
            GLuint programId;
            GLuint vertexShaderId;
            GLuint fragmentShaderId;
            bool initialized;
        
            void createShader(int shaderId, std::string sourceFile);
            void createVertexShader(std::string vertexShader);
            void createFragmentShader(std::string fragmentShader);
            bool link();
            bool validate();
            void cleanup();

        public:
            ShaderClass();
            void init(std::string vertexShader, std::string fragmentShader);
            void bind();
            void unbind();
            void setProjectionMatrix(glm::mat4x4 projectionMatrix);
            void setUniformMat4(std::string matrixName, glm::mat4 matrix);
    };
}