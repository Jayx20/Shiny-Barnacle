#include <iostream>
#include "Graphics.hpp"
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"



int main() {
    Graphics::Renderer renderer;

    int initResult = renderer.init();

    if(initResult<0) {
        return initResult;
    }

    
    ///temporary code

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(renderer.getWindow(), GLFW_STICKY_KEYS, GL_TRUE);

    do {
        glClear( GL_COLOR_BUFFER_BIT );

        glfwSwapBuffers(renderer.getWindow());
        glfwPollEvents();
    } while (glfwGetKey(renderer.getWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(renderer.getWindow()) == 0);

    return 0;
}