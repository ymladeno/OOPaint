/*
 * UIState.cpp
 *
 *  Created on: 23 Mar 2018
 *      Author: osboxes
 */
#include <iostream>
#include "UIState.hpp"

UIState::UIState(Canvas& canvas, Factory& factory)
: canvas(canvas), factory(factory), nextState(nullptr) {
}

UIState::~UIState() {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void UIState::onMouseLeftBtnDown(const Coord2D&) {
	//no implementation
}

void UIState::onMouseRightBtnDown(const Coord2D&) {
	//no implementation
}

void UIState::onMouseLeftBtnUp() {
	//no implementation
}

void UIState::onMouseMotion(const Coord2D&) {
	//no implementation
}

void UIState::onMouseWheel(const double, const Coord2D&) {
	//no implementation
}

void UIState::onKeyDown(const SDL_Keycode, const Coord2D&) {
	//no implementation
}

void UIState::onKeyUp() {
	//no implementation
}

void UIState::changeTo(std::shared_ptr<UIState> state) {
	nextState = state;
}

std::shared_ptr<UIState> UIState::getNextState() const {
	return nextState;
}
