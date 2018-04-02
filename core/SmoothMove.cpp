/*
 * SmoothMove.cpp
 *
 *  Created on: 19 Mar 2018
 *      Author: osboxes
 */

#include "../core/SmoothMove.hpp"

SmoothMove::SmoothMove() {
}

SmoothMove::~SmoothMove() {
}

Coord2D SmoothMove::move(const Coord2D& currCoordenates, const Coord2D& deltaCoord) {
	return currCoordenates + deltaCoord;
}
