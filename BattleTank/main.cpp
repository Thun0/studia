#include "glut.h"
#include <GL/gl.h>
#include <windows.h>
#include "tank.h"
#include "world.h"
#include <cstdio>
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;

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
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Battle Tank");
	glutDisplayFunc(draw);
	glutIdleFunc(draw);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
	glutSpecialFunc(specialDown);
	glutSpecialUpFunc(specialUp);
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

void keyUp(unsigned char key, int x, int y)
{
	if (key == 'z')
	{
		tank.turnTurretRight(false);
	}
	if (key == 'x')
	{
		tank.turnTurretLeft(false);
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
		tank.turnTurretRight(true);
	}
	if (key == 'x')
	{
		tank.turnTurretLeft(true);
	}
}

void specialUp(int key, int x, int y)
{
}

void specialDown(int key, int x, int y)
{
	
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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0, 0, -10);
	tank.draw();
	world.draw();

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
