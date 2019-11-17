#include <iostream>
#include "Graphics.hpp"
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <vector>
#include "glm/glm.hpp"
#include "VectorUtil.hpp"

int main() {
    Graphics::Renderer renderer;

    int initResult = renderer.init();

    if(initResult<0) {
        return initResult;
    }

    
    ///basically everything in main is temporary code

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(renderer.getWindow(), GLFW_STICKY_KEYS, GL_TRUE);


    std::vector<glm::vec3> vertices = std::vector<glm::vec3>{glm::vec3(0,0,0), glm::vec3(1,0,0), glm::vec3(0,1,0), glm::vec3(1,1,0)};
    Graphics::Mesh testMesh(vectorsToFloats(vertices));
    //TODO: make a mesh builder

    std::vector<glm::vec3> colors;

    std::vector<float> vertices2 = std::vector<float> {
        -0.5, -0.5, 0,   -1, 1, 0,   0, 0, 0
    };
    colors = std::vector<glm::vec3> {
        glm::vec3(0, 0.25, 1)
    };

    Graphics::Mesh testMesh2(vertices2, vectorsToFloats(colors)); 


    glClearColor(1,1,1,1);

    do {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        renderer.drawMesh(testMesh);
        renderer.drawMesh(testMesh2);
        
        glfwSwapBuffers(renderer.getWindow());
        glfwPollEvents();
        
        
    } while (glfwGetKey(renderer.getWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(renderer.getWindow()) == 0);

    return 0;
}

/*
GLenum error = glGetError();
if (error!=GL_NO_ERROR) {
    fprintf(stderr, (const char*)gluErrorString(error));
}
*/