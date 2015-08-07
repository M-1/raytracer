//
//  RayTracer.cpp
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#include "RayTracer.h"

#include <limits>
#include <cmath>

#include "Camera.h"
#include "Ray.h"
#include "Scene.h"
#include "Intersection.h"
#include "Surface.h"

std::unique_ptr<Intersection> RayTracer::intersections(const Ray & ray, const Scene & scene) {
	auto closest = std::numeric_limits<float>::infinity();
	std::unique_ptr<Intersection> closestInter;
	for (auto & thing_ptr : scene.things) {
		auto inter = thing_ptr->intersect(ray);
		if (inter != nullptr && inter->dist < closest) {
			closest = inter->dist;
			closestInter = std::move(inter);
		}
	}
	return closestInter;
}

float RayTracer::testRay(const Ray & ray, const Scene & scene) {
	auto isect = intersections(ray, scene);
	if (isect != nullptr) {
		return isect->dist;
	} else {
		return std::numeric_limits<float>::infinity();
	}
}

Color RayTracer::traceRay(const Ray & ray, const Scene & scene, depth_t depth) {
	auto isect = intersections(ray, scene);
	if (isect == nullptr) {
		return Color::background;
	} else {
		return shade(*isect, scene, depth);
	}
}

Color RayTracer::shade(const Intersection & isect, const Scene & scene, depth_t depth) {
	auto d = isect.ray.dir;
	auto pos = Vector::plus(Vector::times(isect.dist, d), isect.ray.start);
	auto normal = isect.thing.normal(pos);
	auto reflectDir = Vector::minus(d, Vector::times(2, Vector::times(Vector::dot(normal, d), normal)));
	auto naturalColor = Color::plus(Color::background,
									getNaturalColor(isect.thing, pos, normal, reflectDir, scene));
	auto reflectedColor = (depth >= maxDepth) ? Color::grey : getReflectionColor(isect.thing, pos, normal, reflectDir, scene, depth);
	return Color::plus(naturalColor, reflectedColor);
}

Color RayTracer::getReflectionColor(const Thing & thing, const Vector & pos, const Vector & normal, const Vector & rd, const Scene & scene, depth_t depth) {
	return Color::scale(thing.surface.reflect(pos), traceRay(Ray(pos, rd), scene, depth + 1));
}

Color RayTracer::getNaturalColor(const Thing & thing, const Vector & pos, const Vector & norm, const Vector & rd, const Scene & scene) {
	
	Color resulting_color = Color::defaultColor;
	
	for (auto & light_ptr : scene.lights) {
		Light & light = *light_ptr;
		
		Vector ldis = Vector::minus(light.pos, pos);
		Vector livec = Vector::norm(ldis);
		float neatIsect = testRay(Ray(pos, livec), scene);
		
		bool isInShadow = (neatIsect == std::numeric_limits<float>::infinity()) ? false : (neatIsect <= Vector::mag(ldis));
		if (isInShadow) {
			continue;
		} else {
			auto illum = Vector::dot(livec, norm);
			auto lcolor = (illum > 0) ? Color::scale(illum, light.color) : Color::defaultColor;
			auto specular = Vector::dot(livec, Vector::norm(rd));
			auto scolor = (specular > 0) ? Color::scale(std::pow(specular, thing.surface.roughness), light.color) : Color::defaultColor;
			resulting_color = Color::plus(resulting_color,
										  Color::plus(Color::times(thing.surface.diffuse(pos), lcolor),
													  Color::times(thing.surface.specular(pos), scolor)));
		}
		
	}
	
	return resulting_color;
}

Vector RayTracer::getPoint(Drawing::dim_t x, Drawing::dim_t y, Drawing::dim_t screenWidth, Drawing::dim_t screenHeight, const Camera & camera) {
	auto recenteredX = (x - (screenWidth / 2.0)) / 2.0 / screenWidth;
	auto recenteredY = -(y - (screenHeight / 2.0)) / 2.0 / screenHeight;
	return Vector::norm(Vector::plus(camera.forward, Vector::plus(Vector::times(recenteredX, camera.right), Vector::times(recenteredY, camera.up))));

}

void RayTracer::render(const Scene & scene, Drawing & ctx, Drawing::dim_t screenWidth, Drawing::dim_t screenHeight) {
	if (screenWidth == 0) {
		screenWidth = ctx.width();
	}
	
	if (screenHeight == 0) {
		screenHeight = ctx.height();
	}
	
	
	for (Drawing::dim_t y = 0; y < screenHeight; y++) {
		for (Drawing::dim_t x = 0; x < screenWidth; x++) {
			auto color = traceRay(Ray(scene.camera.pos, getPoint(x, y, screenWidth, screenHeight, scene.camera)), scene, 0);
			auto c = Color::toDrawingColor(color);
			ctx.draw(x, y, c);
		}
	}

}