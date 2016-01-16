#include "glut.h"
#include <GL/gl.h>
#include <windows.h>
#include "tank.h"

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;

void reshape(GLsizei w, GLsizei h);
void draw();

Tank tank;

void init()
{
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Battle Tank");
	glutDisplayFunc(draw);
	glutIdleFunc(draw);
	glutReshapeFunc(reshape);

	//glShadeModel(GL_SMOOTH);							
	//glClearDepth(1.0f);									
	glEnable(GL_DEPTH_TEST);							
	glDepthFunc(GL_LEQUAL);								
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	
}

void reshape(int w, int h)
{
	if (h > 0 && w > 0)
	{
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45, 1.0*w/h, 1, 1000);
		glMatrixMode(GL_MODELVIEW);
	}
}

void draw()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0, 0, -10);
	tank.draw();

	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	init();

	glutMainLoop();

	return 0;
}
