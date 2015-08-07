//
//  DrawingColor.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__DrawingColor__
#define __raytracer__DrawingColor__

struct DrawingColor {
	// TODO: uint8_t instead of char?
	DrawingColor(char r, char g, char b);
	char r, g, b;
};

#endif /* defined(__raytracer__DrawingColor__) */
