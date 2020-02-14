#ifndef __CUBE
#define __CUBE

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

typedef struct
{
	GLfloat coord[8][3];
} Cube;

GLvoid creerCube(Cube *c, GLfloat);
GLvoid drawCube(Cube *c);

#endif