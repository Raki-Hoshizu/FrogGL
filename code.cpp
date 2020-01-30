// g++ code.cpp -o firstOpenGlApp -lglut -lGLU -lGL

#include <GL/glut.h>

void displayMe(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
		// face avant
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		// fac arrière
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		// face dessus
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f( 1.0f, 1.0f, 1.0f);
		glVertex3f( 1.0f, 1.0f, -1.0f);
		// face dessous
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f( 1.0f, -1.0f, -1.0f);
		glVertex3f( 1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		// face droite
		glVertex3f( 1.0f, -1.0f, -1.0f);
		glVertex3f( 1.0f, 1.0f, -1.0f);
		glVertex3f( 1.0f, 1.0f, 1.0f);
		glVertex3f( 1.0f, -1.0f, 1.0f);
		// face gauche
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1080, 720);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello world!");
	glutDisplayFunc(displayMe);
	glutMainLoop();
	return 0;
}