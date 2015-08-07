//
//  Intersection.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__Intersection__
#define __raytracer__Intersection__

#include "Thing.h"
#include "Ray.h"

struct Intersection {
	Intersection();
	Intersection(const Thing & thing, const Ray & ray, float dist);
	
	// TODO: use getters to hide pointer vs reference differences in fields of different classes?
	const Thing * thing;
	const Ray * ray;
	float dist;
};

#endif /* defined(__raytracer__Intersection__) */
