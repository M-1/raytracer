//
//  Drawing.cpp
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#include "Drawing.h"

Drawing::Drawing(dim_t size_x, dim_t size_y) : size_x(size_x), size_y(size_y), canvas(size_x * size_y, DrawingColor(0, 0, 0)) {
}

DrawingColor & Drawing::get_pixel(dim_t x, dim_t y) {
	// TODO: range check?
	return canvas[size_x * y + x];
}

Drawing::dim_t Drawing::width() {
	return size_x;
}

Drawing::dim_t Drawing::height() {
	return size_y;
}

void Drawing::draw(dim_t x, dim_t y, const DrawingColor & color) {
	get_pixel(x, y) = color;
}

void Drawing::save_ppm(const std::string & out_file_name) {
	// code adapted from http://rosettacode.org/wiki/Bitmap/Write_a_PPM_file#C
	std::ofstream out(out_file_name, std::ios::binary);
	
	// Print the header
	out << "P6\n" << size_x << " " << size_y << "\n255\n";
	
	for (dim_t y = 0; y < size_y; ++y) {
		for (dim_t x = 0; x < size_x; ++x) {
			// TODO: foreach instead - no need to
			DrawingColor & pix = get_pixel(x, y);
			
			out.put(pix.r);
			out.put(pix.g);
			out.put(pix.b);
		}
	}
	
	out.close();
}