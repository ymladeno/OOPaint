/*
 * ShapeRegistry.hpp
 *
 *  Created on: 22 Mar 2018
 *      Author: osboxes
 */

#ifndef INC_SHAPEREGISTRY_HPP_
#define INC_SHAPEREGISTRY_HPP_

#include <string>
#include <functional>
#include <memory>
#include "Shape.hpp"

typedef std::function<std::shared_ptr<Shape>(const Coord2D& coordinates, const std::string& params)> ShapeConstructor;

class ShapeRegistry {
public:
	virtual ~ShapeRegistry() = default;
	virtual void registerShapes(const std::string& name, ShapeConstructor constructor) = 0;
};

#endif /* INC_SHAPEREGISTRY_HPP_ */
