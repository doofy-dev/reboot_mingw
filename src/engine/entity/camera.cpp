#include <engine/entity/camera.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <engine/component/transform.h>

namespace reboot{
    Camera::Camera(int width, int height)
            :GameObject("Camera"),m_FrameWidth(width),m_FrameHeight(height),
             m_NearPlane(0.1f), m_FarPlane(100), m_FieldOfView(80) {
        createProjectionMatrix();
    }

    void Camera::Update() {

    }

    void Camera::createProjectionMatrix() {
        float aspectRatio = (float)m_FrameWidth / (float)m_FrameHeight;
        m_ProjectionMatrix = glm::perspective(m_FieldOfView, aspectRatio, m_NearPlane, m_FarPlane);
    }

    glm::mat4 Camera::getViewMatrix(glm::vec3 *position, glm::vec3 *rotation) {
        glm::mat4 rotationMat = glm::rotate(glm::radians(rotation->x), glm::vec3(1, 0, 0))
                                *glm::rotate(glm::radians(rotation->y), glm::vec3(0, 1, 0))
                                *glm::rotate(glm::radians(rotation->z), glm::vec3(0, 0, 1));

        glm::mat4 translate = glm::translate(glm::mat4(1.0f), -(*position));

        return rotationMat*translate;
    }
    glm::mat4 Camera::getViewMatrix() {
        return getViewMatrix(transform->position,transform->rotation);
    }
}