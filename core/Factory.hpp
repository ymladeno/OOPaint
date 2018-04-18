/*
 * Factory.hpp
 *
 *  Created on: 21 Mar 2018
 *      Author: osboxes
 */

#ifndef CORE_FACTORY_HPP_
#define CORE_FACTORY_HPP_

#include <string>
#include <memory>
#include "Shape.hpp"

class Factory {
public:
	virtual ~Factory() = default;
	virtual std::shared_ptr<Shape> createShape(const std::string& name, const Coord2D& coordinates, const std::string& params) = 0;
};

#endif /* CORE_FACTORY_HPP_ */
