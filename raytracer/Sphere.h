//
//  Sphere.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__Sphere__
#define __raytracer__Sphere__

#include "Thing.h"
#include "Vector.h"

struct Sphere : public Thing {
	float radius2;
	Vector center;
	Sphere(const Vector & center, float radius, const Surface & surface);
	
	virtual Vector normal(const Vector & pos) const;
	
	virtual std::unique_ptr<Intersection> intersect(const Ray & ray) const;

};

#endif /* defined(__raytracer__Sphere__) */
