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
	static GLfloat turretVertices[];
	static GLfloat tracksVertices[];
	static GLfloat gunVertices[];
	static float turretSpeed;
	static float turnSpeed;
	static float speed;
	void drawHull();
	void drawTurret();
	void drawTracks();
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