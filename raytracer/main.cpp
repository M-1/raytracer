//
//  main.cpp
//  raytracer
//
//  Created by a on 06/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <memory>

#include "Drawing.h"

#include "RayTracer.h"
#include "Surfaces.h"
#include "Scene.h"
#include "Plane.h"
#include "Sphere.h"
#include "Thing.h"
#include "Light.h"

std::unique_ptr<Scene> make_scene() {
	std::vector<std::unique_ptr<Thing>> things;
	things.emplace_back(new Plane(Vector(0.0, 1.0, 0.0), 0.0, Surfaces::checkerboard()));
	things.emplace_back(new Sphere(Vector(0.0, 1.0, -0.25), 1.0, Surfaces::shiny()));
	things.emplace_back(new Sphere(Vector(-1.0, 0.5, 1.5), 0.5, Surfaces::shiny()));
	
	std::vector<std::unique_ptr<Light>> lights;
	lights.emplace_back(new Light(Vector(-2.0, 2.5, 0.0), Color(0.49, 0.07, 0.07)));
	lights.emplace_back(new Light(Vector(1.5, 2.5, 1.5), Color(0.07, 0.07, 0.49)));
	lights.emplace_back(new Light(Vector(1.5, 2.5, -1.5), Color(0.07, 0.49, 0.071)));
	lights.emplace_back(new Light(Vector(0.0, 3.5, 0.0), Color(0.21, 0.21, 0.35)));
	
	Camera camera(// Position
				  Vector(3.0, 2.0, 4.0),
				  // LookAt
				  Vector(-1.0, 0.5, 0.0));
	
	return std::unique_ptr<Scene>(new Scene(std::move(things), std::move(lights), std::move(camera)));
}

void exec() {	
	Drawing canv(512, 512);
	
	RayTracer rayTracer;
	
	std::unique_ptr<Scene> scene = make_scene();
	
	rayTracer.render(*scene, canv);
	
	canv.save_ppm("out4.ppm");
}

int main(int argc, const char * argv[]) {
	
	exec();
	
    return 0;
}
