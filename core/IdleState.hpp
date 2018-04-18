/*
 * IdleState.hpp
 *
 *  Created on: 23 Mar 2018
 *      Author: osboxes
 */

#ifndef CORE_IDLESTATE_HPP_
#define CORE_IDLESTATE_HPP_

#include <memory>
#include "UIState.hpp"

class IdleState : public UIState {
public:
	IdleState(Canvas&, Factory&);
	virtual ~IdleState() = default;

	void onMouseLeftBtnDown(const Coord2D& coords) override;
	void onMouseRightBtnDown(const Coord2D& coords) override;
	void onKeyDown(const SDL_Keycode key, const Coord2D& coords) override;
	void onMouseWheel(const double factor, const Coord2D& coords) override;
};

#endif /* CORE_IDLESTATE_HPP_ */
