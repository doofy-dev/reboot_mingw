#include <engine/entity/gameObject.h>
#include <engine/component/component.h>
#include <engine/component/transform.h>

namespace reboot
{
	GameObject::GameObject(const char* name):m_Name(name)
	{
        transform=new Transform();
	}
	void GameObject::addComponent(Component* component)
	{
        component->gameObject=this;
		components.push_back(component);
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
            component->update();
    }

}