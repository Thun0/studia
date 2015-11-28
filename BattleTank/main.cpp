#include "glut.h"
#include <GL/gl.h>
#include <windows.h>

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glColor4f(1, 1, 0, 1);
	glVertex3f(-0.5, -0.5, 0.0);
	glColor4f(0, 1, 1, 1);
	glVertex3f(0.5, 0.0, 0.0);
	glColor4f(1, 0, 1, 1);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Battle Tank");

	glutDisplayFunc(draw);
	glutMainLoop();

	return 0;
}
