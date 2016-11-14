#pragma once

#include "../../preprocessor.h"
#include "../../adapter/context/shaderProgram.h"

namespace reboot_driver
{
	class REBOOT_API Material
	{
	private:
		reboot_adapter::ShaderProgram *m_Shader;
		
	public:
		Material();
        template <struct T>
        void set(const char* variable, T value){m_Shader->getUniform(variable)->load(value); }
	};
}
