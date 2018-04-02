/*
 * SnapMove.cpp
 *
 *  Created on: 19 Mar 2018
 *      Author: osboxes
 */

#include "../core/SnapMove.hpp"

SnapMove::SnapMove(const int gridSize)
: gridSize(gridSize) {
}

Coord2D SnapMove::move(const Coord2D& currCoordenates, const Coord2D& deltaCoord) {
	auto desiredCoords = currCoordenates + deltaCoord + remainder;
	auto snapCoords = (desiredCoords / gridSize).floor() * gridSize;	// rounds the coords to multiple of gridSize
	remainder = desiredCoords - snapCoords;

	return snapCoords;
}
