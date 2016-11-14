#pragma once

#include <vector>

#include "../../preprocessor.h"

namespace reboot
{
	class Component;
	class Transform;
	class Renderer;

	class REBOOT_API GameObject
	{
	public:
		char* m_Name;
		const Transform *transform;
		const Renderer *renderer;
	
	private:
		bool m_IsActive;
		std::vector<Component*> components;
		int layer;

	public:
		GameObject(char* name);
		GameObject();
		~GameObject();
		template <typename T>
		T* getComponent();
		Component* getComponentAt(unsigned int index);
		void addComponent(Component *component);
		bool isActive() { return m_IsActive; }
	};
}