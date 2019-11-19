#pragma once

#include "glm/glm.hpp"
#include "../Graphics.hpp"

namespace GameObjects {
    class Object {

        private:
            glm::vec3 m_position;
            glm::vec3 m_rotation;

        public:
            Object(Graphics::Mesh mesh, glm::vec3 position = glm::vec3(0,0,0));

            Graphics::Mesh m_mesh;

            //transformation matrix for the object
            glm::mat4 getWorldMatrix();
            void setPosition(glm::vec3 position) {m_position = position;}
            void setRotation(glm::vec3 rotation) {m_rotation = rotation;}
            glm::vec3 getPosition() {return m_position;}
            glm::vec3 getRotation() {return m_rotation;}
    };
}