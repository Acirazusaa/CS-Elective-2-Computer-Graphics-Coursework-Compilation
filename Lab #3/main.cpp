#include <iostream>
#include <GL/glut.h>

void display(){

	glClear(GL_COLOR_BUFFER_BIT);	
	
	glBegin(GL_TRIANGLES);
		glVertex2f(0.30, 0);
		glColor3ub(0,0,132);
		glVertex2f(0.0f, 0.30f);
		glColor3ub(0,0,132);
		glVertex2f(-0.0f, -0.30f);
		glColor3ub(0,0,132);
		
		glVertex2f(-0.30, 0);
		glColor3ub(240,240,132);
		glVertex2f(0.0f, 0.30f);
		glColor3ub(240,240,132);			
		glVertex2f(-0.0f, -0.30f);
		glColor3ub(240,240,132);
	
		glVertex2f(-0.30, 0);
		glColor3ub(180,111,112);	
		glVertex2f(-0.15f, -0.30f);
		glColor3ub(180,111,112);
		glVertex2f(0.15f, -0.30f);
		glColor3ub(180,111,112);	
		
		glVertex2f(-0.30, 0);
		glColor3ub(241,10,67);
		glVertex2f(0.15f, 0.30f);
		glColor3ub(241,10,67);
		glVertex2f(-0.15f, 0.30f);	
		glColor3ub(241,10,67);		
		
		glVertex2f(0.30, 0);
		glColor3ub(79,156,145);
		glVertex2f(0.15f, 0.30f);
		glColor3ub(79,156,145);			
		glVertex2f(-0.15f, 0.30f);
		glColor3ub(79,156,145);
		
		glVertex2f(0.30, 0);
		glColor3ub(185,11,217);
		glVertex2f(0.15f, -0.30f);	
		glColor3ub(185,11,217);		
		glVertex2f(-0.15f, -0.30f);
		glColor3ub(185,11,217);
		
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


