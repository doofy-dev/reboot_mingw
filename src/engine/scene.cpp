#include <engine/scene.h>
#include <engine/component/renderer.h>
#include <engine/entity/camera.h>

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
		m_GameObjects.push_back(g);
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
	void Scene::update(BYTE rendermode)
	{
        glm::mat4 view = mainCamera->getViewMatrix();
        glm::mat4 projection = mainCamera->getProjectionMatrix();
        for(GameObject* g : m_GameObjects){
            g->Update();
            g->renderer->m_Mesh->m_Material->bind();
            errorCheck("gu");
            g->renderer->m_Mesh->m_Material->set("view",view);

            errorCheck("vmat");
            g->renderer->m_Mesh->m_Material->set("proj",projection);


            errorCheck("pmat");
            g->renderer->render(rendermode);

            g->renderer->m_Mesh->m_Material->unbind();
            errorCheck("render");
        }
	}
    void Scene::assignCamera(Camera *c, bool main) {
        m_Cameras.push_back(c);
        if(main)
            mainCamera=c;
    }


}