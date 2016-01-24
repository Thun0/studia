#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "glut.h"
#include <GL/gl.h>

class Projectile
{
	const static GLfloat vertices[];
	const static GLfloat normals[];
	float angle;
	float speed;
	float x;
	float y;
	float z;
public:
	void checkCollision();
	void draw();
	void update(int);
	Projectile(float, float, float);
};

#endif