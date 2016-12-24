#pragma once
#include "../../../preprocessor.h"
#include "../shaderProgram.h"
#include <GL/glew.h>
#include <vector>

namespace reboot_kernel_opengl
{
	class REBOOT_API ShaderProgram :public reboot_kernel::ShaderProgram
	{
	private:
		std::vector<unsigned> m_ShaderFileID;
		unsigned static build(GLuint type, const char* shader);
	public:
        ShaderProgram() :reboot_kernel::ShaderProgram(){}
		~ShaderProgram() override;
		bool addShader(short type, const char* shader) override;
		void getUniforms() override;
		void start() override;
		void getAttributes() override;
		void bind() override;
		void unbind() override;
		void load(float value) override;
		void load(glm::vec2& value) override;
		void load(glm::vec3& value) override;
		void load(glm::vec4& value) override;
		void load(double value) override;
		void load(glm::dvec2& value) override;
		void load(glm::dvec3& value) override;
		void load(glm::dvec4& value) override;
		void load(int value) override;
		void load(glm::ivec2& value) override;
		void load(glm::ivec3& value) override;
		void load(glm::ivec4& value) override;
		void load(unsigned value) override;
		void load(glm::uvec2& value) override;
		void load(glm::uvec3& value) override;
		void load(glm::uvec4& value) override;
		void load(bool value) override;
		void load(glm::bvec2& value) override;
		void load(glm::bvec3& value) override;
		void load(glm::bvec4& value) override;
		void load(glm::mat2x2& value) override;
		void load(glm::mat3x3& value) override;
		void load(glm::mat4x4& value) override;
		void load(glm::dmat2x2& value) override;
		void load(glm::dmat3x3& value) override;
		void load(glm::dmat4x4& value) override;
	};
}
