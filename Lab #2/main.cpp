#include <iostream>
#include <GL/glut.h>

void display(){

	glClear(GL_COLOR_BUFFER_BIT);		
	
	glBegin(GL_POLYGON);
		glVertex2f(-0.30, 0);
		glVertex2f(-0.15f, -0.30f);
		glVertex2f(0.15f, -0.30f);
		glVertex2f(0.30, 0);
		glVertex2f(0.15f, 0.30f);		
		glVertex2f(-0.15f, 0.30f);
		glVertex2f(-0.30, 0);

	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	
	glutInit(&argc,argv);
	glutInitWindowSize(1024,768);
	glutInitWindowPosition(200,50);
	
	glutCreateWindow("My First OpenGL");
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}


