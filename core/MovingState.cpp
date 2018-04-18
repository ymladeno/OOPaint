/*
 * MovingState.cpp
 *
 *  Created on: 23 Mar 2018
 *      Author: osboxes
 */

#include <iostream>
#include "MovingState.hpp"
#include "IdleState.hpp"

MovingState::MovingState(Canvas& canvas, Factory& factory, std::shared_ptr<Shape> shape)
: UIState(canvas, factory), shape(shape) {
	if (nullptr == shape) {
		throw std::runtime_error("Null pointer");
	}
}

MovingState::~MovingState() {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void MovingState::onMouseLeftBtnUp() {
	changeTo(std::make_shared<IdleState>(canvas, factory));
}

void MovingState::onMouseMotion(const Coord2D& coords) {
	shape->moveBy(coords);
}
