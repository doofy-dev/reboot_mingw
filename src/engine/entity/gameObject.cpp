#include <engine/entity/gameObject.h>
#include <engine/component/component.h>
#include <engine/component/transform.h>
#include <engine/component/renderer.h>

namespace reboot
{
	GameObject::GameObject(const char* name):m_Name(name)
	{
        transform=new Transform();
	}
	void GameObject::addComponent(Component* component)
	{
		
	}
	template <typename T>
	T* GameObject::getComponent()
	{
		return nullptr;
	}
	Component* GameObject::getComponentAt(unsigned index)
	{
		return nullptr;
	}
	GameObject::~GameObject()
	{
		
	}

    void GameObject::Update() {
        for(Component* component:components)
            component->Update();
    }

}