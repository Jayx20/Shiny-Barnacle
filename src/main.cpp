#include <iostream>
#include "Graphics.hpp"
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <vector>
#include "glm/glm.hpp"
#include "VectorUtil.hpp"
#include "GameObjects.hpp"
#include "Input.hpp"

int main() {
    Graphics::Renderer renderer;
    int initResult = renderer.init();
    
    Input::Keyboard keyboard(renderer.getWindow());

    if(initResult<0) {
        return initResult;
    }

    
    ///basically everything in main is temporary code

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(renderer.getWindow(), GLFW_STICKY_KEYS, GL_TRUE);

    #ifdef DEBUG
    printf("Debug Build\n");
    #endif

    Graphics::Mesh testMesh(std::vector<float>{0,0,0, 5,0,0, 5,0.5,0, 1,1,5 });

    Graphics::Mesh testMesh2(std::vector<float>{5,1,7, 0,1,2, 6.9,4.20,9.11, -2,4,1, 2.1,-2.1,0},
                             std::vector<float>{-.5,.1,.7, 0,.8,.9, -.69,-.420,-.911, 1,-.4,.1, -.21,-.21,1},
                             std::vector<float>(),
                             std::vector<unsigned int> {0,1,2,3,4},
                             5
    );
    

    Graphics::Mesh testCubeMesh = Graphics::CubeMesh::genCubeMesh(1, Graphics::CubeMesh::cubeColors());

    Graphics::Mesh cubeMesh2 = Graphics::CubeMesh::genCubeMesh(2);

    GameObjects::Object testCubeObj(testCubeMesh);

    GameObjects::Object cube2(cubeMesh2, glm::vec3(-5, 5, 0));

    //GameObjects::Object cube3(Graphics::CubeMesh::genCubeMesh(3));
    
    GameObjects::Object monstrosity(testMesh2);

    testCubeObj.setPosition(glm::vec3(0, -0.5, 0));

    monstrosity.setPosition(glm::vec3(-9, -3, 0));

    glClearColor(1,1,1,1);

    float spinSpeed = .002;
    float moveSpeed = .05;
    float turnSpeed = .025;

    Graphics::Camera camera;
    camera.setPosition(glm::vec3(0, 5, 0));

    do {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        renderer.updateView(camera);

        renderer.drawMesh(testMesh);
        renderer.drawObject(testCubeObj);
        renderer.drawObject(cube2);
        testCubeObj.setRotation(testCubeObj.getRotation()+glm::vec3(0.01,0.001,0));

        cube2.setPosition(cube2.getPosition() + glm::vec3(.01,0,0));
        if(cube2.getPosition().x>20)
            cube2.setPosition(glm::vec3(-20, cube2.getPosition().y, cube2.getPosition().z));
        
        cube2.setRotation(cube2.getRotation() + glm::vec3(0,0.001,0.005));



        //fun code
        //if(glfwGetKey(renderer.getWindow(), GLFW_KEY_D)) monstrosity.setRotation(monstrosity.getRotation() + glm::vec3(0,spinSpeed,0));
        //if(glfwGetKey(renderer.getWindow(), GLFW_KEY_A)) monstrosity.setRotation(monstrosity.getRotation() + glm::vec3(0,-spinSpeed,0));
        //if(glfwGetKey(renderer.getWindow(), GLFW_KEY_W)) monstrosity.setRotation(monstrosity.getRotation() + glm::vec3(-spinSpeed,0,0));
        //if(glfwGetKey(renderer.getWindow(), GLFW_KEY_S)) monstrosity.setRotation(monstrosity.getRotation() + glm::vec3(spinSpeed,0,0));
        //if(glfwGetKey(renderer.getWindow(), GLFW_KEY_Q)) monstrosity.setRotation(monstrosity.getRotation() + glm::vec3(0,0,spinSpeed));
        //if(glfwGetKey(renderer.getWindow(), GLFW_KEY_E)) monstrosity.setRotation(monstrosity.getRotation() + glm::vec3(0,0,-spinSpeed));

        if(keyboard.keyPressed(GLFW_KEY_LEFT)) camera.move(glm::vec3(-moveSpeed,0,0));
        if(keyboard.keyPressed(GLFW_KEY_RIGHT)) camera.move(glm::vec3(moveSpeed,0,0));
        if(keyboard.keyPressed(GLFW_KEY_UP)) camera.move(glm::vec3(0,moveSpeed,0));
        if(keyboard.keyPressed(GLFW_KEY_DOWN)) camera.move(glm::vec3(0,-moveSpeed,0));

        if(keyboard.keyPressed(GLFW_KEY_D)) camera.rotate(glm::vec3(0, turnSpeed, 0));
        if(keyboard.keyPressed(GLFW_KEY_A)) camera.rotate(glm::vec3(0, -turnSpeed, 0));
        if(keyboard.keyPressed(GLFW_KEY_W)) camera.rotate(glm::vec3(-turnSpeed, 0, 0));
        if(keyboard.keyPressed(GLFW_KEY_S)) camera.rotate(glm::vec3(turnSpeed, 0, 0));
        if(keyboard.keyPressed(GLFW_KEY_Q)) camera.rotate(glm::vec3(0, 0, turnSpeed));
        if(keyboard.keyPressed(GLFW_KEY_E)) camera.rotate(glm::vec3(0, 0, -turnSpeed));
        //
        renderer.drawObject(monstrosity);


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