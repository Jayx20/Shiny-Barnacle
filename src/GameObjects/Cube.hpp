#include "glm/vec3.hpp"
#include "VectorUtil.hpp"
#include "Graphics/Mesh.hpp"

namespace GameObjects {
    //need to make a gameobject class later to extend from

    //a complete cube has 24 vertices, instead of just 8
    class Cube {
        private:
            //move stuff to private when done testing
        public:
            Cube();
            Cube(glm::vec3 center, float sidelength);

            Graphics::Mesh m_mesh; 

            //generates a mesh for itself
            void updateMesh();

            //creates a mesh for a complex cube
            static Graphics::Mesh genComplexCubeMesh(float width, std::vector<float> colors);
            //makes cool colors for a complex cube mesh
            static std::vector<float> complexCubeColors();
    };
}