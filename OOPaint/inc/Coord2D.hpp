#ifndef COORD2D_HPP_
#define COORD2D_HPP_

#include <string>

struct Coord2D
{
	double x;
	double y;

	Coord2D(double x = 0.0, double y = 0.0);
	Coord2D(const std::string& s1);

	double distanceTo(const Coord2D& coord) const;
	Coord2D& operator+=(const Coord2D& addCoord);
	Coord2D operator+(const Coord2D& addCoord) const;
	Coord2D operator-(const Coord2D& addCoord) const;
	Coord2D operator/(const int num) const;
	Coord2D operator*(const double num) const;
	Coord2D operator*=(const double num);
	Coord2D floor() const;
};

#endif /* COORD2D_HPP_ */
