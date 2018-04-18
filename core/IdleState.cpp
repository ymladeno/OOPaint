/*
 * IdleState.cpp
 *
 *  Created on: 23 Mar 2018
 *      Author: osboxes
 */

#include "Shape.hpp"
#include "IdleState.hpp"
#include "MovingState.hpp"
#include "GroupingState.hpp"

IdleState::IdleState(Canvas& canvas, Factory& factory)
: UIState(canvas, factory) {
}

void IdleState::onMouseLeftBtnDown(const Coord2D& coords) {
	auto shape = canvas.getShapeAt(coords);

	if (nullptr != shape) {
		changeTo(std::make_shared<MovingState>(canvas, factory, shape));
	}
}

void IdleState::onMouseRightBtnDown(const Coord2D& coords) {
	auto selectedShape = canvas.getShapeAt(coords);

	if (selectedShape != nullptr) {
		auto shapes = selectedShape->getChildren();

		if(!shapes.empty()) {
			canvas.remove(selectedShape);

			for(auto shape : shapes) {
				canvas.add(shape);
			}
		}
	}
}

void IdleState::onKeyDown(const SDL_Keycode key, const Coord2D& coords) {
	switch(key) {
		case 'c': {
			auto shape = factory.createShape("Circle", coords, "50");
			canvas.add(shape);
		    break;
		}

		case 'r': {
			auto shape = factory.createShape("Rectangle", coords, "100 50");
			canvas.add(shape);
			break;
		}

		case SDLK_LCTRL:
			changeTo(std::make_shared<GroupingState>(canvas, factory, std::make_shared<ShapeGroup>()));
			break;

		default:
			break;
	}
}

void IdleState::onMouseWheel(const double factor, const Coord2D& coords) {
	auto shape = canvas.getShapeAt(coords);

	if (nullptr != shape) {
		shape->resize(factor, coords);
	}
}

