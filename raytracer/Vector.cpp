//
//  Vector.cpp
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#include "Vector.h"

#include <cmath>
#include <limits>

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {
}

Vector Vector::times(float k, const Vector & v) {
	return Vector(k * v.x, k * v.y, k * v.z);
}

Vector Vector::minus(const Vector & v1, const Vector & v2) {
	return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector Vector::plus(const Vector & v1, const Vector & v2) {
	return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

float Vector::dot(const Vector & v1, const Vector & v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float Vector::mag(const Vector & v) {
	return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector Vector::norm(const Vector & v) {
	float mag = Vector::mag(v);
	float div = (mag == 0) ? std::numeric_limits<float>::infinity() : 1.0 / mag;
	return Vector::times(div, v);
}

Vector Vector::cross(const Vector & v1, const Vector & v2) {
	return Vector(v1.y * v2.z - v1.z * v2.y,
				  v1.z * v2.x - v1.x * v2.z,
				  v1.x * v2.y - v1.y * v2.x);
}