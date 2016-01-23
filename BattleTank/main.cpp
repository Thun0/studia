#include "glut.h"
#include <GL/gl.h>
#include <windows.h>
#include "tank.h"
#include "world.h"

const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT = 900;

void reshape(GLsizei w, GLsizei h);
void draw();
void keyUp(unsigned char, int, int);
void keyDown(unsigned char, int, int);
void specialUp(int, int, int);
void specialDown(int, int, int);
void update();

Tank tank;
World world;

int oldTime = 0;

void init()
{
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Battle Tank");

	glutDisplayFunc(draw);
	glutIdleFunc(draw);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
	glutSpecialFunc(specialDown);
	glutSpecialUpFunc(specialUp);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);									
	glEnable(GL_DEPTH_TEST);							
	glEnable(GL_NORMALIZE);
	glDepthFunc(GL_LEQUAL);								
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();                                // Reset The Projection Matrix
	gluPerspective(45.0f, 1.0*WINDOW_WIDTH/WINDOW_HEIGHT, 0.1f, 1000.0f);        // Calculate The Aspect Ratio Of The Window
	glMatrixMode(GL_MODELVIEW);
}

void reshape(int w, int h)
{
	if (h > 0 && w > 0)
	{
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45, 1.0*w/h, 0.1, 1000);
		glMatrixMode(GL_MODELVIEW);
	}
}

void keyUp(unsigned char key, int x, int y)
{
	if (key == 'z')
	{
		tank.turnTurretLeft(false);
	}
	if (key == 'x')
	{
		tank.turnTurretRight(false);
	}
}

void keyDown(unsigned char key, int x, int y)
{
	if (key == 27)
	{
		exit(0);
	}

	if (key == 'z')
	{
		tank.turnTurretLeft(true);
	}
	if (key == 'x')
	{
		tank.turnTurretRight(true);
	}
}

void specialUp(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT)
	{
		tank.turnLeft(false);
	}
	if (key == GLUT_KEY_RIGHT)
	{
		tank.turnRight(false);
	}
	if (key == GLUT_KEY_UP)
	{
		tank.forward(false);
	}
	if (key == GLUT_KEY_DOWN)
	{
		tank.backward(false);
	}
}

void specialDown(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT)
	{
		tank.turnLeft(true);
	}
	if (key == GLUT_KEY_RIGHT)
	{
		tank.turnRight(true);
	}
	if (key == GLUT_KEY_UP)
	{
		tank.forward(true);
	}
	if (key == GLUT_KEY_DOWN)
	{
		tank.backward(true);
	}
}

void update(int delta)
{
	tank.update(delta);
}

void draw()
{
	int time = glutGet(GLUT_ELAPSED_TIME);
	int delta = time - oldTime;
	oldTime = time;
	update(delta);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(0.0f, 50.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f);
	world.draw();
	tank.draw();

	//glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	init();

	world.init();
	tank.init();

	glutMainLoop();

	return 0;
}
