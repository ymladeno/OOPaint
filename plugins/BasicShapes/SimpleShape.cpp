/*
 * SimpleShape.cpp
 *
 *  Created on: 20 Mar 2018
 *      Author: osboxes
 */

#include "SimpleShape.hpp"

SimpleShape::SimpleShape(const Coord2D& coordinates)
: coordinates(coordinates),
  moveStrategy(nullptr) {
}

SimpleShape::~SimpleShape() {
	delete moveStrategy;
}

void SimpleShape::setColor(const SDL_Color& color) {
	this->color = color;
}

const SDL_Color& SimpleShape::getColor() const {
	return color;
}

void SimpleShape::setMoveStrategy(MoveStrategy* movestrategy) {
	this->moveStrategy = movestrategy;
}

void SimpleShape::moveBy(const Coord2D& deltaCoord) {
	assert(nullptr != moveStrategy);
	coordinates = moveStrategy->move(coordinates, deltaCoord);
}

void SimpleShape::resize(double factor, const Coord2D& center) {
	auto delta = coordinates - center;
	delta *= factor;
	coordinates = center + delta;

	resizeSpecific(factor);
}

std::set<std::shared_ptr<Shape>> SimpleShape::getChildren() const {
	std::set<std::shared_ptr<Shape>> empty;
	return empty;
}
