#pragma once
#include "../preprocessor.h"
#include "../driver/contextManager.h"
#include "scene.h"
#include <vector>

namespace reboot
{
	class REBOOT_API Engine
    {
    protected:
        static Scene *m_Scene;
        std::vector<const char*> m_Tags;
    private:
        int m_FpsLimit;
		reboot_driver::ContextManager *m_ContextManager;
	public:
		Engine(short contextType, short canvasType);
		~Engine();
		void setScene(Scene *scene) { m_Scene = scene; }
		void start();
		void setFpsLimit(int limit) { m_FpsLimit = limit; }
        void setResolution(unsigned width, unsigned height);
	};
}