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
		const char* m_Name;
		const Transform *transform;
		const Renderer *renderer;
	
	private:
		bool m_IsActive;
		std::vector<Component*> components;
		int layer;
        unsigned int tag;

	public:
		GameObject(const char* name);
		GameObject():GameObject("GameObject"){}
		~GameObject();
		template <typename T>
		T* getComponent();
		Component* getComponentAt(unsigned int index);
		void addComponent(Component *component);
		bool isActive() { return m_IsActive; }

        void Update();
	};
}