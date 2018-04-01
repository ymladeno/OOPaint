#include "Rectangle.hpp"

Rectangle::Rectangle(const Coord2D& leftTop, const std::string& params)
: SimpleShape(leftTop), dimensions(Coord2D(params)) {
}

bool Rectangle::containsCoordinates(const Coord2D& coord) const {
	return (coordinates.x <= coord.x) && (coordinates.y <= coord.y)
			&& (coordinates.x + dimensions.x > coord.x) && (coordinates.y + dimensions.y > coord.y);
}

void Rectangle::draw(SDL_Renderer* renderer) const {
	SDL_Rect rect = {(int)coordinates.x, (int)coordinates.y, (int)dimensions.x, (int)dimensions.y};

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(renderer, &rect);
}

void Rectangle::resizeSpecific(double factor) {
	dimensions.x *= factor;
	dimensions.y *= factor;
}

