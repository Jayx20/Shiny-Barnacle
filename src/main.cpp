#include <iostream>
#include "Graphics.hpp"
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <vector>
#include "glm/glm.hpp"


int main() {
    Graphics::Renderer renderer;

    int initResult = renderer.init();

    if(initResult<0) {
        return initResult;
    }

    
    ///temporary code

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(renderer.getWindow(), GLFW_STICKY_KEYS, GL_TRUE);


    std::vector<glm::vec3> vertices = std::vector<glm::vec3>{glm::vec3(0,0,0), glm::vec3(1,0,0), glm::vec3(0,1,0), glm::vec3(1,1,0)};
    Graphics::Mesh testMesh(vertices);

    glClearColor(1,1,1,1);

    Graphics::ShaderClass testProgram = Graphics::ShaderClass("vertex.vsh","fragment.fsh");
    


    do {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


        testProgram.bind();

        
        
        glBindVertexArray(testMesh.getVaoId());
        
        
        GLint numIndices;
        glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &numIndices);

        //glDrawArrays(GL_TRIANGLES, 0 ,3);
        GLenum error = glGetError();
        if (error!=GL_NO_ERROR) {
            std::cout << gluErrorString(error) << std::endl;
        }
        glDrawElements(GL_TRIANGLE_STRIP, numIndices, GL_UNSIGNED_INT, NULL);
        
        glBindVertexArray(0);
        
        testProgram.unbind();


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