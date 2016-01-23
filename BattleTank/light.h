#ifndef LIGHT_H
#define LIGHT_H

#include "glut.h"
#include <GL/gl.h>

class Light
{
	float x;
	float y;
	float z;
	float intensity;
public:
	void init();
	void update();
	void increase();
	void decrease();
};

#endif