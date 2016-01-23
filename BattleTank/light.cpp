#include "light.h"

void Light::init()
{
	intensity = 0.2;

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	GLfloat global_ambient[] = { 0.2, 0.2, 0.2, 0.2 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

	glEnable(GL_LIGHT1);
}

void Light::update()
{
	GLfloat params[] = { intensity, intensity, intensity, intensity };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, params);
	GLfloat position[] = { -15, 10, 0, 1.0f };
	glLightfv(GL_LIGHT1, GL_POSITION, position);
}

void Light::increase()
{
	intensity += 0.1;
	update();
}

void Light::decrease()
{
	intensity -= 0.1;
	update();
}