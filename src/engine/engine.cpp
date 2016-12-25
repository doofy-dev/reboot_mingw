#include <engine/engine.h>
#include <engine/entity/gameObject.h>
#include <engine/component/renderer.h>

namespace reboot
{
    Scene *Engine::m_Scene;
	Engine::Engine(BYTE contextType, BYTE canvasType)
	{
		m_Contex = new reboot_driver::Context(contextType, canvasType);
        m_Contex->m_Canvas->create();
	}
	Engine::~Engine()
	{
		delete m_Contex;
		delete m_Scene;
	}
    void Engine::setScene(Scene *scene) {
        m_Scene = scene;
    }
	void Engine::start()
	{
		while (!m_Contex->m_Canvas->closed()) {
            for(GameObject* g : m_Scene->m_GameObjects){
                g->Update();
                g->renderer->render(m_RenderMode);
            }
            m_Contex->m_Canvas->update();
        }
	}

    void Engine::setResolution(unsigned width, unsigned height) {
        m_Contex->m_Canvas->resize(width,height);
    }

}