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
	static float turretSpeed;
	static float turnSpeed;
	static float speed;
	int hullISize;
	int turretISize;
	int tracksISize;
	int gunISize;
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