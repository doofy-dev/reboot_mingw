#pragma once

#include <gtc/type_ptr.hpp>
#include <vector>

#include "../../preprocessor.h"
#include "component.h"

namespace reboot
{
	class Component;
	class GameObject;
	class REBOOT_API Transform : public Component
	{
    private:
        glm::mat4 *m_TransformationMatrix;
        glm::vec3 *position, *rotation, *scale;
    public:
        std::vector<GameObject*> children;
        GameObject* parent;
        Transform();
	};
}