//
//  Scene.cpp
//  raytracer
//
//  Created by a on 07/08/15.
//  Copyright (c) 2015 Martin Mi. All rights reserved.
//

#include "Scene.h"

#include "Thing.h"
#include "Light.h"

Scene::Scene(std::vector<std::unique_ptr<Thing>> && things, std::vector<std::unique_ptr<Light>> && lights, Camera && camera) : things(std::move(things)), lights(std::move(lights)), camera(std::move(camera)) {
}