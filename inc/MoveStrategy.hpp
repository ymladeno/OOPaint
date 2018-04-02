/*
 * MoveStrategy.hpp
 *
 *  Created on: 19 Mar 2018
 *      Author: osboxes
 */

#ifndef INC_MOVESTRATEGY_HPP_
#define INC_MOVESTRATEGY_HPP_

#include "Coord2D.hpp"

class MoveStrategy {
public:
	virtual ~MoveStrategy() = default;
	virtual Coord2D move(const Coord2D& currCoordenates, const Coord2D& deltaCoord) = 0;
};

#endif /* INC_MOVESTRATEGY_HPP_ */
