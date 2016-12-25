#pragma once

#include <preprocessor.h>
#include <iostream>
#include <driver/context.h>
#include "../../preprocessor.h"
#include "../../kernel/context/shaderProgram.h"

namespace reboot_driver
{
	class REBOOT_API Material
	{
	private:
		reboot_kernel::ShaderProgram *m_Shader;
		
	public:
		Material(){
            m_Shader = Context::current->createShader();
        }
        void loadShader(short shaderType, const char* content){
            m_Shader->addShader(shaderType,content);
        }
        template <typename T>
        void set(const char* variable, T value){
//            std::cout<< type_name<T>() <<std::endl;
            m_Shader->getUniform(variable)->load(value);
        }
	};
}
