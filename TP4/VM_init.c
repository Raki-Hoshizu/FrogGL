// gcc VM_init.c -c
#include "VM_init.h"
#include <stdio.h>
#include <string.h>

extern GLfloat xrot;   // x rotation
extern GLfloat yrot;   // y rotation
extern GLfloat z; // depth into the screen.
extern GLfloat anglePyramid;

int time, fps = -1;
int frame = 0;

void displayFPS(int x, int y, int z)
{
	frame++;
	int actualTime=glutGet(GLUT_ELAPSED_TIME);

	char result[10];

	if (actualTime - time > 1000) {
		fps = frame*1000.0/(actualTime-time);

		printf("%d \n", fps);

	 	time = actualTime;
		frame = 0;
	}
}

/* The main drawing function. */
void VM_init()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
    glLoadIdentity();				// Reset The View

	displayFPS(10, 10, z);

    glTranslatef(0.0f,0.0f,z);                  // move z units out from the screen.


    glRotatef(anglePyramid, 0.0f, 1.0f, 0.0f);

    glRotatef(xrot,1.0f,0.0f,0.0f);		// Rotate On The X Axis
    glRotatef(yrot,0.0f,1.0f,0.0f);		// Rotate On The Y Axis

    glColor3f(1.0f, 1.0f, 1.0f);
}

