// gcc main.c actions.c axes.c init.c lumiere.c switch_blend.c switch_light.c VM_init.c -lm -lGL -lGLU -lglut -o test.out

#include "init.h"
#include "axes.h"
#include "cube.h"
#include "VM_init.h"

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -5.0f;

GLvoid Modelisation()
{
    VM_init();
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
 	Cube *c = NULL;
 	c = (Cube *)malloc(sizeof(Cube));
 	creerCube(c, 1);
    drawCube(c);

    axes();
    glutSwapBuffers();

}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
