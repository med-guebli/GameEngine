#pragma once

#include <string>

namespace Madness {
	class Shader {

	public:
		Shader(const std::string& filename, const unsigned int shaderType);
		void Init();
		unsigned int CreateShader();
		void DeleteShader(const unsigned int shaderId);

	private:
		const std::string& m_filename;
		const unsigned int m_shaderType;
		std::string m_shaderSource;
	};
}