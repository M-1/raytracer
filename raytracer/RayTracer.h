//
//  RayTracer.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__RayTracer__
#define __raytracer__RayTracer__

#include <cstdint>
#include <memory>

#include "Drawing.h"

struct Intersection;
struct Ray;
struct Scene;
struct Color;
struct Thing;
struct Vector;
struct Camera;

class RayTracer {
	typedef std::uint_fast16_t depth_t;
	
	depth_t maxDepth = 5;
	
	//! Returns first (closest) intersection
	std::pair<bool, Intersection> intersections(const Ray & ray, const Scene & scene);
	float testRay(const Ray & ray, const Scene & scene);
	Color traceRay(const Ray & ray, const Scene & scene, depth_t depth);
	Color shade(const Intersection & isect, const Scene & scene, depth_t depth);
	Color getReflectionColor(const Thing & thing, const Vector & pos, const Vector & normal, const Vector & rd, const Scene & scene, depth_t depth);
	Color getNaturalColor(const Thing & thing, const Vector & pos, const Vector & norm, const Vector & rd, const Scene & scene);
	
	static Vector getPoint(Drawing::dim_t x, Drawing::dim_t y, Drawing::dim_t screenWidth, Drawing::dim_t screenHeight, const Camera & camera);
	
public:
	void render(const Scene & scene, /* out */ Drawing & ctx, Drawing::dim_t screenWidth = 0, Drawing::dim_t screenHeight = 0);
};

#endif /* defined(__raytracer__RayTracer__) */
