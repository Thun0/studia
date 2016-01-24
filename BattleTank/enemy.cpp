#include "enemy.h"

#include "Enemy.h"
#include "world.h"
#include "utilities.h"
#define _USE_MATH_DEFINES
#include <math.h>

float Enemy::width = 1.5;

extern World world;

GLfloat Enemy::hullVertices[] = {
	-0.75, 1, -0.75,
	0.75, 1, -0.75,
	0.75, 1, 0.75,
	-0.75, 1, 0.75,

	-0.75, 0, -0.75,
	0.75, 0, -0.75,
	0.75, 1, -0.75,
	-0.75, 1, -0.75,

	-0.75, 0, 0.75,
	0.75, 0, 0.75,
	0.75, 1, 0.75,
	-0.75, 1, 0.75,

	-0.75, 0, -0.75,
	-0.75, 0, 0.75,
	-0.75, 1, 0.75,
	-0.75, 1, -0.75,

	0.75, 0, -0.75,
	0.75, 0, 0.75,
	0.75, 1, 0.75,
	0.75, 1, -0.75,
};

GLfloat Enemy::hullNormals[] = {
	0, 1, 0,
	0, 1, 0,
	0, 1, 0,
	0, 1, 0,

	0, 0, -1,
	0, 0, -1,
	0, 0, -1,
	0, 0, -1,

	0, 0, 1,
	0, 0, 1,
	0, 0, 1,
	0, 0, 1,

	-1, 0, 0,
	-1, 0, 0,
	-1, 0, 0,
	-1, 0, 0,

	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
};

GLfloat Enemy::uvHullData[] = {
	0, 0.4,
	0.5, 0.4,
	0.5, 0.5,
	0, 0.5,

	0, 0,
	0.5, 0,
	0.5, 0.4,
	0, 0.4,

	0, 0,
	0.5, 0,
	0.5, 0.4,
	0, 0.4,

	0.5, 0.6,
	1, 0.6,
	1, 1,
	0.5, 1,

	0.5, 0,
	1, 0,
	1, 0.4,
	0.5, 0.4,
};

GLfloat Enemy::turretVertices[] = {
	-0.4, 1.5, -0.4,
	0.4, 1.5, -0.4,
	0.4, 1.5, 0.4,
	-0.4, 1.5, 0.4,

	-0.4, 1, -0.4,
	0.4, 1, -0.4,
	0.4, 1.5, -0.4,
	-0.4, 1.5, -0.4,

	-0.4, 1, 0.4,
	0.4, 1, 0.4,
	0.4, 1.5, 0.4,
	-0.4, 1.5, 0.4,

	-0.4, 1, -0.4,
	-0.4, 1, 0.4,
	-0.4, 1.5, 0.4,
	-0.4, 1.5, -0.4,

	0.4, 1, -0.4,
	0.4, 1, 0.4,
	0.4, 1.5, 0.4,
	0.4, 1.5, -0.4,
};

GLfloat Enemy::turretNormals[] = {
	0, 1, 0,
	0, 1, 0,
	0, 1, 0,
	0, 1, 0,

	0, 0, -1,
	0, 0, -1,
	0, 0, -1,
	0, 0, -1,

	0, 0, 1,
	0, 0, 1,
	0, 0, 1,
	0, 0, 1,

	-1, 0, 0,
	-1, 0, 0,
	-1, 0, 0,
	-1, 0, 0,

	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
};

GLfloat Enemy::uvTurretData[] = {
	0.5, 0.5,
	0.5, 1,
	1, 1,
	1, 0.5,

	0, 0.5,
	0, 1,
	0.5, 1,
	0.5, 0.5,


	0, 0.5,
	0, 1,
	0.5, 1,
	0.5, 0.5,

	1, 0,
	0, 0,
	0, 0.5,
	1, 0.5,

	1, 0,
	0, 0,
	0, 0.5,
	1, 0.5,
};

