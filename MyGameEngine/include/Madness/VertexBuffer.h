#pragma once

#include <vector>
#include "Madness/Vec.h"

namespace Madness {
	class VertexBuffer {
	public:
		VertexBuffer(const std::vector<Vec>& vertices, const unsigned int location, const unsigned int type, const unsigned int usage, const unsigned int normalized);

		const unsigned int GetLocation() const;
		const unsigned int GetType() const;
		const unsigned int GetUsage() const;
		const unsigned int GetNormalized() const;

		std::vector<Madness::Vec>& GetVertices();

	private:
		const unsigned int m_location, m_type, m_usage, m_normalized;
		std::vector<Madness::Vec> m_vertices;
	};
}
