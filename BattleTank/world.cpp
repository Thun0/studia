#include "world.h"

GLfloat World::vertices[] = {
	-100, 0, -100,
	-100, 0, 100,
	100, 0, 100,
	100, 0, -100,
};
GLuint World::indices[] = {
	0, 1, 2, 3,
};

World::World()
{
}

World::~World()
{
}

void World::draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	drawFloor();
	drawSkybox();
	glDisableClientState(GL_VERTEX_ARRAY);
}

void World::drawFloor()
{
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glPushMatrix();
	glColor3f(0.2, 0.2, 0.2);

	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, indices);
	glPopMatrix();
}

void World::drawSkybox()
{

}