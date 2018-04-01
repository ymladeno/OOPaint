/*
 * UIStateMachine.cpp
 *
 *  Created on: 23 Mar 2018
 *      Author: osboxes
 */

#include <stdexcept>
#include "UIStateMachine.hpp"

UIStateMachine::UIStateMachine(std::shared_ptr<UIState> state)
: currentState(state), clickedX(false) {

}

void UIStateMachine::updateState(std::shared_ptr<UIState> state) {
	if (nullptr != state) {
		currentState = state;
	}
}

bool UIStateMachine::isRunning() const {
	return !clickedX;
}

void UIStateMachine::onEvent(SDL_Event& event) {

	int x, y;
	SDL_GetMouseState(&x, &y);

	Coord2D mouseCoordinates{x, y};

	switch (event.type) {

		case  SDL_QUIT:
			clickedX = true;
			return;

		case SDL_MOUSEBUTTONDOWN:
			if (SDL_BUTTON_LEFT == event.button.button) {
				currentState->onMouseLeftBtnDown(mouseCoordinates);
			} else if (SDL_BUTTON_RIGHT == event.button.button) {
				currentState->onMouseRightBtnDown(mouseCoordinates);
			}
			else {
			}
			break;

		case SDL_MOUSEBUTTONUP:
			currentState->onMouseLeftBtnUp();
			break;

		case SDL_KEYDOWN:
			currentState->onKeyDown(event.key.keysym.sym, mouseCoordinates);
			break;

		case SDL_MOUSEMOTION:
			currentState->onMouseMotion(Coord2D(event.motion.xrel, event.motion.yrel));
			break;

		case SDL_MOUSEWHEEL:
			currentState->onMouseWheel(event.wheel.y > 0 ? 1.1:0.9, mouseCoordinates);
			break;

		case SDL_KEYUP:
			currentState->onKeyUp();
			break;

	}

	updateState(currentState->getNextState());

}


