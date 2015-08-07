//
//  Ray.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__Ray__
#define __raytracer__Ray__

#include "Vector.h"

struct Ray {
	Ray(const Vector & start, const Vector & dir);
	Vector start;
	Vector dir;
	
};

#endif /* defined(__raytracer__Ray__) */
