#pragma once

#include <glm/gtc/type_ptr.hpp>
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
        glm::mat4 m_TransformationMatrix;
    public:
        glm::vec3 position, rotation, scale;
    public:
        //TODO what if i create a tree structure manager and using that instead of this?
        std::vector<GameObject*> children;
        GameObject* parent;
        Transform();
        void createTransformationMatrix();
	    inline glm::mat4 getTransformationMatrix(){ return m_TransformationMatrix;}
    };
}