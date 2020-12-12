#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Madness/shader.h"
#include <fstream>
#include <sstream>

namespace Madness {
	Shader::Shader(const std::string& filename, const unsigned int shaderType): m_filename(filename), m_shaderType(shaderType) {
	}

	void Shader::Init()
	{
		std::ifstream stream(this->m_filename);
		std::stringstream shaderSource;

		if (stream.is_open()) {

			shaderSource << stream.rdbuf();

			stream.close();
		}

		this->m_shaderSource = shaderSource.str();
	}

	unsigned int Shader::CreateShader() {
		GLuint id = glCreateShader(this->m_shaderType);
		const char* src = this->m_shaderSource.c_str();
		glShaderSource(id, 1, &src, NULL);
		glCompileShader(id);

		return id;
	}

	void Shader::DeleteShader(const unsigned int shaderId) {
		glDeleteShader(shaderId);
	}
}