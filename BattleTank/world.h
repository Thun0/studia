#ifndef WORLD_H
#define WORLD_H

#include "glut.h"
#include <GL/gl.h>
#include <vector>
#include "projectile.h"

class World
{
	GLuint floorTexture;
	GLuint wallTexture;
	const static GLfloat vertices[];
	const static GLfloat normals[];
	const static GLfloat uvData[];
	const static GLfloat wallVertices[];
	const static GLfloat wallNormals[];
	const static GLfloat uvWallData[];
	void drawFloor();
	void drawMap();
	void drawProjectiles();
public:
	std::vector<Projectile> projectiles;
	const static int MAP_SIZE;
	const static int WALL_SIZE;
	const static int map[20][20];
	void draw();
	void init();
	void update(int);
	World();
	~World();
};

#endif