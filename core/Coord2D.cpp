#include "../inc/Coord2D.hpp"

#include <cmath>
#include <sstream>

Coord2D::Coord2D(double x, double y)
: x(x), y(y) {
}

Coord2D::Coord2D(const std::string& txtCoords)
: x(0), y(0) {
    std::istringstream iss(txtCoords);
    iss >> x >> y;
}

// FIXME: not all related operators are overloaded
Coord2D Coord2D::operator+(const Coord2D& addCoord) const {
	return Coord2D(x + addCoord.x, y + addCoord.y);
}

Coord2D& Coord2D::operator+=(const Coord2D& addCoord) {
	*this = *this + addCoord;

	return *this;
}

// FIXME: should be defined in terms of others, i.e. operator+ and unary-
Coord2D Coord2D::operator-(const Coord2D& addCoord) const {
	return Coord2D(x - addCoord.x, y - addCoord.y);
}

Coord2D Coord2D::operator/(const int num) const {
	return Coord2D(x / num, y / num);
}

Coord2D Coord2D::operator*(const double num) const {
	return Coord2D(x * num, y * num);
}

Coord2D Coord2D::operator*=(const double num) {
	*this = *this * num;
	return *this;
}

Coord2D Coord2D::floor() const {
	return Coord2D(std::floor(x), std::floor(y));
}

double Coord2D::distanceTo(const Coord2D& coord) const {
	return sqrt((x - coord.x) * (x - coord.x) + (y - coord.y) *  (y - coord.y));
}
