#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Madness {
	class Program {
	public:
		void Use();
		void Delete();
		static const Program& Create(const unsigned int vertexShaderId, const unsigned int fragmentShaderId);

	private:
		Program(const unsigned int vertexShaderId, const unsigned int fragmentShaderId);

	private:
		unsigned int m_programId;
		unsigned int m_vertexShaderId;
		unsigned int m_fragmentShaderId;
	};
}