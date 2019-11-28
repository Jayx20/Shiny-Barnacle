#include "Camera.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Graphics {
    glm::mat4 Camera::viewMatrix() {
        glm::mat4 vMatrix = glm::mat4(1.0f);
        
        glm::mat4 positionMatrix = glm::translate(glm::mat4(1.0f), -m_position);
        //glm::rotate(vMatrix, -m_rotation);

        //x axis rotation
        glm::mat4 rotationMatrixX = glm::rotate(glm::mat4(1.0f), -m_rotation.x, glm::vec3(1,0,0));

        //y axis rotation
        glm::mat4 rotationMatrixY = glm::rotate(glm::mat4(1.0f), -m_rotation.y, glm::vec3(0,1,0));

        //z axis rotation
        glm::mat4 rotationMatrixZ = glm::rotate(glm::mat4(1.0f), -m_rotation.z, glm::vec3(0,0,1));

        ///TODO: figure out how to combine these, it should be easy but GLM didnt like it

        glm::mat4 rotationMatrix = rotationMatrixX * rotationMatrixY * rotationMatrixZ;

        vMatrix = rotationMatrix*positionMatrix;

        return vMatrix;
    }
}

