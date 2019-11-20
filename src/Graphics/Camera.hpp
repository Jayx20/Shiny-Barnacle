#pragma once

#include "glm/glm.hpp"

namespace Graphics {
    class Camera {
        private:
            glm::vec3 m_position;
            glm::vec3 m_rotation;
        
        public:
            glm::mat4 viewMatrix();
    };
}