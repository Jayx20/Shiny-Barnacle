#include "Mesh.hpp"

#include <iostream>
#include "../VectorUtil.hpp"

namespace Graphics {

    //i considered using pointers for all of my vertex data stuff, may change to that later

    ///TODO: make the builder class, i am sick of typing std::vector and glm::vec3 over and over
    Mesh::Mesh(
                std::vector<float> vertices,
                std::vector<float> colors,
                std::vector<float> textCoords,
                std::vector<unsigned int> indices,
                int drawType
    ) {
        m_vertices = vertices;
        m_colors = colors;
        m_textCoords = textCoords;
        m_indices = indices;
        m_drawType = drawType;

        if(indices.size()==0) {
            m_indices = genIndexArray();
        }
        

        //change this in the future to be done manually?
        if (checkValid() ) {createBuffers();}
        //emptyArrays(); //probably reenable this in the future idk
    }

    bool Mesh::checkValid() {
        ///TODO: make this actually do something lmao
        return true;
    }

    void Mesh::createBuffers() {
        if (vaoId==0) {
            glGenVertexArrays(1, &vaoId);
        }

        glBindVertexArray(vaoId);

        //vertices
        glGenBuffers(1, &vertexBufferId);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
        glBufferData(GL_ARRAY_BUFFER, m_vertices.size()*sizeof(float), m_vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, NULL);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0); //?

        //indices
        glGenBuffers(1, &indexBufferId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size()*sizeof(unsigned int), m_indices.data(), GL_STATIC_DRAW);

        //color
        glGenBuffers(1, &colorBufferId);
        glBindBuffer(GL_ARRAY_BUFFER, colorBufferId);
        glBufferData(GL_ARRAY_BUFFER, m_colors.size()*sizeof(float), m_colors.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(1, 3, GL_FLOAT, false, 0, NULL);
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, 0); //?

        //textures
        //todo

        glBindVertexArray(0);
    }

    void Mesh::deleteBuffers() {
        glDeleteBuffers(1, &vertexBufferId);
        glDeleteBuffers(1, &indexBufferId);
        glDeleteBuffers(1, &colorBufferId);
        glDeleteBuffers(1, &textCoordsBufferId);
        glDeleteBuffers(1, &textImageBufferId);
        glDeleteVertexArrays(1, &vaoId);
    }
    
    std::vector<unsigned int> Mesh::genIndexArray() {
        std::vector<unsigned int> indices;

        //GL_TRIANGLE_STRIP
        if(m_drawType==5) {
            indices.resize(m_vertices.size());
            for (unsigned int i = 0; i<m_vertices.size(); i++) {
                indices[i] = i;
            }
        }
        else {
            //other index generation hasn't been made, so just crash
            ///TODO: either choose to only use GL_TRIANGLE_STRIP or add the rest of the generators
            assert("invalid mesh drawType" && false);
        }

        return indices;
    }

    /**
     * Clears all the data in the arrays of this object, for when it is has already been copied into buffers.
     */
    void Mesh::emptyArrays() {
            m_vertices = std::vector<float>();
            m_indices = std::vector<unsigned int>();
            m_colors = std::vector<float>{0,0,0};
            m_textCoords = std::vector<float>();
    }

}