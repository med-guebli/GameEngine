#include "Madness/VertexBuffer.h"

namespace Madness {
	VertexBuffer::VertexBuffer(const std::vector<Vec>& vertices, const unsigned int location, const unsigned int type, const unsigned int usage, const unsigned int normalized) :
		m_location(location),
		m_type(type),
		m_usage(usage),
		m_normalized(normalized)
	
	{
		this->m_vertices = vertices;
	}

	const unsigned int VertexBuffer::GetLocation() const
	{
		return this->m_location;
	}

	const unsigned int VertexBuffer::GetType() const
	{
		return this->m_type;
	}

	const unsigned int VertexBuffer::GetUsage() const
	{
		return this->m_usage;
	}

	std::vector<Madness::Vec>& VertexBuffer::GetVertices()
	{
		return this->m_vertices;
	}

	const unsigned int VertexBuffer::GetNormalized() const
	{
		return this->m_normalized;
	}
}