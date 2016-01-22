#include "utilities.h"
#include "world.h"

const GLfloat World::vertices[] = {
	100, 0, -100,
	100, 0, 100,
	-100, 0, 100,
	-100, 0, -100,
};

const GLfloat World::normals[] = {
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
};

const GLfloat World::uvData[] = {
	0.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	1.0f, 0.0f
};

const int World::map[10][10] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

World::World()
{}

World::~World()
{}

void World::init()
{
	floorTexture = loadTexture("bmp/floor.bmp");
}

void World::draw()
{
	drawFloor();
	/*glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	drawMap();
	drawSkybox();
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);*/
}

void World::drawFloor()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnable(GL_TEXTURE_2D);

	glPushMatrix(); 

	GLfloat params[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glBindTexture(GL_TEXTURE_2D, floorTexture);


	glTranslatef(0, -500, 0);

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

void World::drawSkybox()
{
}

void World::drawMap()
{

}