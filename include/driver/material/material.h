#pragma once

#include "../../preprocessor.h"
#include "../../kernel/context/shaderProgram.h"

namespace reboot_driver
{
	class REBOOT_API Material
	{
	private:
		reboot_kernel::ShaderProgram *m_Shader;
		
	public:
		Material();
        template <struct T>
        void set(const char* variable, T value){m_Shader->getUniform(variable)->load(value); }
	};
}
