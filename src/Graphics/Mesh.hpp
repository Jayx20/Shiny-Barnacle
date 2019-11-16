#pragma once

#include "GL/glew.h"
#include "glm/glm.hpp"
#include <vector>
#include "../VectorUtil.hpp"

namespace Graphics {
    class Mesh {

        private:
            GLuint vaoId=0;
            GLuint vertexBufferId=0;
            GLuint indexBufferId=0;
            GLuint colorBufferId=0;
            GLuint textCoordsBufferId=0;
            GLuint textImageBufferId=0;

            int m_drawType;

            std::vector<float> m_vertices;
            std::vector<int> m_indices;
            std::vector<float> m_colors;
            std::vector<float> m_textCoords;
            //more texture functionality is to be added

            std::vector<int> genIndexArray();

        public:
            int getVaoId() {return vaoId;}
            int getDrawType() {return m_drawType;}
            
            //possibly make constructor private in the future
            Mesh(
                std::vector<glm::vec3> vertices,
                std::vector<int> indices = std::vector<int>(),
                int drawType = 5,
                std::vector<glm::vec3> colors = std::vector<glm::vec3>{glm::vec3(0,0,0)},
                std::vector<glm::vec2> textCoords = std::vector<glm::vec2>()
                //add image later peehaps
            );
            bool checkValid();
            void createBuffers();
            void deleteBuffers();
            void emptyArrays();
    };
}