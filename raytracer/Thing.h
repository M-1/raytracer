//
//  Thing.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__Thing__
#define __raytracer__Thing__

#include <utility>

struct Intersection;
struct Ray;
struct Vector;
struct Surface;

struct Thing {
	virtual std::pair<bool, Intersection> intersect(const Ray & ray) const = 0; // TODO: use optional<Intersection> instead
	virtual Vector normal(const Vector & pos) const = 0;
	
	explicit Thing(const Surface & surface);
	const Surface & surface;

	virtual ~Thing();
};

#endif /* defined(__raytracer__Thing__) */
