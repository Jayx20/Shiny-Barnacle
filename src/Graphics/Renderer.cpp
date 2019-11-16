#include "Renderer.hpp"
#include <iostream>
#include <string>

// Include GLEW. Always include it before gl.h and glfw3.h, since it's a bit magic.
#include "GL/glew.h"
#include "GLFW/glfw3.h"

const int DEFAULT_WINDOW_WIDTH = 640;
const int DEFAULT_WINDOW_HEIGHT = 480;

namespace Graphics {

    Renderer::Renderer() {
        windowWidth = DEFAULT_WINDOW_WIDTH;
        windowHeight = DEFAULT_WINDOW_HEIGHT;
    }

    void Renderer::setWindowSize(int width, int height) {
        windowWidth = width;
        windowHeight = height;
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

        glEnable( GL_DEBUG_OUTPUT );
        glDebugMessageCallback(GLMessageCallback, 0 );

        //glViewPort(0, 0, windowWidth, windowHeight);

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