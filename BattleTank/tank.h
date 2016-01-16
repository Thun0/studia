#ifndef TANK_H
#define TANK_H

#include "glut.h"
#include <GL/gl.h>

class Tank
{
	float hullAngle;
	float turretAngle;
	static GLfloat hullVertices[];
	static GLuint hullIndices[];
	static GLfloat turretVertices[];
	static GLuint turretIndices[];
	static GLfloat tracksVertices[];
	static GLuint tracksIndices[];
	static GLfloat gunVertices[];
	static GLuint gunIndices[];
	int hullISize;
	int turretISize;
	int tracksISize;
	int gunISize;
	void drawHull();
	void drawTurret();
	void drawTracks();
	void drawGun();
public:
	void draw();
	Tank();
	~Tank();
};

#endif