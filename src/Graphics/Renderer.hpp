#pragma once

#include "GL/glew.h"
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"

namespace Graphics {
    class Renderer {
        private:
            GLFWwindow* window;
            int windowWidth;
            int windowHeight;
            static void uGlfwErrorCallback(int, const char* err_str);
            static void GLMessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam );

        public:
            Renderer();
            int init();
            void setWindowSize(int width, int height);
            GLFWwindow* getWindow() {return window;}

    };
}