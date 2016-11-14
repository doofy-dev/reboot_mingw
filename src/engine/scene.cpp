#include <engine/scene.h>
namespace reboot
{
	Scene::Scene():m_Name((char*)"Scene")
	{
		
	}
	Scene::Scene(char* name) :m_Name(name)
	{

	}
	Scene::~Scene()
	{
		
	}

	void Scene::assignGameObject(GameObject* g)
	{
		
	}
	 void Scene::deleteGameObject(GameObject* g)
	 {
		 
	 }
	 unsigned Scene::findIndexByName(char* name)
	 {
		 return 0;
	 }
	 GameObject* Scene::getGameObjectByIndex(unsigned index)
	 {
		 return new GameObject();
	 }
	void Scene::update()
	{
		
	}


}