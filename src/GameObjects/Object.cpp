#include "Object.hpp"
#include "glm/gtc/matrix_transform.hpp" //glm::transform

namespace GameObjects {

    Object::Object(Graphics::Mesh mesh, glm::vec3 position) : m_mesh(mesh) {
        m_position = position;
        //m_rotation = glm::vec3(0,0,0); ?neccesary?
    }

    glm::mat4 Object::getWorldMatrix() {
        glm::mat4 worldMatrix;

        glm::mat4 positionMatrix = glm::mat4(1.0f); //identity matrix
        positionMatrix = glm::translate(positionMatrix, m_position);

        //glm::mat4 rotationMatrix = glm::mat4(1.0f); //identity matrix
        //rotationMatrix = glm::rotate(rotationMatrix, m_rotation);

        //y axis rotation for testing
        glm::mat4 rotationMatrixY = glm::mat4(1.0f);
        rotationMatrixY = glm::rotate(rotationMatrixY, m_rotation.y, glm::vec3(0,1,0));

        //z axis rotation for testing
        glm::mat4 rotationMatrixZ = glm::mat4(1.0f);
        rotationMatrixZ = glm::rotate(rotationMatrixZ, m_rotation.z, glm::vec3(0,0,1));

        glm::mat4 rotationMatrix = rotationMatrixY * rotationMatrixZ;

        worldMatrix = positionMatrix*rotationMatrix; //add rotation etc later
        return worldMatrix;
    }
}