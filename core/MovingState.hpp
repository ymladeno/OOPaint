/*
 * MovingState.hpp
 *
 *  Created on: 23 Mar 2018
 *      Author: osboxes
 */

#ifndef CORE_MOVINGSTATE_HPP_
#define CORE_MOVINGSTATE_HPP_

#include "UIState.hpp"
#include "Shape.hpp"

class MovingState : public UIState {
public:
	MovingState(Canvas& canvas, Factory& factory, std::shared_ptr<Shape> shape);
	virtual ~MovingState();

	virtual void onMouseLeftBtnDown(const Coord2D& coords) override;
	virtual void onMouseLeftBtnUp() override;
	virtual void onMouseMotion(const Coord2D& coords) override;
	//virtual void onKeyUp() override;
private:
	std::shared_ptr<Shape> shape;
};

#endif /* CORE_MOVINGSTATE_HPP_ */
