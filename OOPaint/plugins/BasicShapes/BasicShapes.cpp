/*
 * BasicShapes.cpp
 *
 *  Created on: 22 Mar 2018
 *      Author: osboxes
 */

#include <iostream>
#include <memory>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "../../inc/ShapeRegistry.hpp"

extern "C" void registerMakers(ShapeRegistry& registry ) {

	std::cout << __PRETTY_FUNCTION__ << std::endl;

	registry.registerShapes("Circle", [](const Coord2D& coordinates, const std::string& params) {
		return std::make_shared<Circle>(coordinates, params);
	});

	registry.registerShapes("Rectangle", [](const Coord2D& coordinates, const std::string& params) {
		return std::make_shared<Rectangle>(coordinates, params);
	});
}
