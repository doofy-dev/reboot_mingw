#include <engine/engine.h>
#include <engine/entity/gameObject.h>
#include <engine/component/renderer.h>

namespace reboot
{
    Scene *Engine::m_Scene;
	Engine::Engine(BYTE contextType, BYTE canvasType)
	{
		m_ContextManager = new reboot_driver::ContextManager(contextType, canvasType);
	}
	Engine::~Engine()
	{
		delete m_ContextManager;
		delete m_Scene;
	}
    void Engine::setScene(Scene *scene) {
        m_Scene = scene;
    }
	void Engine::start()
	{
		m_ContextManager->start();
		while (!m_ContextManager->closed()) {
            for(GameObject* g : m_Scene->m_GameObjects){
                g->Update();
                g->renderer->render(m_RenderMode);
            }
            m_ContextManager->update();
        }
	}

    void Engine::setResolution(unsigned width, unsigned height) {

    }

}