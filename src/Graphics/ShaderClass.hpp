#pragma once
#include <string>
#include "GL/glew.h"
#include <fstream>
#include <vector>

namespace Graphics {
    class ShaderClass{
        private:
            GLuint programId;
            GLuint vertexShaderId;
            GLuint fragmentShaderId;
        
            void createShader(int shaderId, std::string sourceFile);

        public:
            ShaderClass(std::string vertexShader, std::string fragmentShader);
            void bind();
            void unbind();
            void createVertexShader(std::string vertexShader);
            void createFragmentShader(std::string fragmentShader);
            void link();
            void cleanup();
            void validate();
    };
}