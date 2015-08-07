//
//  Drawing.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__Drawing__
#define __raytracer__Drawing__

#include <cstdint>
#include <vector>
#include <string>
#include <fstream>

#include "DrawingColor.h"

class Drawing {
public:
	typedef std::uint_fast16_t dim_t;

	Drawing(dim_t size_x, dim_t size_y);
	
private:
	dim_t size_x, size_y;
	std::vector<DrawingColor> canvas;
	
	DrawingColor & get_pixel(dim_t x, dim_t y);
	
public:
	dim_t width();
	dim_t height();
	
	void draw(dim_t x, dim_t y, const DrawingColor & color);
	
	void save_ppm(const std::string & fname);
};

#endif /* defined(__raytracer__Drawing__) */
