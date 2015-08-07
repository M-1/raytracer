//
//  Light.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__Light__
#define __raytracer__Light__

#include "Vector.h"
#include "Color.h"


struct Light {
	Vector pos;
	Color color;
	
	Light(const Vector & pos, const Color & color);
	
};

#endif /* defined(__raytracer__Light__) */
