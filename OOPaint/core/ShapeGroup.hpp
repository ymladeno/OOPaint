/*
 * ShapeGroup.hpp
 *
 *  Created on: 20 Mar 2018
 *      Author: osboxes
 */

#ifndef SRC_ShapeGroup_HPP_
#define SRC_ShapeGroup_HPP_

#include <set>
#include <memory>

#include "../inc/Shape.hpp"

class ShapeGroup : public Shape {
public:
	ShapeGroup();
	virtual ~ShapeGroup() = default;

	void setColor(const SDL_Color& color) override;
	void moveBy(const Coord2D& deltaCoord) override;
	void draw(SDL_Renderer* renderer) const override;
	void resize(double factor, const Coord2D& center) override;
	bool containsCoordinates(const Coord2D& coord) const override;
	void setMoveStrategy(MoveStrategy* movestrategy) override;

    void add(std::shared_ptr<Shape> shape);
    void remove(std::shared_ptr<Shape> shape);
    void removeall();

	std::set<std::shared_ptr<Shape>>::iterator begin() const;
    std::set<std::shared_ptr<Shape>>::iterator end() const;

private:
	std::set<std::shared_ptr<Shape>> group;
};

#endif /* SRC_ShapeGroup_HPP_ */
