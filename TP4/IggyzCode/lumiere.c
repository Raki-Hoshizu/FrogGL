#include "lumiere.h"
// gcc lumiere.cpp -c 
void lumiere() {
  GLfloat LightAmbient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
  GLfloat LightDiffuse[] = { 0.9f, 0.9f, 0.9f, 1.0f };
  GLfloat LightSpecular[] = { 0.9f, 0.9f, 0.9f, 1.0f };
  GLfloat LightPosition[] = { 2.0f, 0.0f, 0.0f, 1.0f };
  
  glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
  glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);
  glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
  glEnable(GL_LIGHT1);
}
