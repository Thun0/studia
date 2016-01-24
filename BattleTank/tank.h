#ifndef TANK_H
#define TANK_H

#include "glut.h"
#include <GL/gl.h>

class Tank
{
	float hullAngle;
	float turretAngle;
	static float width;
	static GLfloat hullVertices[];
	static GLfloat hullNormals[];
	static GLfloat uvHullData[];
	static GLfloat turretVertices[];
	static GLfloat turretNormals[];
	static GLfloat uvTurretData[];
	static GLfloat gunVertices[];
	static GLfloat gunNormals[];
	static GLfloat uvGunData[];
	static float turretSpeed;
	static float turnSpeed;
	static float speed;
	GLuint hullTexture;
	GLuint turretTexture;
	void drawHull();
	void drawTurret();
	void drawGun();
	float x;
	float z;
	bool isForward;
	bool isBackward;
	bool isLeft;
	bool isRight;
	bool turretRight;
	bool turretLeft;
	void checkCollisions(float, float);
public:
	void init();
	void forward(bool);
	void backward(bool);
	void turnLeft(bool);
	void turnRight(bool);
	void turnTurretLeft(bool);
	void turnTurretRight(bool);
	void draw();
	void update(int);
	Tank();
	~Tank();
};

#endif