//
//  Color.cpp
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#include "Color.h"

#include <algorithm>

#include "DrawingColor.h"

Color::Color(float r, float g, float b) : r(r), g(g), b(b) {
}

Color Color::scale(float k, const Color & v) {
	return Color(k * v.r, k * v.g, k * v.b);
}

Color Color::plus(const Color & v1, const Color & v2) {
	return Color(v1.r + v2.r, v1.g + v2.g, v1.b + v2.b);
}

Color Color::times(const Color & v1, const Color & v2) {
	return Color(v1.r * v2.r, v1.g * v2.g, v1.b * v2.b);
}

Color Color::white = Color(1.0, 1.0, 1.0);
Color Color::grey = Color(0.5, 0.5, 0.5);
Color Color::black = Color(0.0, 0.0, 0.0);
Color Color::background = Color::black;
Color Color::defaultColor = Color::black;

DrawingColor Color::toDrawingColor(const Color & c) {
	static float max = 1.0;
	return DrawingColor(std::min(c.r, max) * 255,
						std::min(c.g, max) * 255,
						std::min(c.b, max) * 255);
}
