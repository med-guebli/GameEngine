#pragma once

#include "Shape.h";

namespace Madness {
	class Triangle : public Shape {
	public:
		Triangle();

		Vec& GetA();
		Vec& SetA(Vec vec);

		Vec& GetB();
		Vec& SetB(Vec vec);

		Vec& GetC();
		Vec& SetC(Vec vec);

		void SetColor(Vec vec);

		std::vector<Vec>& Shape::GetVertices();
		std::vector<Vec>& Shape::GetColors();
	private:
		std::vector<Vec> m_vertices;
		std::vector<Vec> m_colors;
	};
}