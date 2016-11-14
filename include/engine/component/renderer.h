#pragma once

#include "../../preprocessor.h"

namespace reboot
{
	class REBOOT_API Renderer
	{
	private:
		int m_ShaderID;
		
	public:
		void render();
	};
}
