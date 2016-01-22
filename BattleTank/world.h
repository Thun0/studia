#ifndef WORLD_H
#define WORLD_H

#include "glut.h"
#include <GL/gl.h>

class World
{
	GLuint floorTexture;
	const static GLfloat vertices[];
	const static GLfloat normals[];
	const static GLfloat uvData[];
	const static int map[10][10];
	void drawFloor();
	void drawSkybox();
	void drawMap();
public:
	void draw();
	void init();
	World();
	~World();
};

#endif