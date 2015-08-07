//
//  Sphere.cpp
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#include "Sphere.h"

#include <cmath>

#include "Ray.h"
#include "Intersection.h"

Sphere::Sphere(const Vector & center, float radius, const Surface & surface) : Thing(surface), center(center), radius2(radius * radius) {
}

Vector Sphere::normal(const Vector & pos) const {
	return Vector::norm(Vector::minus(pos, center));
}

std::unique_ptr<Intersection> Sphere::intersect(const Ray & ray) const {
	auto eo = Vector::minus(center, ray.start);
	auto v = Vector::dot(eo, ray.dir);
	auto dist = 0;
	if (v >= 0) {
		auto disc = radius2 - (Vector::dot(eo, eo) - v * v);
		if (disc >= 0) {
			dist = v - std::sqrt(disc);
		}
	}
	if (dist == 0) {
		return nullptr;
	} else {
		return std::unique_ptr<Intersection>(new Intersection(*this, ray, dist));
	}
}
