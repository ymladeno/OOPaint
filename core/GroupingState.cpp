/*
 * GroupingState.cpp
 *
 *  Created on: 23 Mar 2018
 *      Author: osboxes
 */

#include "GroupingState.hpp"
#include "IdleState.hpp"
#include "MovingState.hpp"

GroupingState::GroupingState(Canvas& canvas, Factory& factory, std::shared_ptr<ShapeGroup> group)
: UIState(canvas, factory), group(group) {
}

void GroupingState::onMouseLeftBtnDown(const Coord2D& coords) {
	auto selectedShape = canvas.getShapeAt(coords);

	if (nullptr != selectedShape) {
		canvas.remove(selectedShape);
		group->add(selectedShape);
	}
}

void GroupingState::onKeyUp() {
	if (group != nullptr) {
		canvas.add(group);
	}
	changeTo(std::make_shared<IdleState>(canvas, factory));
}

