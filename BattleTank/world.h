#ifndef WORLD_H
#define WORLD_H

#include "glut.h"
#include <GL/gl.h>

class World
{
	static GLfloat vertices[];
	static GLuint indices[];
	void drawFloor();
	void drawSkybox();
public:
	void draw();
	World();
	~World();
};

#endif