#pragma once
#include "../preprocessor.h"
#include <vector>
#include "../adapter/canvas/canvas.h"
#include "../adapter/context/shaderProgram.h"

namespace reboot_driver
{
	class REBOOT_API ContextManager
	{
	private:
		short m_ContextType;
		reboot_adapter::Canvas *m_Canvas;
		std::vector<reboot_adapter::ShaderProgram*> m_Programs;
	public:
		ContextManager(short contextType, short canvasType);
		void update();
		bool closed();
		void start() { m_Canvas->create(); }
	};
}
