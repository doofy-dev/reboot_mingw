#pragma once
#include <preprocessor.h>
#include "../driver/contextManager.h"
#include <engine/scene.h>
#include <vector>
#include <afxres.h>

namespace reboot
{
	class REBOOT_API Engine
    {
    public:
        static Scene *m_Scene;

    protected:
        std::vector<const char*> m_Tags;
    private:
        int m_FpsLimit;
        BYTE m_RenderMode;
		reboot_driver::ContextManager *m_ContextManager;
	public:
		Engine(BYTE contextType, BYTE canvasType);
		~Engine();
        void setRenderMode(BYTE renderMode){m_RenderMode=renderMode;}
		void setScene(Scene *scene);
		void start();
		void setFpsLimit(int limit) { m_FpsLimit = limit; }
        void setResolution(unsigned width, unsigned height);
	};
}