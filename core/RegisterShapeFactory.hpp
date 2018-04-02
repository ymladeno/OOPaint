/*
 * RegisterShapeFactory.hpp
 *
 *  Created on: 21 Mar 2018
 *      Author: osboxes
 */

#ifndef CORE_REGISTERSHAPEFACTORY_HPP_
#define CORE_REGISTERSHAPEFACTORY_HPP_

#include <map>
#include "../inc/ShapeRegistry.hpp"
#include "Factory.hpp"

class RegisterShapeFactory: public Factory, public ShapeRegistry {
public:
	std::shared_ptr<Shape> createShape(const std::string& name, const Coord2D& coordinates, const std::string& params) override;
	void registerShapes(const std::string& name, ShapeConstructor constructor);

private:
	std::map<std::string, ShapeConstructor> shapeConstructor;
};

#endif /* CORE_REGISTERSHAPEFACTORY_HPP_ */
