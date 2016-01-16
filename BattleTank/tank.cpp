#include "tank.h"

GLfloat Tank::hullVertices[] =		{	
										-3, 0.5, 2,
										3, 0.5, 2,
										3, 2, 2,
										-3, 2, 2,
										-3, 2, -2,
										-3, 0.5, -2,
										3, 0.5, -2,
										3, 2, -2,
									};
GLuint Tank::hullIndices[] =		{
										0, 1, 2, 3,
										0, 3, 4, 5,
										5, 4, 7, 6,
										1, 2, 7, 6,
										0, 1, 5, 6,
										2, 3, 4, 7,
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
GLuint Tank::turretIndices[] =		{
										0, 1, 2, 3,
										0, 3, 4, 5,
										5, 4, 7, 6,
										1, 2, 7, 6,
										0, 1, 5, 6,
										2, 3, 4, 7,
									};

GLfloat Tank::tracksVertices[] =	{
										-3, -1, 2,
										3, -1, 2,
										3, 0.5, 2,
										-3, 0.5, 2,
										-3, 0.5, 1.5,
										-3, -1, 1.5,
										3, -1, 1.5,
										3, 0.5, 1.5,

										-3, -1, -1.5,
										3, -1, -1.5,
										3, 0.5, -1.5,
										-3, 0.5, -1.5,
										-3, 0.5, -2,
										-3, -1, -2,
										3, -1, -2,
										3, 0.5, -2,
									};
GLuint Tank::tracksIndices[] =		{
										0, 1, 2, 3,
										0, 3, 4, 5,
										5, 4, 7, 6,
										1, 2, 7, 6,
										0, 1, 5, 6,
										2, 3, 4, 7,

										8, 9, 10, 11,
										8, 11, 12, 13,
										13, 12, 15, 14,
										9, 10, 15, 14,
										8, 9, 13, 14,
										10, 11, 12, 15,
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
GLuint Tank::gunIndices[] =			{
										0, 1, 2, 3,
										0, 3, 4, 5,
										5, 4, 7, 6,
										1, 2, 7, 6,
										0, 1, 5, 6,
										2, 3, 4, 7,
									};

Tank::Tank()
{
	hullISize = 24;
	turretISize = 24;
	tracksISize = 48;
	gunISize = 24;
	hullAngle = 0;
	turretAngle = 0;
}

void Tank::draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	hullAngle += 0.02;
	if (hullAngle > 360)
		hullAngle -= 360;
	glTranslatef(0, 0, -10);
	drawHull();
	drawTurret();
	drawTracks();
	drawGun();
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Tank::drawHull()
{
	glVertexPointer(3, GL_FLOAT, 0, hullVertices);
	glPushMatrix();
	glRotatef(hullAngle, 1.0, 1.0, 1.0);
	glColor3f(0.2, 0.7, 0.2);

	glDrawElements(GL_QUADS, hullISize, GL_UNSIGNED_INT, hullIndices);
	glPopMatrix();	
}

void Tank::drawTurret()
{
	glVertexPointer(3, GL_FLOAT, 0, turretVertices);
	glPushMatrix();
	glRotatef(hullAngle, 1.0, 1.0, 1.0);
	glColor3f(1, 0.0, 0.0);

	glDrawElements(GL_QUADS, turretISize, GL_UNSIGNED_INT, turretIndices);
	glPopMatrix();
}

void Tank::drawGun()
{
	glVertexPointer(3, GL_FLOAT, 0, gunVertices);
	glPushMatrix();
	glRotatef(hullAngle, 1.0, 1.0, 1.0);
	glColor3f(1, 0.0, 0.8);

	glDrawElements(GL_QUADS, gunISize, GL_UNSIGNED_INT, gunIndices);
	glPopMatrix();
}

void Tank::drawTracks()
{
	glVertexPointer(3, GL_FLOAT, 0, tracksVertices);
	glPushMatrix();
	glRotatef(hullAngle, 1.0, 1.0, 1.0);
	glColor3f(0.1, 0.5, 1.0);

	glDrawElements(GL_QUADS, tracksISize, GL_UNSIGNED_INT, tracksIndices);
	glPopMatrix();
}

Tank::~Tank()
{
}