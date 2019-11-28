#include "Keyboard.hpp"

namespace Input {
    bool Keyboard::keyPressed(int key) {
        //int result = glfwGetKey(m_window, key);
        //return (result == GLFW_PRESS);
        return glfwGetKey(m_window, key);
    }
}