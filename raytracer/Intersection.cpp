//
//  Intersection.cpp
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#include "Intersection.h"

Intersection::Intersection() : thing(nullptr), ray(nullptr) {
}

Intersection::Intersection(const Thing & thing, const Ray & ray, float dist) : thing(&thing), ray(&ray), dist(dist) {
}