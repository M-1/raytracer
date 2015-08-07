//
//  Color.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__Color__
#define __raytracer__Color__

struct DrawingColor;

struct Color {
	Color(float r, float g, float b);
	float r, g, b;
	
	static Color scale(float k, const Color & v);
	static Color plus(const Color & v1, const Color & v2);
	static Color times(const Color & v1, const Color & v2);
	
	static Color white;
	static Color grey;
	static Color black;
	static Color background;
	static Color defaultColor;
	
	static DrawingColor toDrawingColor(const Color & c);
};
#endif /* defined(__raytracer__Color__) */
