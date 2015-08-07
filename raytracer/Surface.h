//
//  Surface.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__Surface__
#define __raytracer__Surface__

#include "Color.h"
#include "Vector.h"

struct Surface {
	virtual Color diffuse(const Vector & pos) const = 0;
	virtual Color specular(const Vector & pos) const = 0;
	virtual float reflect(const Vector & pos) const = 0;
	
	explicit Surface(float roughness);
	float roughness;
	
	virtual ~Surface();
};

#endif /* defined(__raytracer__Surface__) */
