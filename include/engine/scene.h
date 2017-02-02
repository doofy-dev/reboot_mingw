#pragma once

#include <vector>
#include "entity/camera.h"


#include "../preprocessor.h"
#include "entity/gameObject.h"
namespace reboot
{
	class REBOOT_API Scene
	{
	private:
		char* m_Name;

		//@TODO: Maybe std::list
    public:
		std::vector<GameObject*> m_GameObjects;
        std::vector<Camera*> m_Cameras;
        Camera *mainCamera;
	public:
		Scene(char* name);
		Scene():Scene((char*)"Scene"){};
		~Scene();
		void assignGameObject(GameObject *g);
		void assignCamera(Camera *c, bool main);
		void deleteGameObject(GameObject *g);
		unsigned int findIndexByName(char* name);
		GameObject* getGameObjectByIndex(unsigned int index);

		void update(BYTE rendermode);
	};
}
