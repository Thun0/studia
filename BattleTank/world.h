#ifndef WORLD_H
#define WORLD_H

#include "glut.h"
#include "enemy.h"
#include <GL/gl.h>
#include <vector>
#include "projectile.h"

class World
{
	GLuint floorTexture;
	GLuint wallTexture;
	GLuint skyTexture;
	const static GLfloat vertices[];
	const static GLfloat normals[];
	const static GLfloat uvData[];
	const static GLfloat wallVertices[];
	const static GLfloat wallNormals[];
	const static GLfloat uvWallData[];
	const static GLfloat skyboxVertices[];
	const static GLfloat skyboxNormals[];
	const static GLfloat uvSkyboxData[];
	void drawFloor();
	void drawMap();
	void drawProjectiles();
	void drawEnemies();
	void drawSkybox();
public:
	std::vector<Projectile> projectiles;
	std::vector<Enemy> enemies;
	const static int MAP_SIZE;
	const static int WALL_SIZE;
	const static int SKY_SIZE;
	const static int map[20][20];
	void draw();
	void init();
	void update(int);
	World();
	~World();
};

#endif