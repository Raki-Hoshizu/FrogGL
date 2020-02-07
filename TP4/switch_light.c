// gcc switch_light.cpp -c
#include "switch_light.h"

GLuint switch_light(GLuint light) { 
  light = light ? 0 : 1;
  if (!light) {
    glDisable(GL_LIGHTING);	
    glDisable(GL_COLOR_MATERIAL);
  } else {
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL); // Très important pour les couleurs soient préservées
  }
  return light;
}
