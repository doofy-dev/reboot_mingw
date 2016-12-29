#include <kernel/context/openGL/shaderProgram.h>
#include <GL/glew.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

namespace reboot_kernel_opengl
{
    ShaderProgram::ShaderProgram():reboot_kernel::ShaderProgram()
	{
        m_ShaderID = glCreateProgram();
        errorCheck("shader create");
        std::cout<<"Shaderprogram ID "<<m_ShaderID<<std::endl;
	}
    ShaderProgram::~ShaderProgram()
	{

	}

	bool ShaderProgram::addShader(short shaderType, const char* shader)
	{
		GLuint type = 0;
		const char* st;
		switch (shaderType)
		{
		case SHADER_FRAGMENT:
			st = "Fragment";
			type = GL_FRAGMENT_SHADER;
			break;
		case SHADER_GEOMETRY:
			st = "Geometry";
			type = GL_GEOMETRY_SHADER;
			break;
		case SHADER_VERTEX:
			st = "Vertex";
			type = GL_VERTEX_SHADER;
			break;
		default:
			st = "Unknown";
			type = shaderType;
			break;
		}
		GLuint id = build(type, shader);
		if (id == 0)
		{
			std::cout << st << " shader loading failed!" << std::endl;
			return false;
		}
        std::cout << st << " shader loaded!" << std::endl;
		glAttachShader(m_ShaderID, id);

		m_ShaderFileID.push_back(id);
		return true;
	}
	void ShaderProgram::start()
	{
        std::cout<<"opengl shader start"<<std::endl;
		glLinkProgram(m_ShaderID);

        errorCheck("linkshader");
		glValidateProgram(m_ShaderID);

        errorCheck("validate");
		for(auto id :m_ShaderFileID){
			glDeleteShader(id);
        }

        errorCheck("deleteshader");
		m_ShaderFileID.clear();
        errorCheck("clear");
        getUniforms();
	}
	unsigned ShaderProgram::build(GLuint type, const char* shader)
	{
		auto shaderID = glCreateShader(type);

		glShaderSource(shaderID, 1, &shader, NULL);
		glCompileShader(shaderID);
		GLint result;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(shaderID, length, &length, &error[0]);
			std::cout <<"SHADER ERROR "<< &error[0] << std::endl;
			glDeleteShader(shaderID);
			return 0;
		}
		return shaderID;
	}

    int ShaderProgram::getUniformValue(const char *name) {
        return glGetUniformLocation(m_ShaderID,name);
    }

	void ShaderProgram::getUniforms()
	{
        int numActiveUniforms=0;
        glGetProgramiv(m_ShaderID, GL_ACTIVE_UNIFORM_BLOCKS, &numActiveUniforms);
std::cout<<"Loading uniforms count: "<<numActiveUniforms<<" for shader "<<m_ShaderID<<std::endl;
        for (unsigned unif = 0; unif < numActiveUniforms; ++unif)
        {
            std::vector<GLchar> nameData(256);
            int arraySize = 0;
            GLenum type = 0;
            GLsizei actualLength = 0;
            glGetActiveUniform(m_ShaderID, unif, nameData.size(), &actualLength, &arraySize, &type, &nameData[0]);
            std::string name((char*)&nameData[0], actualLength - 1);

            //TODO: lenght, type and other infos are missing
            reboot_kernel::ShaderVariable *variable = new reboot_kernel::ShaderVariable();
            variable->ID=glGetUniformLocation(m_ShaderID,&name[0]);
            variable->name=&name[0];
            std::cout<<"Field: "<<variable->name<<" ID: "<<variable->ID<<std::endl;
            m_Uniforms.push_back(variable);
            nameData.clear();
        }
	}
	void ShaderProgram::getAttributes()
	{
	}
	void ShaderProgram::bind()
	{
		glUseProgram(m_ShaderID);
	}
	void ShaderProgram::unbind()
	{
		glUseProgram(0);
	}
	void ShaderProgram::load(float value)
	{
		glUniform1f(m_CurrentVariable->ID, value);
	}
	void ShaderProgram::load(glm::vec2& value)
	{
		glUniform2f(m_CurrentVariable->ID, value.x, value.y);
	}
	void ShaderProgram::load(glm::vec3& value)
	{
		glUniform3f(m_CurrentVariable->ID, value.x, value.y, value.z);
	}
	void ShaderProgram::load(glm::vec4& value)
	{
		glUniform4f(m_CurrentVariable->ID, value.x, value.y, value.z, value.w);
	}
	void ShaderProgram::load(double value)
	{
		glUniform1d(m_CurrentVariable->ID, value);
	}
	void ShaderProgram::load(glm::dvec2& value)
	{
		glUniform2d(m_CurrentVariable->ID, value.x, value.y);
	}
	void ShaderProgram::load(glm::dvec3& value)
	{
		glUniform3d(m_CurrentVariable->ID, value.x, value.y, value.z);
	}
	void ShaderProgram::load(glm::dvec4& value)
	{
		glUniform4d(m_CurrentVariable->ID, value.x, value.y, value.z, value.w);
	}
	void ShaderProgram::load(int value)
	{
		glUniform1i(m_CurrentVariable->ID, value);
	}
	void ShaderProgram::load(glm::ivec2& value)
	{
		glUniform2i(m_CurrentVariable->ID, value.x, value.y);
	}
	void ShaderProgram::load(glm::ivec3& value)
	{
		glUniform3i(m_CurrentVariable->ID, value.x, value.y, value.z);
	}
	void ShaderProgram::load(glm::ivec4& value)
	{
		glUniform4i(m_CurrentVariable->ID, value.x, value.y, value.z, value.w);
	}
	void ShaderProgram::load(unsigned value)
	{
		glUniform1ui(m_CurrentVariable->ID, value);
	}
	void ShaderProgram::load(glm::uvec2& value)
	{
		glUniform2ui(m_CurrentVariable->ID, value.x, value.y);
	}
	void ShaderProgram::load(glm::uvec3& value)
	{
		glUniform3ui(m_CurrentVariable->ID, value.x, value.y, value.z);
	}
	void ShaderProgram::load(glm::uvec4& value)
	{
		glUniform4ui(m_CurrentVariable->ID, value.x, value.y, value.z, value.w);
	}
	void ShaderProgram::load(bool value)
	{
		glUniform1i(m_CurrentVariable->ID, boolToInt(value));
	}
	void ShaderProgram::load(glm::bvec2& value)
	{
		glUniform2i(m_CurrentVariable->ID, boolToInt(value.x), boolToInt(value.y));
	}
	void ShaderProgram::load(glm::bvec3& value)
	{
		glUniform3i(m_CurrentVariable->ID, boolToInt(value.x), boolToInt(value.y), boolToInt(value.z));
	}
	void ShaderProgram::load(glm::bvec4& value)
	{
		glUniform4i(m_CurrentVariable->ID, boolToInt(value.x), boolToInt(value.y), boolToInt(value.z), boolToInt(value.w));
	}

	void ShaderProgram::load(glm::mat2x2& value)
	{
		glUniformMatrix2fv(m_CurrentVariable->ID, 1, GL_FALSE, glm::value_ptr(value));
	}
	void ShaderProgram::load(glm::mat3x3& value)
	{
		glUniformMatrix3fv(m_CurrentVariable->ID, 1, GL_FALSE, glm::value_ptr(value));
	}
	void ShaderProgram::load(glm::mat4x4& value)
	{
        errorCheck("before mat4 load");
		glUniformMatrix4fv(m_CurrentVariable->ID, 1, GL_FALSE, glm::value_ptr(value));
        errorCheck("after mat4 load");
	}
	void ShaderProgram::load(glm::dmat2x2& value)
	{
		glUniformMatrix2dv(m_CurrentVariable->ID, 1, GL_FALSE, glm::value_ptr(value));
	}
	void ShaderProgram::load(glm::dmat3x3& value)
	{
		glUniformMatrix3dv(m_CurrentVariable->ID, 1, GL_FALSE, glm::value_ptr(value));
	}
	void ShaderProgram::load(glm::dmat4x4& value)
	{
		glUniformMatrix4dv(m_CurrentVariable->ID, 1, GL_FALSE, glm::value_ptr(value));
	}
}
