#include "src\graphics\window.h"

int main() {
	using namespace sparky;
	using namespace graphics;
	
	Window window("Sparky!", 950, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);


	std::cout << glGetString(GL_VERSION) << std::endl;

	while (!window.closed()) {
		std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;
		window.clear();
		glBegin(GL_QUADS);
		glVertex2d(-0.5f, -0.5f);
		glVertex2d(-0.5f,  0.5f);
		glVertex2d( 0.5f,  0.5f);
		glVertex2d( 0.5f, -0.5f);
		glEnd();
		window.update();
	}

	
	return 0;
}
