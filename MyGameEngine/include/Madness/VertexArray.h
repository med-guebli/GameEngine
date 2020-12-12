#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Madness/VertexBuffer.h"

namespace Madness {

	class VertexArray {
	public:
		VertexArray();

		void Add(const VertexBuffer& buffer);
		void Bind();
		void Unbind();

	private:
		unsigned int m_vao;

		std::vector<unsigned int> m_vbos;
		std::vector<VertexBuffer> m_buffers;
	};
}