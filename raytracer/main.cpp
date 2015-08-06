//
//  main.cpp
//  raytracer
//
//  Created by a on 06/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#include <iostream>
#include <fstream>

//! Type for usage as dimensions/coordinates
typedef std::uint_fast16_t dim_t;

int main(int argc, const char * argv[]) {
	// code adapted from http://rosettacode.org/wiki/Bitmap/Write_a_PPM_file#C
	dim_t size_x = 320, size_y = 240;
	std::string out_file = "out.ppm";
	
	std::ofstream out(out_file, std::ios::binary);
	
	// Print the header
	out << "P6\n" << size_x << " " << size_y << "\n255\n";
	
	for (dim_t y = 0; y < size_y; ++y) {
		for (dim_t x = 0; x < size_x; ++x) {
			static char color[3];
			color[0] = x % 256; // red
			color[1] = y % 256; // green
			color[2] = (x * y) % 256; // blue
			out.write(&color[0], 3);
		}
	}
	
	out.close();
	
    return 0;
}
