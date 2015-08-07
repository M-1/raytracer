//
//  Surfaces.cpp
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#include "Surfaces.h"

#include <memory>
#include <cmath>

namespace Surfaces {
	
	ShinySurface::ShinySurface() : Surface(250) {};
	Color ShinySurface::diffuse(const Vector & pos) const {
		return Color::white;
	}
	Color ShinySurface::specular(const Vector & pos) const {
		return Color::grey;
	}
	float ShinySurface::reflect(const Vector & pos) const {
		return 0.7;
	}
	
	
	CheckerboardSurface::CheckerboardSurface() : Surface(150) {};
	Color CheckerboardSurface::diffuse(const Vector & pos) const {
		if (int(std::floor(pos.z) + std::floor(pos.x)) % 2 != 0) {
			return Color::white;
		} else {
			return Color::black;
		}
	}
	Color CheckerboardSurface::specular(const Vector & pos) const {
		return Color::white;
	}
	float CheckerboardSurface::reflect(const Vector & pos) const {
		if (int(std::floor(pos.z) + std::floor(pos.x)) % 2 != 0) {
			return 0.1;
		} else {
			return 0.7;
		}
	}
	
	
	const Surface & shiny() {
		static const std::unique_ptr<Surface> surf(new ShinySurface);
		
		return *surf;
	}
	
	const Surface & checkerboard() {
		static const std::unique_ptr<Surface> surf(new CheckerboardSurface);
		
		return *surf;
	}
}