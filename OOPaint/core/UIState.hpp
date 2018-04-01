/*
 * UIState.hpp
 *
 *  Created on: 23 Mar 2018
 *      Author: osboxes
 */

#ifndef CORE_UISTATE_HPP_
#define CORE_UISTATE_HPP_

#include <memory>
#include "SDL2/SDL.h"
#include "Canvas.hpp"
#include "Factory.hpp"

class UIState {
public:
	UIState(Canvas& canvas, Factory& factory);
	virtual ~UIState();

	virtual void onMouseLeftBtnDown(const Coord2D& coords);
	virtual void onMouseRightBtnDown(const Coord2D& coords);
	virtual void onMouseLeftBtnUp();
	virtual void onMouseMotion(const Coord2D&);
	virtual void onMouseWheel(const double factor, const Coord2D& coords);
	virtual void onKeyDown(const SDL_Keycode, const Coord2D&);
	virtual void onKeyUp();

	std::shared_ptr<UIState> getNextState() const;

protected:
	void changeTo(std::shared_ptr<UIState> state);
	Canvas& canvas;
	Factory& factory;

private:
	std::shared_ptr<UIState> nextState;
};

#endif /* CORE_UISTATE_HPP_ */
