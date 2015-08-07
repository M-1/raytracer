//
//  Thing.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__Thing__
#define __raytracer__Thing__

#include <memory>

struct Intersection;
struct Ray;
struct Vector;
struct Surface;

struct Thing {
	// these member functions need to return an interface (usage of pointer/reference is necessary for polymorphism) -> used unique_ptr for automatic freeing
	virtual std::unique_ptr<Intersection> intersect(const Ray & ray) const = 0;
	virtual Vector normal(const Vector & pos) const = 0;
	
	explicit Thing(const Surface & surface);
	const Surface & surface;

	virtual ~Thing();
};

#endif /* defined(__raytracer__Thing__) */
