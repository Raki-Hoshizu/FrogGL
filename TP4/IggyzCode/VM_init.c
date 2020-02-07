// gcc VM_init.c -c
#include "VM_init.h"

extern GLfloat xrot;   // x rotation
extern GLfloat yrot;   // y rotation
extern GLfloat z; // depth into the screen.

/* The main drawing function. */
void VM_init()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
    glLoadIdentity();				// Reset The View

    glTranslatef(0.0f,0.0f,z);                  // move z units out from the screen.

    glRotatef(xrot,1.0f,0.0f,0.0f);		// Rotate On The X Axis
    glRotatef(yrot,0.0f,1.0f,0.0f);		// Rotate On The Y Axis

    glColor3f(1.0f, 1.0f, 1.0f);
}

