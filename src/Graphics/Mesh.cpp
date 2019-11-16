#include "Mesh.hpp"
#include <iostream>

namespace Graphics {

    //i considered using pointers for all of my vertex data stuff, may change to that later
    Mesh::Mesh(
                std::vector<glm::vec3> vertices,
                std::vector<int> indices,
                int drawType,
                std::vector<glm::vec3> colors,
                std::vector<glm::vec2> textCoords
    ) {
        assert(vertices.size()!=0 && "invalid mesh, no vertices");
        
        m_vertices = vectorsToFloats(vertices);
        m_indices = indices;
        m_drawType = drawType;
        m_colors = vectorsToFloats(colors);
        m_textCoords = vectorsToFloats(textCoords);

        if(indices.size()==0) {
            m_indices = genIndexArray();
        }
        

        //change this in the future to be done manually?
        if (checkValid() ) {createBuffers();}
        emptyArrays();
    }

    bool Mesh::checkValid() {
        return true;
    }


    void Mesh::createBuffers() {
        if (vaoId==0) {
            glGenVertexArrays(1, &vaoId);
        }

        if(vaoId==0) {
            printf("bruh");
        }

        glBindVertexArray(vaoId);



        //vertices
        glGenBuffers(1, &vertexBufferId);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
        glBufferData(GL_ARRAY_BUFFER, m_vertices.size()*sizeof(float), m_vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, NULL);
        glBindBuffer(GL_ARRAY_BUFFER, 0); //?

        //indices
        glGenBuffers(1, &indexBufferId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size()*sizeof(int), m_indices.data(), GL_STATIC_DRAW);
        
        //color
        glGenBuffers(1, &colorBufferId);
        glBindBuffer(GL_ARRAY_BUFFER, colorBufferId);
        glBufferData(GL_ARRAY_BUFFER, m_colors.size()*sizeof(float), m_colors.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(1, 3, GL_FLOAT, false, 0, NULL);
        //glBindBuffer(GL_ARRAY_BUFFER, 0); //?


        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

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
    
    std::vector<int> Mesh::genIndexArray() {
        std::vector<int> indices;

        //GL_TRIANGLE_STRIP
        if(m_drawType==5) {
            indices.resize(m_vertices.size());
            for (int i = 0; i<m_vertices.size(); i++) {
                indices[i] = i;
            }
        }
        else {
            //give up, basically lmao
            assert("invalid mesh drawType" && false);
        }

        return indices;
    }

    /**
     * Clears all the data in the arrays of this object, for when it is has already been copied into buffers.
     */
    void Mesh::emptyArrays() {
            m_vertices = std::vector<float>();
            m_indices = std::vector<int>();
            m_colors = std::vector<float>{0,0,0};
            m_textCoords = std::vector<float>();
    }

}