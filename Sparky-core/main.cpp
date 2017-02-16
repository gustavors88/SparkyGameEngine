#include "src\graphics\window.h"
#include "src\maths\maths.h"

int main() {
	using namespace sparky;
	using namespace graphics;
	using namespace maths;

	Window window("Sparky!", 950, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	mat4 position = mat4::translation(vec3(2, 3, 4));
	position *= mat4::identity();
	
	position.elements[12] = 4.0f;

	vec4& column = position.columns[3];
	std::cout << &position.columns[3].x << std::endl;
	std::cout << &position.elements[12] << std::endl;


	while (!window.closed()) {
		window.clear();
		

#if 1
		glBegin(GL_QUADS);
		glVertex2d(-0.5f, -0.5f);
		glVertex2d(-0.5f,  0.5f);
		glVertex2d( 0.5f,  0.5f);
		glVertex2d( 0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif

		window.update();
	}
	return 0;
}
