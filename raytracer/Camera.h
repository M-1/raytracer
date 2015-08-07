//
//  Camera.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__Camera__
#define __raytracer__Camera__

#include "Vector.h"

struct Camera {
	Camera(const Vector & pos, const Vector & lookAt);

	Vector forward, right, up;
	Vector pos;
};

#endif /* defined(__raytracer__Camera__) */
