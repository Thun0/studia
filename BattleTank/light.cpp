#include "light.h"

void Light::init()
{
	intensity = 0.8;

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	GLfloat global_ambient[] = { 0.2, 0.2, 0.2, 0.2 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);
}

void Light::update()
{
	GLfloat params[] = { intensity, intensity, intensity, intensity };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, params);
	GLfloat position[] = { 20, 15, 20, 1.0f };
	glLightfv(GL_LIGHT1, GL_POSITION, position);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, params);
	GLfloat position2[] = { -20, 10, 0, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, position2);
}

void Light::increase()
{
	intensity += 0.1;
}

void Light::decrease()
{
	intensity -= 0.1;
}