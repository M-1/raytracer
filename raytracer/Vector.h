//
//  Vector.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__Vector__
#define __raytracer__Vector__

struct Vector {
	Vector(float x, float y, float z);
	float x, y, z;
	
	static Vector times(float k, const Vector & v);
	static Vector minus(const Vector & v1, const Vector & v2);
	static Vector plus(const Vector & v1, const Vector & v2);
	static float dot(const Vector & v1, const Vector & v2);
	static float mag(const Vector & v);
	static Vector norm(const Vector & v);
	static Vector cross(const Vector & v1, const Vector & v2);
};

#endif /* defined(__raytracer__Vector__) */
