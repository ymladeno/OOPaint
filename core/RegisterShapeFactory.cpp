/*
 * RegisterShapeFactory.cpp
 *
 *  Created on: 21 Mar 2018
 *      Author: osboxes
 */

#include "../core/RegisterShapeFactory.hpp"
#include "../core/SmoothMove.hpp"

std::shared_ptr<Shape> RegisterShapeFactory::createShape(const std::string& name, const Coord2D& coordinates, const std::string& params) {

	std::shared_ptr<Shape> shape = shapeConstructor.at(name)(coordinates, params);

	shape->setMoveStrategy(new SmoothMove());
	shape->setColor({0xff, 0xff, 0xff, 0xff});	// FIXME: hardcoded

	return shape;
}

void RegisterShapeFactory::registerShapes(const std::string& name, ShapeConstructor constructor) {
	shapeConstructor[name] = constructor;
}
