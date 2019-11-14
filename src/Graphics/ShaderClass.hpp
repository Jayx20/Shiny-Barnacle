#pragma once
#include <string>

namespace Graphics {
    class ShaderClass{
        private:
            int programId;
        
        public:
            ShaderClass(std::string vertexShader, std::string fragmentShader);
            void bind();
            void unbind();
    };
}