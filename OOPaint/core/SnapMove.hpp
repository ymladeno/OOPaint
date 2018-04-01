/*
 * SnapMove.hpp
 *
 *  Created on: 19 Mar 2018
 *      Author: osboxes
 */

#ifndef CORE_SNAPMOVE_HPP_
#define CORE_SNAPMOVE_HPP_

#include "../inc/MoveStrategy.hpp"

class SnapMove : public MoveStrategy {
public:
	SnapMove(const int gridSize);
	virtual ~SnapMove() = default;

	virtual Coord2D move(const Coord2D& currCoordenates, const Coord2D& deltaCoord);

private:
	const int gridSize;
	Coord2D remainder;
};

#endif /* CORE_SNAPMOVE_HPP_ */
