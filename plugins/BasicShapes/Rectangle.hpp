#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "SimpleShape.hpp"

class Rectangle: public SimpleShape {
public:
	Rectangle(const Coord2D& leftTop, const std::string& params);

	void draw(SDL_Renderer* renderer) const;
	void resizeSpecific(double factor) override;
	bool containsCoordinates(const Coord2D& coord) const;

private:
	Coord2D dimensions;
};

#endif /* RECTANGLE_HPP_ */