GLfloat Enemy::gunVertices[] = {
	-0.15, 1.4, -0.15,
	0.15, 1.4, -0.15,
	0.15, 1.4, 1.5,
	-0.15, 1.4, 1.5,

	-0.15, 1.1, -0.15,
	0.15, 1.1, -0.15,
	0.15, 1.4, -0.15,
	-0.15, 1.4, -0.15,

	-0.15, 1.1, 1.5,
	0.15, 1.1, 1.5,
	0.15, 1.4, 1.5,
	-0.15, 1.4, 1.5,

	-0.15, 1.1, -0.15,
	-0.15, 1.1, 1.5,
	-0.15, 1.4, 1.5,
	-0.15, 1.4, -0.15,

	0.15, 1.1, -0.15,
	0.15, 1.1, 1.5,
	0.15, 1.4, 1.5,
	0.15, 1.4, -0.15,
};

GLfloat Enemy::gunNormals[] = {
	0, 1, 0,
	0, 1, 0,
	0, 1, 0,
	0, 1, 0,

	0, 0, -1,
	0, 0, -1,
	0, 0, -1,
	0, 0, -1,

	0, 0, 1,
	0, 0, 1,
	0, 0, 1,
	0, 0, 1,

	-1, 0, 0,
	-1, 0, 0,
	-1, 0, 0,
	-1, 0, 0,

	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
};

GLfloat Enemy::uvGunData[] = {
	0, 0.5,
	0, 1,
	0.5, 1,
	0.5, 0.5,

	0, 0.5,
	0, 1,
	0.5, 1,
	0.5, 0.5,

	0, 0.5,
	0, 1,
	0.5, 1,
	0.5, 0.5,

	0, 0.5,
	0, 1,
	0.5, 1,
	0.5, 0.5,

	0, 0.5,
	0, 1,
	0.5, 1,
	0.5, 0.5,
};

void Enemy::init(float a, float b, float c)
{
	hullAngle = c;
	turretAngle = -90;
	x = a;
	z = b;
	hullTexture = loadTexture("bmp/hullEnemy.bmp");
	turretTexture = loadTexture("bmp/turretEnemy.bmp");
}

void Enemy::draw()
{
	glPushMatrix();
	glTranslatef(x, 0, z);
	drawHull();
	drawTurret();
	drawGun();
	glPopMatrix();
}

void Enemy::drawHull()
{
	glPushMatrix();
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnable(GL_TEXTURE_2D);

	GLfloat params[] = { 1, 1, 1, 1 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, params);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, params);
	glBindTexture(GL_TEXTURE_2D, hullTexture);

	glVertexPointer(3, GL_FLOAT, 0, hullVertices);
	glNormalPointer(GL_FLOAT, 0, hullNormals);
	glTexCoordPointer(2, GL_FLOAT, 0, uvHullData);

	glRotatef(hullAngle, 0.0, 1.0, 0.0);
	glDrawArrays(GL_QUADS, 0, 20);

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glPopMatrix();
}

void Enemy::drawTurret()
{
	glPushMatrix();
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnable(GL_TEXTURE_2D);
	GLfloat params[] = { 1, 1, 1, 1 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, params);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, params);
	glBindTexture(GL_TEXTURE_2D, turretTexture);
	glVertexPointer(3, GL_FLOAT, 0, turretVertices);
	glNormalPointer(GL_FLOAT, 0, turretNormals);
	glTexCoordPointer(2, GL_FLOAT, 0, uvTurretData);

	glRotatef(turretAngle + hullAngle, 0.0, 1.0, 0.0);
	glColor3f(1, 0.0, 0.0);

	glDrawArrays(GL_QUADS, 0, 20);

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glPopMatrix();
}

void Enemy::drawGun()
{
	glPushMatrix();
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnable(GL_TEXTURE_2D);
	GLfloat params[] = { 1, 1, 1, 1 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, params);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, params);
	glBindTexture(GL_TEXTURE_2D, turretTexture);
	glVertexPointer(3, GL_FLOAT, 0, gunVertices);
	glNormalPointer(GL_FLOAT, 0, gunNormals);
	glTexCoordPointer(2, GL_FLOAT, 0, uvGunData);

	glRotatef(turretAngle + hullAngle, 0.0, 1.0, 0.0);
	glColor3f(1, 0.0, 0.0);

	glDrawArrays(GL_QUADS, 0, 20);

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glPopMatrix();
}
