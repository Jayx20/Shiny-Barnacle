#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Graphics {
    class Renderer {
        private:
            GLFWwindow* window;
            int windowWidth;
            int windowHeight;

        public:
            Renderer();
            int init();
            void setWindowSize(int width, int height);
            GLFWwindow* getWindow() {return window;}

    };
}