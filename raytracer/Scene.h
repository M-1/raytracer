//
//  Scene.h
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#ifndef __raytracer__Scene__
#define __raytracer__Scene__

#include <vector>
#include <memory>

#include "Thing.h"
#include "Light.h"
#include "Camera.h"


struct Scene {
	std::vector<std::unique_ptr<Thing>> things;
	std::vector<std::unique_ptr<Light>> lights;
	Camera camera;
	
	Scene(std::vector<std::unique_ptr<Thing>> && things, std::vector<std::unique_ptr<Light>> && lights, Camera && camera);
	
};

#endif /* defined(__raytracer__Scene__) */
