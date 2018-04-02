/*
 * SmoothMove.hpp
 *
 *  Created on: 19 Mar 2018
 *      Author: osboxes
 */

#ifndef CORE_SMOOTHMOVE_HPP_
#define CORE_SMOOTHMOVE_HPP_

#include "../inc/MoveStrategy.hpp"

class SmoothMove : public MoveStrategy {
public:
	SmoothMove();
	virtual ~SmoothMove();
	virtual Coord2D move(const Coord2D& currCoordenates, const Coord2D& deltaCoord);
};

#endif /* CORE_SMOOTHMOVE_HPP_ */
