/*
 * UIStateMachine.hpp
 *
 *  Created on: 23 Mar 2018
 *      Author: osboxes
 */

#ifndef CORE_UISTATEMACHINE_HPP_
#define CORE_UISTATEMACHINE_HPP_

#include "UIState.hpp"

class UIStateMachine {
public:
	UIStateMachine(std::shared_ptr<UIState> state);
	virtual ~UIStateMachine() = default;
	void onEvent(SDL_Event& event);
	bool isRunning() const;

private:
	void updateState(std::shared_ptr<UIState> state);
	std::shared_ptr<UIState> currentState;
	bool clickedX;
};

#endif /* CORE_UISTATEMACHINE_HPP_ */
