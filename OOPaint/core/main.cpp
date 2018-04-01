#include "Canvas.hpp"
#include "OOPaintApp.hpp"
#include "RegisterShapeFactory.hpp"
#include "PluginManager.hpp"
#include "IdleState.hpp"

const char* DEFAULT_WINDOW_TITLE = "Object-Oriented Paint - EA";
const int DEFAULT_WINDOW_WIDTH = 640;
const int DEFAULT_WINDOW_HEIGHT = 480;
const SDL_Color DEFAULT_WINDOW_COLOR = {0x30, 0x30, 0x30, 0xff};

int main() {
	// Create subsystems & wire them together
	RegisterShapeFactory factory;
	PluginManager pluginManager(factory);

	pluginManager.loadPlugins("/home/osboxes/workspace/training_paterns/OOPaint/install/plugins/basic_shapes.so");

	Canvas canvas = Canvas(
			DEFAULT_WINDOW_TITLE, 
			DEFAULT_WINDOW_WIDTH, 
			DEFAULT_WINDOW_HEIGHT, 
			DEFAULT_WINDOW_COLOR);

    UIStateMachine stateMachine(std::make_shared<IdleState>(canvas, factory, nullptr));

	OOPaintApp application(canvas, stateMachine);		// Dependency Injection (almost; Canvas is not Abstract...)
	
	application.run();
}
