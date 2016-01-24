#include "tank.h"
#include "world.h"
#include "utilities.h"
#define _USE_MATH_DEFINES
#include <math.h>

float Tank::width = 1.5;

GLfloat Tank::hullVertices[] = {
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

GLfloat Tank::hullNormals[] = {
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

GLfloat Tank::uvHullData[] = {
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

GLfloat Tank::turretVertices[] =	{
										-1.5, 2, 1,
										1.5, 2, 1,
										1.5, 3, 1,
										-1.5, 3, 1,

										-1.5, 3, -1,
										-1.5, 2, -1,
										1.5, 2, -1,
										1.5, 3, -1,
									};

GLfloat Tank::gunVertices[] =		{
										-1.5, 2.25, 0.25,
										-5, 2.25, 0.25,
										-5, 2.75, 0.25,
										-1.5, 2.75, 0.25,

										-1.5, 2.75, -0.25,
										-1.5, 2.25, -0.25,
										-5, 2.25, -0.25,
										-5, 2.75, -0.25,
									};


float Tank::turretSpeed = 0.20;
float Tank::turnSpeed = 0.14;
float Tank::speed = 0.01;

Tank::Tank()
{}

void Tank::init()
{
	hullAngle = 0;
	turretAngle = 0;
	x = -5;
	z = 0;
	isLeft = false;
	isRight = false;
	isForward = false;
	isBackward = false;
	turretRight = false;
	turretLeft = false;
	hullTexture = loadTexture("bmp/hull.bmp");
}

void Tank::draw()
{
	glTranslatef(x, 0, z);
	drawHull();
	//drawTurret();
	//drawGun();
}

void Tank::drawHull()
{
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

	glPushMatrix();
	glRotatef(hullAngle, 0.0, 1.0, 0.0);
	glDrawArrays(GL_QUADS, 0, 20);

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glPopMatrix();	
}

void Tank::drawTurret()
{
	glVertexPointer(3, GL_FLOAT, 0, turretVertices);
	glPushMatrix();
	glRotatef(turretAngle + hullAngle, 0.0, 1.0, 0.0);
	glColor3f(1, 0.0, 0.0);

	glDrawArrays(GL_QUADS, 0, 20);
	glPopMatrix();
}

void Tank::drawGun()
{
	glVertexPointer(3, GL_FLOAT, 0, gunVertices);
	glPushMatrix();
	glRotatef(turretAngle + hullAngle, 0.0, 1.0, 0.0);
	glColor3f(1, 0.0, 0.8);

	glDrawArrays(GL_QUADS, 0, 20);
	glPopMatrix();
}

void Tank::forward(bool a)
{
	isForward = a;
}

void Tank::backward(bool a)
{
	isBackward = a;
}

void Tank::turnLeft(bool a)
{
	isLeft = a;
}

void Tank::turnRight(bool a)
{
	isRight = a;
}

void Tank::turnTurretLeft(bool a)
{
	turretLeft = a;
}

void Tank::turnTurretRight(bool a)
{
	turretRight = a;
}

void Tank::checkCollisions(float newX, float newZ)
{
	bool badZ = false;
	bool badX = false;
	for (int i = 0; i < World::MAP_SIZE; ++i)
	{
		for (int j = 0; j < World::MAP_SIZE; ++j)
		{
			if (World::map[i][j] == 0)
				continue;
			if (fabs(newX - (j*World::WALL_SIZE - 20 + World::WALL_SIZE / 2)) < width / 2 + World::WALL_SIZE / 2
				&& fabs(newZ - (i*World::WALL_SIZE - 20 + World::WALL_SIZE / 2)) < width / 2 + World::WALL_SIZE / 2)
			{
				//printf("kolizja! %d %d // %f %f // %f %f\n", i, j, newX, newZ, x, z);
				if ((fabs(x - (j*World::WALL_SIZE - 20 + World::WALL_SIZE / 2)) < width / 2 + World::WALL_SIZE / 2
					&& fabs(newZ - (i*World::WALL_SIZE - 20 + World::WALL_SIZE / 2)) < width / 2 + World::WALL_SIZE / 2))
				{
					//printf("Z bad\n");
					badZ = true;
				}
				if ((fabs(newX - (j*World::WALL_SIZE - 20 + World::WALL_SIZE / 2)) < width / 2 + World::WALL_SIZE / 2
					&& fabs(z - (i*World::WALL_SIZE - 20 + World::WALL_SIZE / 2)) < width / 2 + World::WALL_SIZE / 2))
				{
					//printf("X bad\n");
					badX = true;
				}
			}
		}
	}
	if (!badX) x = newX;
	if (!badZ) z = newZ;
}

void Tank::update(int delta)
{
	if (turretRight && !turretLeft)
		turretAngle -= turretSpeed*delta;
	else if (!turretRight && turretLeft)
		turretAngle += turretSpeed*delta;
	if (isLeft && !isRight)
		hullAngle += turnSpeed*delta;
	if (!isLeft && isRight)
		hullAngle -= turnSpeed*delta;
	float angle = (hullAngle) * M_PI / 180;

	float newX, newZ;
	if (isForward && !isBackward)
	{
		newX = x - cos(angle)*speed*delta;
		newZ = z + sin(angle)*speed*delta;
		checkCollisions(newX, newZ);	
	}
	if (isBackward && !isForward)
	{
		newX = x + cos(angle)*speed*delta;
		newZ = z - sin(angle)*speed*delta;
		checkCollisions(newX, newZ);
	}
}

Tank::~Tank()
{
}