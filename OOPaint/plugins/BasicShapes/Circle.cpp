#include <cmath>
#include "Circle.hpp"

Circle::Circle(const Coord2D& center, const std::string& params)
: SimpleShape(center), radius(std::atof(params.c_str())) {
}

void Circle::draw(SDL_Renderer* renderer) const {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	// Midpoint algorithm for drawing circle
	int x = radius, y = 0;
	int radiusError = 1-x;

	while(x >= y)
	{
		SDL_RenderDrawPoint(renderer, x + coordinates.x, y + coordinates.y);
		SDL_RenderDrawPoint(renderer, y + coordinates.x, x + coordinates.y);
		SDL_RenderDrawPoint(renderer, -x + coordinates.x, y + coordinates.y);
		SDL_RenderDrawPoint(renderer, -y + coordinates.x, x + coordinates.y);
		SDL_RenderDrawPoint(renderer, -x + coordinates.x, -y + coordinates.y);
		SDL_RenderDrawPoint(renderer, -y + coordinates.x, -x + coordinates.y);
		SDL_RenderDrawPoint(renderer, x + coordinates.x, -y + coordinates.y);
		SDL_RenderDrawPoint(renderer, y + coordinates.x, -x + coordinates.y);

		y++;

		if(radiusError<0)
		{
			radiusError+=2*y+1;
		}
		else
		{
			x--;
			radiusError+=2*(y-x+1);
		}
	}
}

void Circle::resizeSpecific(double factor) {
	radius *= factor;
}

bool Circle::containsCoordinates(const Coord2D& coord) const {
	return (coordinates.distanceTo(coord) <= radius);
}
