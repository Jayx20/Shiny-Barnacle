#pragma once

#include <vector>
#include "GL/glew.h" // Always include glew before gl.h and glfw3.h, since it's a bit magic.
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"
#include "Mesh.hpp"
#include "ShaderClass.hpp"
#include "../GameObjects.hpp"

namespace Graphics {
    class Renderer {
        private:
            GLFWwindow* window;
            int windowWidth;
            int windowHeight;
            bool shaderBound; //in the future, we may need to know WHICH shader is bound
            static void uGlfwErrorCallback(int, const char* err_str);
            static void GLMessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam );
            
            Graphics::ShaderClass mainShader;

        public:
            Renderer();
            int init();
            void setWindowSize(int width, int height);
            GLFWwindow* getWindow() {return window;}
            void drawMesh(Mesh &mesh);
            void drawObject(GameObjects::Object &object);
            //void drawMeshes(std::vector<Mesh> &meshes);

    };
}