/*
 * GroupingState.hpp
 *
 *  Created on: 23 Mar 2018
 *      Author: osboxes
 */

#ifndef CORE_GROUPINGSTATE_HPP_
#define CORE_GROUPINGSTATE_HPP_

#include "UIState.hpp"
#include "ShapeGroup.hpp"

class GroupingState : public UIState {
public:
	GroupingState(Canvas& canvas, Factory& factory, std::shared_ptr<ShapeGroup> shape);
	virtual ~GroupingState() = default;

	void onMouseLeftBtnDown(const Coord2D& coords) override;
	void onMouseRightBtnDown(const Coord2D& coords) override;
	void onKeyUp() override;

private:
	std::shared_ptr<ShapeGroup> group;
};

#endif /* CORE_GROUPINGSTATE_HPP_ */
