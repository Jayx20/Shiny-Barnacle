#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Input {

    class Keyboard {
        private:
            GLFWwindow* m_window;
        public:
            bool keyPressed(int key);
            //bool keyPressed(char* keyName); possible addition
            Keyboard(GLFWwindow* window) {m_window = window;}
    };
}