#pragma once

#include "Madness/VertexArray.h"

namespace Madness {

	VertexArray::VertexArray() :
		m_vao(0)
	{
	}

	void VertexArray::Add(const VertexBuffer& buffer) {
		this->m_buffers.push_back(buffer);
	}

	void VertexArray::Bind()
	{
		glGenVertexArrays(1, &this->m_vao);
		glBindVertexArray(this->m_vao);

		for (size_t i = 0; i < this->m_buffers.size(); i++)
		{
			VertexBuffer buffer = this->m_buffers.at(i);

			unsigned int vbo;
			glGenBuffers(1, &vbo);
			glBindBuffer(buffer.GetType(), vbo);
			glBufferData(buffer.GetType(), sizeof(Vec) * buffer.GetVertices().size(), &buffer.GetVertices()[0], buffer.GetUsage());

			glVertexAttribPointer(buffer.GetLocation(), sizeof(float), GL_FLOAT, buffer.GetNormalized(), sizeof(Vec), (void*)0);
			glEnableVertexAttribArray(buffer.GetLocation());

			this->m_vbos.push_back(vbo);
		}
	}

	void VertexArray::Unbind()
	{
		glDeleteVertexArrays(1, &this->m_vao);

		for (size_t i = 0; i < this->m_vbos.size(); i++)
		{
			glDeleteBuffers(1, &this->m_vbos.at(i));
		}

		this->m_vbos.clear();
	}
}