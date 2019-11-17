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
    };
}