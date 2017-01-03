#include <engine/component/transform.h>
#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>

namespace reboot{
    Transform::Transform() {
        position=glm::vec3(0,0,1);
        rotation=glm::vec3(0);
        scale=glm::vec3(1);
    }
    void Transform::createTransformationMatrix() {
        glm::mat4 rotationMatrix = glm::rotate(rotation.x,glm::vec3(1,0,0)) *
                glm::rotate(rotation.y,glm::vec3(0,1,0))*
                glm::rotate(rotation.z,glm::vec3(0,0,1));
        glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f),position);
        glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f),scale);
        m_TransformationMatrix = translationMatrix*rotationMatrix*scaleMatrix;
    }
}