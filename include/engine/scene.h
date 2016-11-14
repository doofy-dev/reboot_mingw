#pragma once

#include <vector>

#include "../preprocessor.h"
#include "entity/gameObject.h"
namespace reboot
{
	class REBOOT_API Scene
	{
	private:
		char* m_Name;
		//@TODO: Maybe std::list
		std::vector<GameObject*> m_GameObjects;
	public:
		Scene(char* name);
		Scene();
		~Scene();
		void assignGameObject(GameObject *g);
		void deleteGameObject(GameObject *g);
		unsigned int findIndexByName(char* name);
		GameObject* getGameObjectByIndex(unsigned int index);

		void update();
	};
}
