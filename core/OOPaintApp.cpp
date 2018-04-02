/*
 * OOPaintApp.cpp
 *
 *  Created on: Nov 25, 2015
 *      Author: ivaylo
 */
#include <memory>
#include "OOPaintApp.hpp"

OOPaintApp::OOPaintApp(Canvas& canvas, UIStateMachine& stateMachine)
: canvas(canvas), stateMachine(stateMachine) {
}

void OOPaintApp::run() {

	while (true) {
		SDL_Event event;

		if (SDL_WaitEvent(&event))
		{
			stateMachine.onEvent(event);

			if (!stateMachine.isRunning()) {
				return;
			}

			// Show the result
			canvas.update();
		}
	}
}
