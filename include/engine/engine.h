#pragma once
#include "../preprocessor.h"
#include "../driver/contextManager.h"
#include "scene.h"

namespace reboot
{
	class REBOOT_API Engine
	{
	private:
		int m_FpsLimit;
		Scene *m_Scene;
		reboot_driver::ContextManager *m_ContextManager;
	public:
		Engine(short contextType, short canvasType);
		~Engine();
		void setScene(Scene *scene) { m_Scene = scene; }
		void start();
		void setFpsLimit(int limit) { m_FpsLimit = limit; }
	};
}