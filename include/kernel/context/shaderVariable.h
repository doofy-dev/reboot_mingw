#pragma once

#include "../../preprocessor.h"
namespace reboot_kernel
{
	struct REBOOT_API ShaderVariable
	{
		virtual ~ShaderVariable()
		{
		}

		unsigned int ID;
		int size;
		int length;
		unsigned int type;
		const char* name;
	};
}