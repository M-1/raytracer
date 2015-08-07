//
//  Plane.cpp
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#include "Plane.h"

#include "Ray.h"
#include "Intersection.h"

Plane::Plane(const Vector & norm, float offset, const Surface & surface) : Thing(surface), norm(norm), offset(offset) {
}

Vector Plane::normal(const Vector & pos) const {
	return norm;
}

std::pair<bool, Intersection> Plane::intersect(const Ray & ray) const {
	auto denom = Vector::dot(norm, ray.dir);
	if (denom > 0) {
		return std::make_pair(false, Intersection());
	} else {
		auto dist = (Vector::dot(norm, ray.start) + offset) / (-denom);
		return std::make_pair(true, Intersection(*this, ray, dist));
	}
}