#include "Madness/triangle.h";

namespace Madness {

	Triangle::Triangle() {
		this->m_vertices = std::vector<Vec>(3);
		this->m_colors.push_back(Vec(0.5f, 0.1f, 0.9f, 1.0f));
		this->m_colors.push_back(Vec(0.5f, 0.1f, 0.9f, 1.0f));
		this->m_colors.push_back(Vec(0.5f, 0.1f, 0.9f, 1.0f));
	}

	Madness::Vec& Triangle::GetA() {
		return this->m_vertices[0];
	}

	Madness::Vec& Triangle::SetA(Madness::Vec vec) {
		this->m_vertices[0] = vec;

		return this->m_vertices[0];
	}

	Madness::Vec& Triangle::GetB() {
		return this->m_vertices[1];
	}

	Madness::Vec& Triangle::SetB(Madness::Vec vec) {
		this->m_vertices[1] = vec;

		return this->m_vertices[1];
	}

	Madness::Vec& Triangle::GetC() {
		return this->m_vertices[2];
	}

	Madness::Vec& Triangle::SetC(Madness::Vec vec) {
		this->m_vertices[2] = vec;

		return this->m_vertices[2];
	}

	void Triangle::SetColor(Vec vec)
	{
		this->m_colors[0] = vec;
		this->m_colors[1] = vec;
		this->m_colors[2] = vec;
	}

	std::vector<Madness::Vec>& Triangle::GetVertices() {
		return this->m_vertices;
	}

	std::vector<Madness::Vec>& Triangle::GetColors() {
		return this->m_colors;
	}
}