//
//  Camera.cpp
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#include "Camera.h"

Camera::Camera(const Vector & pos, const Vector & lookAt) :
pos(pos),
forward(Vector::norm(Vector::minus(lookAt, pos))),
right(Vector::times(1.5, Vector::norm(Vector::cross(forward, /* down: */Vector(0.0, -1.0, 0.0))))),
up (Vector::times(1.5, Vector::norm(Vector::cross(forward, right))))
{
}