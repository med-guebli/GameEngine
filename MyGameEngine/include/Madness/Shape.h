#pragma once

#include <vector>
#include "Vec.h";


namespace Madness {
	class Shape {
	public:
		virtual std::vector<Madness::Vec>& GetVertices() = 0;
		virtual std::vector<Madness::Vec>& GetColors() = 0;

	public:
		void Rotate(float angle);

		void Scale(float factor);

		void Move(const Madness::Vec& position);

		/**
			Calculates the centroide of the shape
		*/
		Madness::Vec Centroide();
	};
}