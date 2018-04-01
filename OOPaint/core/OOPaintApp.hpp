/*
 * OOPaintApp.hpp
 *
 *  Created on: Nov 25, 2015
 *      Author: ivaylo
 */

#ifndef OOPAINTAPP_HPP_
#define OOPAINTAPP_HPP_

#include "Canvas.hpp"
#include "Factory.hpp"
#include "ShapeGroup.hpp"
#include "UIStateMachine.hpp"

// FIXME: concrete class, doesn't have abstract base or separate interface
class OOPaintApp {
public:
	OOPaintApp(Canvas& canvas, UIStateMachine& stateMachine);
	~OOPaintApp() = default;

	void run();

private:
	Canvas& canvas;
	UIStateMachine& stateMachine;
};

#endif /* OOPAINTAPP_HPP_ */
