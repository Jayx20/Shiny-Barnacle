#include "Renderer.hpp"

#include <iostream>
#include <string>
#include "GL/glew.h" // Always include glew before gl.h and glfw3.h, since it's a bit magic.
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp" //glm::ortho
#include "GLFW/glfw3.h"

const int DEFAULT_WINDOW_WIDTH = 1920;
const int DEFAULT_WINDOW_HEIGHT = 1080;

namespace Graphics {

    Renderer::Renderer() {
        shaderBound = false;
        windowWidth = DEFAULT_WINDOW_WIDTH;
        windowHeight = DEFAULT_WINDOW_HEIGHT;
    }

    void Renderer::setWindowSize(int width, int height) {
        windowWidth = width;
        windowHeight = height;

        //TODO: actually update the window
    }

    void Renderer::drawObject(GameObjects::Object &object) {
        mainShader.bind();
        shaderBound = true;

        mainShader.setUniformMat4("worldMatrix", object.getWorldMatrix());

        drawMesh(object.m_mesh);

        mainShader.setUniformMat4("worldMatrix", glm::mat4(1.0f) ); //should be identity matrix
        
        mainShader.unbind();
        shaderBound = false;
    }

    void Renderer::drawMesh(Mesh &mesh) {
        ///TODO: i just realized this copies the mesh, i need to fix that, lamo
        
        //only enable the shader if needed, if it's already enabled don't mess with it
        if(!shaderBound) {
            mainShader.bind();
            //don't update the variable, because we will unbind at the end, leaving it false
        }
        

        glBindVertexArray(mesh.getVaoId());
        int numIndices = 0; //should probably leave indices count in the mesh class, but this way we can use any VAO regardless of whether its in a mesh
        glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &numIndices);

        glDrawElements(mesh.getDrawType(), numIndices, GL_UNSIGNED_INT, NULL );
        
        #ifdef DEBUG
        //Error check
        GLint error = glGetError();
        if (error!=GL_NO_ERROR) {
            std::cout << gluErrorString(error) << std::endl;
        }
        #endif
        
        glBindVertexArray(0);

        if(!shaderBound) {
            mainShader.unbind();
        }

    }

    /**
     * With help from <a href="https://www.opengl-tutorial.org/beginners-tutorials/tutorial-1-opening-a-window/">opengl-tutorial.org</a> 
     */
    int Renderer::init() {
        std::cout << "Initializing Graphics!\n";

        glewExperimental = true;
        if ( !glfwInit() ) {
            fprintf(stderr, "Failed to initialize GLFW\n");
            return -1;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

        glfwSetErrorCallback(uGlfwErrorCallback);

        window = glfwCreateWindow(windowWidth, windowHeight, "Untitled Game", NULL, NULL);
        if (window == NULL) {
            fprintf(stderr, "Failed to create window\n");
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window);
        glewExperimental=true; //idk why it does it again but whatever

        if (glewInit() != GLEW_OK) {
            fprintf(stderr, "GLEW failed to initialize\n");
            return -1;
        }

        #ifdef DEBUG
        glEnable( GL_DEBUG_OUTPUT );
        glDebugMessageCallback(GLMessageCallback, 0 );
        #endif

        mainShader.init("vertex.vsh","fragment.fsh");

        //glm::mat4 projectionMatrix = glm::ortho(0,windowWidth,0,windowHeight,-1,1);
        glm::mat4 projectionMatrix = glm::ortho(-16.f,16.f,-9.f,9.f,-10.f,10.f);

        mainShader.bind();
        mainShader.setProjectionMatrix(projectionMatrix);
        mainShader.setUniformMat4("worldMatrix", glm::mat4(1.0f) ); //should be identity matrix
        mainShader.unbind();

        #ifdef DEBUG
        //Error check
        GLenum error = glGetError();
        if (error!=GL_NO_ERROR) {
            std::cout << gluErrorString(error) << std::endl;
        }
        #endif

        glEnable(GL_DEPTH_TEST);

        return 0;
    }

    void Renderer::uGlfwErrorCallback(int, const char* err_str) {
        std::cout << "GLFW Error: " << err_str << std::endl;
    } 

    void Renderer::GLMessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
    {
        fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
            ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
                type, severity, message );
    }

}