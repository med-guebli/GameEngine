#pragma once

namespace Madness {
	struct Vec {
		float x, y, z, w;

	public:
		Vec() {
			this->x = 0.0f;
			this->y = 0.0f;
			this->z = 0.0f;
			this->w = 0.0f;
		}

		Vec(float x, float y) {
			this->x = x;
			this->y = y;
			this->z = 0.0f;
			this->w = 1.0f;
		}

		Vec(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = 1.0f;
		}

		Vec(float x, float y, float z, float w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}
	};
}