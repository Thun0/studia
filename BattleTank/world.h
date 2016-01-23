#ifndef WORLD_H
#define WORLD_H

#include "glut.h"
#include <GL/gl.h>

class World
{
	GLuint floorTexture;
	GLuint wallTexture;
	const static int MAP_SIZE;
	const static int WALL_SIZE;
	const static GLfloat vertices[];
	const static GLfloat normals[];
	const static GLfloat uvData[];
	const static GLfloat World::wallVertices[];
	const static GLfloat World::wallNormals[];
	const static GLfloat World::uvWallData[];
	const static int map[20][20];
	void drawFloor();
	void drawMap();
public:
	void draw();
	void init();
	World();
	~World();
};

#endif