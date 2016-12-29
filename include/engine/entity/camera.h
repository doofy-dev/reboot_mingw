#pragma once

#include <vector>
#include <glm/gtc/type_ptr.hpp>
#include "../../preprocessor.h"
#include "gameObject.h"

namespace reboot
{
	class Camera : public GameObject
	{
	public:
        float m_FieldOfView;
        float m_NearPlane;
        float m_FarPlane;
        std::vector<int> renderLayer;
        int m_FrameWidth, m_FrameHeight;
        glm::mat4 m_ProjectionMatrix;
        glm::vec3 m_BackgroundColor;

		int target;
	public:
        Camera(int width, int height);
		void Update() override;
        glm::mat4 getViewMatrix(glm::vec3 *position, glm::vec3 *rotation);
        glm::mat4 getViewMatrix();
        void createProjectionMatrix();
        inline glm::mat4 getProjectionMatrix() { return m_ProjectionMatrix; }

        inline glm::vec3 getBackgroundColor() { return m_BackgroundColor; }
        inline void setBackgroundColor(glm::vec3 color) { m_BackgroundColor = color; }
    };
}