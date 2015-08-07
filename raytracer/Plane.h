//
//  Plane.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__Plane__
#define __raytracer__Plane__

#include "Thing.h"
#include "Vector.h"

struct Plane : public Thing {
	Vector norm;
	float offset;
	
	Plane(const Vector & norm, float offset, const Surface & surface);
	
	virtual Vector normal(const Vector & pos) const;
	virtual std::unique_ptr<Intersection> intersect(const Ray & ray) const;
};

#endif /* defined(__raytracer__Plane__) */
