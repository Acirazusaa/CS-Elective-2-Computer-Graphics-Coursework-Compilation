#include <iostream>
#include <GL/glut.h>

void display(){



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


