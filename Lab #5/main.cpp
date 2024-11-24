#include <GL/glut.h>
#include <cstdlib>

float faceColor[3] = {0.0, 0.0, 0.0}; // Initial random color

float leftEyeColor[3] = {1.0, 0.0, 0.0};  // Red
float rightEyeColor[3] = {0.0, 1.0, 0.0}; // Green

float facePositionX = 0.0;
float facePositionY = 0.0;

void drawFace() {
    // Draw the face
    glColor3fv(faceColor);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.5 + facePositionX, -0.5 + facePositionY); // Bottom-left vertex
    glVertex2f(0.5 + facePositionX, -0.5 + facePositionY);  // Bottom-right vertex
    glVertex2f(0.5 + facePositionX, 0.5 + facePositionY);   // Top-right vertex
    glVertex2f(-0.5 + facePositionX, 0.5 + facePositionY);  // Top-left vertex
    glEnd();

    // Draw the left eye
    glColor3fv(leftEyeColor);
    glBegin(GL_QUADS);
    glVertex2f(-0.2 + facePositionX, 0.1 + facePositionY);
    glVertex2f(-0.2 + facePositionX, 0.2 + facePositionY);
    glVertex2f(-0.1 + facePositionX, 0.2 + facePositionY);
    glVertex2f(-0.1 + facePositionX, 0.1 + facePositionY);
    glEnd();

    // Draw the right eye
    glColor3fv(rightEyeColor);
    glBegin(GL_QUADS);
    glVertex2f(0.2 + facePositionX, 0.1 + facePositionY);
    glVertex2f(0.2 + facePositionX, 0.2 + facePositionY);
    glVertex2f(0.1 + facePositionX, 0.2 + facePositionY);
    glVertex2f(0.1 + facePositionX, 0.1 + facePositionY);
    glEnd();
    
    glColor3fv(faceColor);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.2 + facePositionX, -0.2 + facePositionY);
    glVertex2f(0.2 + facePositionX, -0.2 + facePositionY);
    glEnd();

    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawFace();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27) // ESC key
        exit(0);
    else if (key == 'a')
        facePositionX -= 0.1;
    else if (key == 'd')
        facePositionX += 0.1;
    else if (key == 'w')
        facePositionY += 0.1;
    else if (key == 's')
        facePositionY -= 0.1;

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Change left eye color (random color)
        leftEyeColor[0] = static_cast<float>(rand()) / RAND_MAX;
        leftEyeColor[1] = static_cast<float>(rand()) / RAND_MAX;
        leftEyeColor[2] = static_cast<float>(rand()) / RAND_MAX;
    } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        // Change right eye color (random color)
        rightEyeColor[0] = static_cast<float>(rand()) / RAND_MAX;
        rightEyeColor[1] = static_cast<float>(rand()) / RAND_MAX;
        rightEyeColor[2] = static_cast<float>(rand()) / RAND_MAX;
    }

    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Face Drawing");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glClearColor(1.0, 1.0, 1.0, 1.0);

    glutMainLoop();
    return 0;
}

