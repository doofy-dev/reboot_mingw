#pragma once
#include "../preprocessor.h"
#include <vector>
#include <afxres.h>
#include "../kernel/canvas/canvas.h"
#include "../kernel/context/shaderProgram.h"

namespace reboot_driver
{
	class REBOOT_API ContextManager
	{
	private:
		short m_ContextType;
		reboot_kernel::Canvas *m_Canvas;
		std::vector<reboot_kernel::ShaderProgram*> m_Programs;
	public:
		ContextManager(BYTE contextType, BYTE canvasType);
		void update();
		bool closed();
		void start() { m_Canvas->create(); }
	};
}
