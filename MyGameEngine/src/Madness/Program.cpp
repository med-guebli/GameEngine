#include "Madness/program.h"

namespace Madness {

	Program::Program(const unsigned int vertexShaderId, const unsigned int fragmentShaderId) {
		this->m_vertexShaderId = vertexShaderId;
		this->m_fragmentShaderId = fragmentShaderId;

		this->m_programId = glCreateProgram();

		glAttachShader(this->m_programId, this->m_vertexShaderId);
		glAttachShader(this->m_programId, this->m_fragmentShaderId);
		glLinkProgram(this->m_programId);
	}

	void Program::Use()
	{
		glUseProgram(this->m_programId);
	}

	void Program::Delete()
	{
		glDetachShader(this->m_programId, this->m_vertexShaderId);
		glDeleteShader(this->m_vertexShaderId);

		glDetachShader(this->m_programId, this->m_fragmentShaderId);
		glDeleteShader(this->m_fragmentShaderId);

		glDeleteProgram(this->m_programId);
	}

	const Program& Program::Create(const unsigned int vertexShaderId, const unsigned int fragmentShaderId)
	{
		return Program(vertexShaderId, fragmentShaderId);
	}
}