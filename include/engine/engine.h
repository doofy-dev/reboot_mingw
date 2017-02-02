#pragma once
#include <preprocessor.h>
#include "driver/context.h"
#include <engine/scene.h>
#include <vector>
#include <reboot.h>
#include <driver/io/input.h>
namespace reboot
{
	class REBOOT_API Engine
    {
    public:
        static Scene *m_Scene;
        reboot_driver::Input *input;

    protected:
        std::vector<const char*> m_Tags;
    private:
        int m_FpsLimit;
        BYTE m_RenderMode;
		reboot_driver::Context *m_Contex;
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