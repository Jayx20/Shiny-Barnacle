#pragma once

#include "glm/vec3.hpp"
#include "Mesh.hpp"

namespace Graphics {
    //need to make a gameobject class later to extend from

    //a complete cube has 24 vertices, instead of just 8
    class CubeMesh {
        private:
            //move stuff to private when done testing
        public:
            //Graphics::Mesh m_mesh; 

            //generates a mesh for itself
            //void updateMesh();

            //creates a mesh for a complex cube
            static Graphics::Mesh genCubeMesh(float width, std::vector<float> colors);
            //makes cool colors for a complex cube mesh
            static std::vector<float> cubeColors();
    };
}