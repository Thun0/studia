#include "projectile.h"
#define _USE_MATH_DEFINES
#include <math.h>

const GLfloat Projectile::vertices[] = {
	0, 1.2, 0,
	0.1, 1.2, 0,
	0.1, 1.3, 0,
	0, 1.3, 0,

	0.1, 1.2, 0,
	0.1, 1.2, -0.1,
	0.1, 1.3, -0.1,
	0.1, 1.3, 0,

	0, 1.2, 0,
	0, 1.3, 0,
	0, 1.3, -0.1,
	0, 1.2, -0.1,

	0, 1.3, 0,
	0.1, 1.3, 0,
	0.1, 1.3, -0.1,
	0, 1.3, -0.1,

	0, 1.2, -0.1,
	0.1, 1.2, -0.1,
	0.1, 1.3, -0.1,
	0, 1.3, -0.1,
};

const GLfloat Projectile::normals[] = {
	0, 0, 1,
	0, 0, 1,
	0, 0, 1,
	0, 0, 1,

	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
	1, 0, 0,

	-1, 0, 0,
	-1, 0, 0,
	-1, 0, 0,
	-1, 0, 0,

	0, 1, 0,
	0, 1, 0,
	0, 1, 0,
	0, 1, 0,

	0, 0, -1,
	0, 0, -1,
	0, 0, -1,
	0, 0, -1,
};

Projectile::Projectile(float a, float b, float ang)
{
	speed = 0.01;
	x = a;
	z = b;
	angle = ang+90;
}

void Projectile::draw()
{
	glPushMatrix();

	GLfloat params[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, params);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, params);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glColor3f(0.8, 0.8, 0);
	glTranslatef(x, 0, z);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glNormalPointer(GL_FLOAT, 0, normals);
	glDrawArrays(GL_QUADS, 0, 20);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
}

void Projectile::update(int delta)
{
	float rdangle = (angle)* M_PI / 180;
	x -= cos(rdangle)*speed*delta;
	z += sin(rdangle)*speed*delta;
	checkCollision();
}

void Projectile::checkCollision()
{

}