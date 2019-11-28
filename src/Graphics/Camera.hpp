#pragma once

#include "glm/glm.hpp"

namespace Graphics {
    class Camera {
        private:
            glm::vec3 m_position;
            glm::vec3 m_rotation;
        
        public:
            glm::mat4 viewMatrix();
            void setPosition(glm::vec3 position) {m_position = position;}
            void move(glm::vec3 movement) {m_position += movement;}
            void setRotation(glm::vec3 rotation) {m_rotation = rotation;}
            void rotate(glm::vec3 rotation) {m_rotation += rotation;}
            glm::vec3 getPosition() {return m_position;}
    };
}

