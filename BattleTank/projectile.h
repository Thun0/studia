#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "glut.h"
#include <GL/gl.h>

class Projectile
{
	float angle;
	static float speed;
	float x;
	float y;
	float z;
public:
	void init();
	void draw();
	void update(int);
	Projectile();
	~Projectile();
};

#endif