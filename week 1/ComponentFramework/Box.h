#pragma once
#include "Shape.h"
#include <Vector.h>

namespace GEOMETRY {


	struct Box : public Shape {

		float halfSideLength = 1.0f;
		MATH::Vec3 centerPos;

		Box() {
			set(1.0f, MATH::Vec3(0.0f, 0.0f, 0.0f));
		}

		Box(float halfSideLength_, MATH::Vec3 centerPos_) {
			set(halfSideLength_, centerPos_);
		}

		void set(float halfSideLength_, MATH::Vec3 centerPos_) {
			halfSideLength = halfSideLength_;
			centerPos = centerPos_;
		}

		void generateVerticesAndNormals() override;
	};
}

