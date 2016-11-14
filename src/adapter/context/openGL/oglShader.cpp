#include <adapter/context/openGL/oglShader.h>
#include <GL/glew.h>
#include <iostream>

namespace reboot_adapter
{
	OGLShader::~OGLShader()
	{
		m_ShaderID = glCreateProgram();
	}

	bool OGLShader::addShader(short shaderType, const char* shader)
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
		glAttachShader(m_ShaderID, id);
		m_ShaderFileID.push_back(id);
		return true;
	}
	void OGLShader::start()
	{
		glLinkProgram(m_ShaderID);
		glValidateProgram(m_ShaderID);
		for(auto id :m_ShaderFileID)
			glDeleteShader(id);
		m_ShaderFileID.clear();
	}
	unsigned OGLShader::build(GLuint type, const char* shader)
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
			std::cout << &error[0] << std::endl;
			glDeleteShader(shaderID);
			return 0;
		}
		return shaderID;
	}

	void OGLShader::getUniforms()
	{
	}
	void OGLShader::getAttributes()
	{
	}
	void OGLShader::bind()
	{
		glUseProgram(m_ShaderID);
	}
	void OGLShader::unbind()
	{
		glUseProgram(0);
	}
	void OGLShader::load(float value)
	{
		glUniform1f(m_CurrentVariable->ID, value);
	}
	void OGLShader::load(glm::vec2& value)
	{
		glUniform2f(m_CurrentVariable->ID, value.x, value.y);
	}
	void OGLShader::load(glm::vec3& value)
	{
		glUniform3f(m_CurrentVariable->ID, value.x, value.y, value.z);
	}
	void OGLShader::load(glm::vec4& value)
	{
		glUniform4f(m_CurrentVariable->ID, value.x, value.y, value.z, value.w);
	}
	void OGLShader::load(double value)
	{
		glUniform1d(m_CurrentVariable->ID, value);
	}
	void OGLShader::load(glm::dvec2& value)
	{
		glUniform2d(m_CurrentVariable->ID, value.x, value.y);
	}
	void OGLShader::load(glm::dvec3& value)
	{
		glUniform3d(m_CurrentVariable->ID, value.x, value.y, value.z);
	}
	void OGLShader::load(glm::dvec4& value)
	{
		glUniform4d(m_CurrentVariable->ID, value.x, value.y, value.z, value.w);
	}
	void OGLShader::load(int value)
	{
		glUniform1i(m_CurrentVariable->ID, value);
	}
	void OGLShader::load(glm::ivec2& value)
	{
		glUniform2i(m_CurrentVariable->ID, value.x, value.y);
	}
	void OGLShader::load(glm::ivec3& value)
	{
		glUniform3i(m_CurrentVariable->ID, value.x, value.y, value.z);
	}
	void OGLShader::load(glm::ivec4& value)
	{
		glUniform4i(m_CurrentVariable->ID, value.x, value.y, value.z, value.w);
	}
	void OGLShader::load(unsigned value)
	{
		glUniform1ui(m_CurrentVariable->ID, value);
	}
	void OGLShader::load(glm::uvec2& value)
	{
		glUniform2ui(m_CurrentVariable->ID, value.x, value.y);
	}
	void OGLShader::load(glm::uvec3& value)
	{
		glUniform3ui(m_CurrentVariable->ID, value.x, value.y, value.z);
	}
	void OGLShader::load(glm::uvec4& value)
	{
		glUniform4ui(m_CurrentVariable->ID, value.x, value.y, value.z, value.w);
	}
	void OGLShader::load(bool value)
	{
		glUniform1i(m_CurrentVariable->ID, boolToInt(value));
	}
	void OGLShader::load(glm::bvec2& value)
	{
		glUniform2i(m_CurrentVariable->ID, boolToInt(value.x), boolToInt(value.y));
	}
	void OGLShader::load(glm::bvec3& value)
	{
		glUniform3i(m_CurrentVariable->ID, boolToInt(value.x), boolToInt(value.y), boolToInt(value.z));
	}
	void OGLShader::load(glm::bvec4& value)
	{
		glUniform4i(m_CurrentVariable->ID, boolToInt(value.x), boolToInt(value.y), boolToInt(value.z), boolToInt(value.w));
	}

	void OGLShader::load(glm::mat2x2& value)
	{
		glUniformMatrix2fv(m_CurrentVariable->ID, 1, GL_FALSE, glm::value_ptr(value));
	}
	void OGLShader::load(glm::mat3x3& value)
	{
		glUniformMatrix3fv(m_CurrentVariable->ID, 1, GL_FALSE, glm::value_ptr(value));
	}
	void OGLShader::load(glm::mat4x4& value)
	{
		glUniformMatrix4fv(m_CurrentVariable->ID, 1, GL_FALSE, glm::value_ptr(value));
	}
	void OGLShader::load(glm::dmat2x2& value)
	{
		glUniformMatrix2dv(m_CurrentVariable->ID, 1, GL_FALSE, glm::value_ptr(value));
	}
	void OGLShader::load(glm::dmat3x3& value)
	{
		glUniformMatrix3dv(m_CurrentVariable->ID, 1, GL_FALSE, glm::value_ptr(value));
	}
	void OGLShader::load(glm::dmat4x4& value)
	{
		glUniformMatrix4dv(m_CurrentVariable->ID, 1, GL_FALSE, glm::value_ptr(value));
	}
}
