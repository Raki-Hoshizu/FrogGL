// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test.o

#include "init.h"
#include "axes.h"
#include "VM_init.h"

GLfloat xrot = 0.0f;
GLfloat yrot = 0.0f;
GLfloat z = -5.0f; 

GLvoid Modelisation()
{
  VM_init();

  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.

  double paume = 2;
  double phalange = 1;
  double angle = 10;

  glPushMatrix();

    // Dessin de la paume
    glPushMatrix();
    glScalef(paume, paume, paume/3);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();

    // Déplacement pour la 1ere phalange
    glTranslatef(paume/4, paume/4, 0);
    glRotatef(angle, 1, 0, 0);
    glTranslatef(0, phalange/4, 0);

    // Dessin de la 1ere phalange
    glPushMatrix();
    glScalef(0.5, phalange, 0.5);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();

    // Déplacement pour la 2eme phalange
    glTranslatef(0, phalange/2, 0);
    glRotatef(angle, 1, 0, 0);

    // Dessin de la 2eme phalange
    glPushMatrix();
    glScalef(0.5, phalange, 0.5);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();

    glPopMatrix();
    glPushMatrix();

    // Déplacement pour la 1ere phalange
    glTranslatef(0, paume/4 + 0.2, 0);
    glRotatef(angle, 1, 0, 0);
    glTranslatef(0, phalange/4, 0);

    // Dessin de la 1ere phalange
    glPushMatrix();
    glScalef(0.5, phalange, 0.5);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();

    // Déplacement pour la 2eme phalange
    glTranslatef(0, phalange/2, 0);
    glRotatef(angle, 1, 0, 0);

    // Dessin de la 2eme phalange
    glPushMatrix();
    glScalef(0.5, phalange, 0.5);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();

    glPopMatrix();
    glPushMatrix();

    // Déplacement pour la 1ere phalange
    glTranslatef(-paume/4, paume/4 + 0.1, 0);
    glRotatef(angle, 1, 0, 0);
    glTranslatef(0, phalange/4, 0);

    // Dessin de la 1ere phalange
    glPushMatrix();
    glScalef(0.5, phalange, 0.5);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();

    // Déplacement pour la 2eme phalange
    glTranslatef(0, phalange/2, 0);
    glRotatef(angle, 1, 0, 0);

    // Dessin de la 2eme phalange
    glPushMatrix();
    glScalef(0.5, phalange, 0.5);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();

    glPopMatrix();
    glPushMatrix();

    // Déplacement pour la 1ere phalange
    glTranslatef(-paume/2.5, paume/4 - 0.4, 0);
    glRotatef(20, 0, 0, 1);
    glTranslatef(0, phalange/4, 0);

    // Dessin de la 1ere phalange
    glPushMatrix();
    glScalef(0.5, phalange, 0.5);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();

    // Déplacement pour la 2eme phalange
    glTranslatef(0, phalange/2, 0);
    glRotatef(angle, 1, 0, 0);

    // Dessin de la 2eme phalange
    glPushMatrix();
    glScalef(0.5, phalange, 0.5);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();

    glPopMatrix();
    glPushMatrix();

    // Déplacement pour la 1ere phalange
    glTranslatef(paume/3, paume/6 - 0.4, 0);
    glRotatef(-40, 0, 0, 1);
    glTranslatef(0, phalange/4, 0);

    // Dessin de la 1ere phalange
    glPushMatrix();
    glScalef(0.5, phalange, 0.5);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();

    // Déplacement pour la 2eme phalange
    glTranslatef(0, phalange/2, 0);
    glRotatef(angle, 1, 0, 0);

    // Dessin de la 2eme phalange
    glPushMatrix();
    glScalef(0.5, phalange, 0.5);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();

  glPopMatrix();

  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
