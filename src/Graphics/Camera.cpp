#include "Camera.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Graphics {
    glm::mat4 Camera::viewMatrix() {
        glm::mat4 vMatrix = glm::mat4(1.0f);
        
        glm::translate(vMatrix, -m_position);
        //glm::rotate(vMatrix, -m_rotation);

        return vMatrix;
    }
}

