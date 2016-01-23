#include "utilities.h"
#include "world.h"

const int World::MAP_SIZE = 20;
const int World::WALL_SIZE = 2;

const GLfloat World::vertices[] = {
	100, 0, -100,
	100, 0, 100,
	-100, 0, 100,
	-100, 0, -100,
};

const GLfloat World::normals[] = {
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
};

const GLfloat World::uvData[] = {
	0.0f, 0.0f,
	0.0f, 8.0f,
	8.0f, 8.0f,
	8.0f, 0.0f
};

const int World::map[MAP_SIZE][MAP_SIZE] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};


const GLfloat World::wallVertices[] = {
	0, 0, 0,
	WALL_SIZE, 0, 0,
	WALL_SIZE, WALL_SIZE, 0,
	0, WALL_SIZE, 0,						//przod

	WALL_SIZE, 0, 0,
	WALL_SIZE, 0, -WALL_SIZE,
	WALL_SIZE, WALL_SIZE, -WALL_SIZE,
	WALL_SIZE, WALL_SIZE, 0,				//prawo

	0, 0, 0,
	0, WALL_SIZE, 0,
	0, WALL_SIZE, -WALL_SIZE,
	0, 0, -WALL_SIZE,						//lewo

	0, WALL_SIZE, 0,
	WALL_SIZE, WALL_SIZE, 0,
	WALL_SIZE, WALL_SIZE, -WALL_SIZE,
	0, WALL_SIZE, -WALL_SIZE,				//gora

	0, 0, -WALL_SIZE,
	WALL_SIZE, 0, -WALL_SIZE,
	WALL_SIZE, WALL_SIZE, -WALL_SIZE,
	0, WALL_SIZE, -WALL_SIZE,				//tyl
};

const GLfloat World::wallNormals[] = {
	0, 0, 1,
	0, 0, 1,
	0, 0, 1,
	0, 0, 1,

	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
	1, 0, 0,

	-1, 0, 0,
	-1, 0, 0,
	-1, 0, 0,
	-1, 0, 0,

	0, 1, 0,
	0, 1, 0,
	0, 1, 0,
	0, 1, 0,

	0, 0, -1,
	0, 0, -1,
	0, 0, -1,
	0, 0, -1,
};

const GLfloat World::uvWallData[] = {
	0, 0,
	0, 1,
	1, 1,
	1, 0,

	0, 0,
	1, 0,
	1, 1,
	0, 1,

	0, 0,
	0, 1,
	1, 1,
	1, 0,

	0, 0,
	0, 1,
	1, 1,
	1, 0,

	0, 0,
	0, 1,
	1, 1,
	1, 0,
};


World::World()
{}

World::~World()
{}

void World::init()
{
	floorTexture = loadTexture("bmp/floor.bmp");
	wallTexture = loadTexture("bmp/wall.bmp");
}

void World::draw()
{
	drawFloor();
	drawMap();
}

void World::drawFloor()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnable(GL_TEXTURE_2D);

	glPushMatrix(); 

	GLfloat params[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, params);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, params);

	glBindTexture(GL_TEXTURE_2D, floorTexture);
	
	glColor3f(1, 1, 1);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, uvData);
	glNormalPointer(GL_FLOAT, 0, normals);
	glDrawArrays(GL_QUADS, 0, 4);
		
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void World::drawMap()
{
	glEnable(GL_TEXTURE_2D);
	for (int i = 0; i < MAP_SIZE; ++i)
	{
		for (int j = 0; j < MAP_SIZE; ++j)
		{
			if (map[i][j])
			{
				glPushMatrix();

				GLfloat params[] = { 1.0f, 1.0f, 1.0f, 1.0f };
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, params);
				glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, params);

				glEnableClientState(GL_VERTEX_ARRAY);
				glEnableClientState(GL_TEXTURE_COORD_ARRAY);
				glEnableClientState(GL_NORMAL_ARRAY);
				glColor3f(1, 1, 1);
				glBindTexture(GL_TEXTURE_2D, wallTexture);
				glTranslatef(j*WALL_SIZE-20, 0, i*WALL_SIZE-18);
				glVertexPointer(3, GL_FLOAT, 0, wallVertices);
				glTexCoordPointer(2, GL_FLOAT, 0, uvWallData);
				glNormalPointer(GL_FLOAT, 0, wallNormals);
				glDrawArrays(GL_QUADS, 0, 20);
				glDisableClientState(GL_NORMAL_ARRAY);
				glDisableClientState(GL_TEXTURE_COORD_ARRAY);
				glDisableClientState(GL_VERTEX_ARRAY);
				glPopMatrix();		
			}
		}
	}
	glDisable(GL_TEXTURE_2D);
}