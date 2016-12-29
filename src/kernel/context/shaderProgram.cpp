#include <kernel/context/shaderProgram.h>
#include <iostream>
namespace reboot_kernel
{
	ShaderProgram::~ShaderProgram(){}

	void ShaderProgram::getUniforms(){}
	void ShaderProgram::getAttributes(){}
	void ShaderProgram::bind(){}
	void ShaderProgram::unbind(){}

    ShaderProgram* ShaderProgram::getUniform(const char *uniform) {
        for(ShaderVariable* variable:m_Uniforms){
            if(strcmp(variable->name,uniform)==0) {
                m_CurrentVariable = variable;
                return this;
            }
        }
        int id = getUniformValue(uniform);

        if(id>=0){
            ShaderVariable *variable = new reboot_kernel::ShaderVariable();
            variable->ID=id;
            variable->name=uniform;
            std::cout<<"Field loaded manually: "<<variable->name<<" ID: "<<variable->ID<<std::endl;
            m_Uniforms.push_back(variable);
            m_CurrentVariable = variable;
            return  this;
        }

        std::cout<<"Shader variable '"<<uniform<<"' not found!"<<std::endl;
        return this;
    }
}
