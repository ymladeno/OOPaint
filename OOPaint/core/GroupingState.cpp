/*
 * GroupingState.cpp
 *
 *  Created on: 23 Mar 2018
 *      Author: osboxes
 */

#include "GroupingState.hpp"
#include "IdleState.hpp"
#include "MovingState.hpp"

GroupingState::GroupingState(Canvas& canvas, Factory& factory, std::shared_ptr<ShapeGroup> shape)
: UIState(canvas, factory), group(shape) {
}

void GroupingState::onMouseLeftBtnDown(const Coord2D& coords) {
	auto selectedShape = canvas.getShapeAt(coords);

	if (nullptr != selectedShape) {
		canvas.remove(selectedShape);
		group->add(selectedShape);
	}
}

void GroupingState::onMouseRightBtnDown(const Coord2D& coords) {
	auto selectedShape = canvas.getShapeAt(coords);

	if (nullptr != selectedShape) {
		group->remove(selectedShape);
		canvas.add(selectedShape);
	}
}

void GroupingState::onKeyUp() {
	canvas.add(group);

	int x, y;
	SDL_GetMouseState(&x, &y);
	Coord2D mouseCoordinates{x, y};

	auto selectedShape = canvas.getShapeAt(mouseCoordinates);

	changeTo(std::make_shared<IdleState>(canvas, factory, selectedShape));
}
