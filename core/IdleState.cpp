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

IdleState::IdleState(Canvas& canvas, Factory& factory, std::shared_ptr<Shape> shape)
: UIState(canvas, factory), shape(shape) {
}

void IdleState::onMouseLeftBtnDown(const Coord2D& coords) {
	shape = canvas.getShapeAt(coords);

	if (nullptr != shape) {
		changeTo(std::make_shared<MovingState>(canvas, factory, shape));
	}
}

void IdleState::onKeyDown(const SDL_Keycode key, const Coord2D& coords) {
	switch(key) {
		case 'c': {
			shape = factory.createShape("Circle", coords, "50");
			canvas.add(shape);
		    break;
		}

		case 'r': {
			shape = factory.createShape("Rectangle", coords, "100 50");
			canvas.add(shape);
			break;
		}

		case SDLK_LCTRL:
			changeTo(std::make_shared<GroupingState>(canvas, factory, std::dynamic_pointer_cast<ShapeGroup>(shape)));
			break;

		default:
			break;
	}
}

void IdleState::onMouseWheel(const double factor, const Coord2D& coords) {
	if (nullptr != shape) {
		shape->resize(factor, coords);
	}
}

