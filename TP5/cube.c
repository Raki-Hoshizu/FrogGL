#include "cube.h"

// 0 : avant, 1 : arriere, 2 : droit, 3 : gauche, 4 : dessus, 5 : dessous
static int faces[][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {1, 4, 7, 2}, {0, 3, 6, 5}, {2, 7, 6, 3}, {1, 0, 5, 4}};
static int sommets[][3] = {{0, 3, 5}, {0, 2, 5}, {0, 2, 4}, {0, 3, 4}, {1, 2, 5}, {1, 3, 5}, {1, 3, 4}, {1, 2, 4}};

GLvoid creerCube(Cube *c, GLfloat taille)
{
	for (int i=0; i<8; ++i)
	{
		switch(sommets[i][0])
		{
			case 0:
				c->coord[i][2] = 0;
				break;
			case 1:
				c->coord[i][2] = taille;
				break;
		}
		switch(sommets[i][1])
		{
			case 3:
				c->coord[i][0] = 0;
				break;
			case 2:
				c->coord[i][0] = taille;
				break;
		}
		switch(sommets[i][2])
		{
			case 5:
				c->coord[i][1] = 0;
				break;
			case 4:
				c->coord[i][1] = taille;
				break;
		}
	}
}

GLvoid drawCube(Cube *c)
{
	glBegin(GL_QUADS);
	for (int i=0; i<6; ++i)
	{
		glColor3f(i/3.f, 1-(i/3.f), 1.0);
		glVertex3f(c->coord[faces[i][0]][0], c->coord[faces[i][0]][1], c->coord[faces[i][0]][2]);
		glVertex3f(c->coord[faces[i][1]][0], c->coord[faces[i][1]][1], c->coord[faces[i][1]][2]);
		glVertex3f(c->coord[faces[i][2]][0], c->coord[faces[i][2]][1], c->coord[faces[i][2]][2]);
		glVertex3f(c->coord[faces[i][3]][0], c->coord[faces[i][3]][1], c->coord[faces[i][3]][2]);
	}
	glEnd();
}