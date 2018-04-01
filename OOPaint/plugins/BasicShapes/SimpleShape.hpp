/*
 * SimpleShape.hpp
 *
 *  Created on: 20 Mar 2018
 *      Author: osboxes
 */

#ifndef SRC_SimpleShape_HPP_
#define SRC_SimpleShape_HPP_

#include "../inc/Shape.hpp"

class SimpleShape : public Shape {
public:
	SimpleShape(const Coord2D& coordinates);
	virtual ~SimpleShape();

	// Methods inherited by subclasses
	virtual void setColor(const SDL_Color& color);
	virtual const SDL_Color& getColor() const;

	virtual void moveBy(const Coord2D& deltaCoord);
	void resize(double factor, const Coord2D& center) override;

	// Pure virtual methods - to be implemented in subclasses
	virtual void draw(SDL_Renderer* renderer) const = 0;
	virtual bool containsCoordinates(const Coord2D& coord) const = 0;

	virtual void setMoveStrategy(MoveStrategy* movestrategy);

protected:
	virtual void resizeSpecific(double factor) = 0;

	SDL_Color color;
	Coord2D coordinates;
	MoveStrategy* moveStrategy;
};

#endif /* SRC_SimpleShape_HPP_ */
