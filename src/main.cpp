#include <iostream>
#include "Graphics.hpp"
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <vector>
#include "glm/glm.hpp"
#include "VectorUtil.hpp"
#include "GameObjects.hpp"

int main() {
    Graphics::Renderer renderer;

    int initResult = renderer.init();

    if(initResult<0) {
        return initResult;
    }

    
    ///basically everything in main is temporary code

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(renderer.getWindow(), GLFW_STICKY_KEYS, GL_TRUE);

    #ifdef DEBUG
    printf("Debug Build\n");
    #endif

    std::vector<glm::vec3> vertices2 = std::vector<glm::vec3>{glm::vec3(0,0,0), glm::vec3(1,0,0), glm::vec3(0,1,0), glm::vec3(1,1,0)};
    Graphics::Mesh testMesh(std::vector<float>{0,0,0, 1,0,0, 0,0.5,0, 1,1,0 });

    std::vector<float> cubeColors;
    cubeColors.resize(72);
    std::fill(cubeColors.begin(), cubeColors.end(), 0.5);

    Graphics::Mesh testCubeMesh = Graphics::CubeMesh::genCubeMesh(1, Graphics::CubeMesh::cubeColors());

    Graphics::Mesh cubeMesh2 = Graphics::CubeMesh::genCubeMesh(2, Graphics::CubeMesh::cubeColors());

    GameObjects::Object testCubeObj(testCubeMesh);

    GameObjects::Object cube2(cubeMesh2, glm::vec3(-5, 5, 0));

    testCubeObj.setPosition(glm::vec3(0, -0.5, 0));

    glClearColor(1,1,1,1);

    do {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        renderer.drawMesh(testMesh);
        renderer.drawObject(testCubeObj);
        renderer.drawObject(cube2);
        testCubeObj.setRotation(testCubeObj.getRotation()+glm::vec3(0.1,0.01,0));

        cube2.setPosition(cube2.getPosition() + glm::vec3(.1,0,0));
        if(cube2.getPosition().x>20)
            cube2.setPosition(glm::vec3(-20, cube2.getPosition().y, cube2.getPosition().z));
        
        cube2.setRotation(cube2.getRotation() + glm::vec3(0,0.01,0.05));

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