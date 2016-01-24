#ifndef ENEMY_H
#define ENEMY_H

#include "glut.h"
#include <GL/gl.h>

class Enemy
{
	float hullAngle;
	float turretAngle;
	static GLfloat hullVertices[];
	static GLfloat hullNormals[];
	static GLfloat uvHullData[];
	static GLfloat turretVertices[];
	static GLfloat turretNormals[];
	static GLfloat uvTurretData[];
	static GLfloat gunVertices[];
	static GLfloat gunNormals[];
	static GLfloat uvGunData[];
	GLuint hullTexture;
	GLuint turretTexture;
	void drawHull();
	void drawTurret();
	void drawGun();
public:
	float x;
	float z;
	static float width;
	void init(float, float, float);
	void draw();
};

#endif