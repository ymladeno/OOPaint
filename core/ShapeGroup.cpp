/*
 * ShapeGroup.cpp
 *
 *  Created on: 20 Mar 2018
 *      Author: osboxes
 */

#include "../core/ShapeGroup.hpp"

ShapeGroup::ShapeGroup()
: group() {

}


void ShapeGroup::setColor(const SDL_Color& color) {
	for(auto shape : group) {
		shape->setColor(color);
	}
}

void ShapeGroup::draw(SDL_Renderer* renderer) const {
	for(auto shape : group) {
		shape->draw(renderer);
	}
}

void ShapeGroup::resize(double factor, const Coord2D& center) {
	for(auto shape : group) {
		shape->resize(factor, center);
	}
}

bool ShapeGroup::containsCoordinates(const Coord2D& coord) const {
	for(auto shape : group) {
		if (shape->containsCoordinates(coord)) {
			return true;
		}
	}
	return false;
}

void ShapeGroup::setMoveStrategy(MoveStrategy* movestrategy) {
	for(auto shape : group) {
		shape->setMoveStrategy(movestrategy);
	}
}


void ShapeGroup::moveBy(const Coord2D& deltaCoord) {
	for(auto shape : group) {
		shape->moveBy(deltaCoord);
	}
}

void ShapeGroup::add(std::shared_ptr<Shape> shape) {
	group.insert(shape);
}

void ShapeGroup::remove(std::shared_ptr<Shape> shape) {
	size_t s = group.erase(shape);
}

void ShapeGroup::removeall() {
	group.clear();
}

std::set<std::shared_ptr<Shape>>::iterator ShapeGroup::begin() const {
	return group.begin();
}

std::set<std::shared_ptr<Shape>>::iterator ShapeGroup::end() const {
	return group.end();
}
