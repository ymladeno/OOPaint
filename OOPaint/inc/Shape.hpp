#ifndef SHAPE_HPP_
#define SHAPE_HPP_

#include <SDL2/SDL.h>
#include <cassert>

#include "../inc/Coord2D.hpp"
#include "../inc/MoveStrategy.hpp"

class Shape {
public:
	virtual ~Shape() = default;

	virtual void setColor(const SDL_Color& color) = 0;
	virtual void moveBy(const Coord2D& deltaCoord) = 0;
	virtual void draw(SDL_Renderer* renderer) const = 0;
	virtual void resize(double factor, const Coord2D& center) = 0;
	virtual bool containsCoordinates(const Coord2D& coord) const = 0;
	virtual void setMoveStrategy(MoveStrategy* movestrategy) = 0;
};

#endif /* SHAPE_HPP_ */
