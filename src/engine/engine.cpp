#include <engine/engine.h>

namespace reboot
{
	Engine::Engine(short contextType, short canvasType)
	{
		m_ContextManager = new reboot_driver::ContextManager(contextType, canvasType);
	}
	Engine::~Engine()
	{
		delete m_ContextManager;
		delete m_Scene;
	}
	void Engine::start()
	{
		m_ContextManager->start();
		while (!m_ContextManager->closed())
			m_ContextManager->update();
	}

}