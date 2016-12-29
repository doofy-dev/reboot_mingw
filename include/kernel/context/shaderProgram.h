#pragma once

#include <vector>
#include <glm/gtc/type_ptr.hpp>

#include <preprocessor.h>
#include "shaderVariable.h"

namespace reboot_kernel
{
	class REBOOT_API ShaderProgram
	{
	protected:
		std::vector<ShaderVariable*> m_Variables;
		std::vector<ShaderVariable*> m_Uniforms;
		unsigned int m_ShaderID;
	public:
        ShaderVariable* m_CurrentVariable;

        virtual ~ShaderProgram();
		unsigned int getID() const { return m_ShaderID; }
		virtual void start() {getAttributes();getUniforms();}
        virtual int getUniformValue(const char* name){}
		int boolToInt(bool v){return v?1:0;}
		virtual bool addShader(short shaderType, const char* shader) { return false; }
		virtual void getUniforms();
		virtual void getAttributes();
		virtual void bind();
		virtual void unbind();
        ShaderProgram* getUniform(const char* uniform);
		//Loading values
		virtual void load(float value) {}
		virtual void load(glm::vec2 &value) {}
		virtual void load(glm::vec3 &value) {}
		virtual void load(glm::vec4 &value) {}

		virtual void load(double value) {}
		virtual void load(glm::dvec2 &value) {}
		virtual void load(glm::dvec3 &value) {}
		virtual void load(glm::dvec4 &value) {}

		virtual void load(int value) {}
		virtual void load(glm::ivec2 &value) {}
		virtual void load(glm::ivec3 &value) {}
		virtual void load(glm::ivec4 &value) {}

		virtual void load(unsigned int value) {}
		virtual void load(glm::uvec2 &value) {}
		virtual void load(glm::uvec3 &value) {}
		virtual void load(glm::uvec4 &value) {}

		virtual void load(bool value) {}
		virtual void load(glm::bvec2 &value) {}
		virtual void load(glm::bvec3 &value) {}
		virtual void load(glm::bvec4 &value) {}

		virtual void load(glm::mat2x2 &value) {}
		virtual void load(glm::mat3x3 &value) {}
		virtual void load(glm::mat4x4 &value) {}

		virtual void load(glm::dmat2x2 &value) {}
		virtual void load(glm::dmat3x3 &value) {}
		virtual void load(glm::dmat4x4 &value) {}
	};
}