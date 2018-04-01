#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "SimpleShape.hpp"

class Circle: public SimpleShape
{
public:
	Circle(const Coord2D& center, const std::string& params);

	void draw(SDL_Renderer* renderer) const;
	void resizeSpecific(double factor) override;
	bool containsCoordinates(const Coord2D& coord) const;

private:
	double radius;
};

#endif /* CIRCLE_H_ */
