//
//  Surfaces.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__Surfaces__
#define __raytracer__Surfaces__

#include <memory>

#include "Surface.h"

namespace Surfaces {
	
	struct ShinySurface : public Surface {
		ShinySurface();
		
		virtual Color diffuse(const Vector & pos) const;
		virtual Color specular(const Vector & pos) const;
		virtual float reflect(const Vector & pos) const;
	};
	
	struct CheckerboardSurface : public Surface {
		CheckerboardSurface();
		
		virtual Color diffuse(const Vector & pos) const;
		virtual Color specular(const Vector & pos) const;
		virtual float reflect(const Vector & pos) const;
	};
	
	// Implemented as getters
	const Surface & shiny();
	const Surface & checkerboard();
};

#endif /* defined(__raytracer__Surfaces__) */
