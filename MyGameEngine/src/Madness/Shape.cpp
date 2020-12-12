#include "Madness/Shape.h";
#include "Madness/common.h"

namespace Madness {
	void Shape::Rotate(float angle) {
		std::vector<Madness::Vec>& vertices = this->GetVertices();

		const float rad = angle * Madness::Math::PI / 180;

		for (size_t i = 0; i < vertices.size(); i++)
		{
			Vec centroide = this->Centroide();
			const float rotatedX = (vertices[i].x) * cos(rad) - (vertices[i].y) * sin(rad);
			const float rotatedY = (vertices[i].y) * cos(rad) + (vertices[i].x) * sin(rad);

			vertices[i].x = rotatedX;
			vertices[i].y = rotatedY;
		}
	}

	void Shape::Scale(float factor) {
		std::vector<Madness::Vec>& vertices = this->GetVertices();

		for (size_t i = 0; i < vertices.size(); i++)
		{
			vertices[i].x *= factor;
			vertices[i].y *= factor;
		}
	}

	void Shape::Move(const Madness::Vec& position)
	{
		std::vector<Madness::Vec>& vertices = this->GetVertices();

		for (size_t i = 0; i < vertices.size(); i++)
		{
			vertices[i].x += 0.005f;
			vertices[i].y += 0.005f;
		}
	}

	Madness::Vec Shape::Centroide() {
		std::vector<Madness::Vec>& vertices = this->GetVertices();

		float x = 0, y = 0;

		for (size_t i = 0; i < vertices.size(); i++)
		{
			x += vertices[i].x;
			y += vertices[i].y;
		}

		return Vec(x / vertices.size(), y / vertices.size());
	}
}