#include <kernel/context/shaderProgram.h>
#include <iostream>
namespace reboot_kernel
{
	ShaderProgram::ShaderProgram()
	{
	}

	ShaderProgram::~ShaderProgram(){}

	void ShaderProgram::getUniforms(){}
	void ShaderProgram::getAttributes(){}
	void ShaderProgram::bind(){}
	void ShaderProgram::unbind(){}

    ShaderProgram* ShaderProgram::getUniform(const char *uniform) {
        for(ShaderVariable* variable:m_Variables){
            if(strcmp(variable->name,uniform)==0) {
                m_CurrentVariable = variable;
                return this;
            }
        }
        std::cout<<"Shader variable '"<<uniform<<"' not found!"<<std::endl;
        return this;
    }
}
