#include <GL/glut.h>
#include <cstdlib>

float faceColor[3] = {0.0, 0.0, 0.0}; // Initial random color

float leftEyeColor[3] = {1.0, 0.0, 0.0};  // Red
float rightEyeColor[3] = {0.0, 1.0, 0.0}; // Green

GLfloat facePositionX = 0.0;
GLfloat facePositionY = 0.0;

GLfloat leftEyePositionX = -0.1; // Adjusted for closer eyes
GLfloat leftEyePositionY = 0.1;

GLfloat rightEyePositionX = 0.1; // Adjusted for closer eyes
GLfloat rightEyePositionY = 0.1;

GLfloat faceVertices[] = {
    -0.5, -0.5,
    0.5, -0.5,
    0.5, 0.5,
    -0.5, 0.5
};

GLfloat leftEyeVertices[] = {
    -0.1, 0.1, // Adjusted for closer eyes
    -0.1, 0.2, // Adjusted for closer eyes
    -0.0, 0.2, // Adjusted for closer eyes
    -0.0, 0.1  // Adjusted for closer eyes
};

GLfloat rightEyeVertices[] = {
    0.1, 0.1, // Adjusted for closer eyes
    0.1, 0.2, // Adjusted for closer eyes
    0.0, 0.2, // Adjusted for closer eyes
    0.0, 0.1  // Adjusted for closer eyes
};

void drawFace() {
    glEnableClientState(GL_VERTEX_ARRAY);
    
    GLfloat translatedFaceVertices[8];
    for (int i = 0; i < 8; i += 2) {
        translatedFaceVertices[i] = faceVertices[i] + facePositionX;
        translatedFaceVertices[i + 1] = faceVertices[i + 1] + facePositionY;
    }

    glVertexPointer(2, GL_FLOAT, 0, translatedFaceVertices);

    // Draw the face
    glColor3fv(faceColor);
    glDrawArrays(GL_LINE_LOOP, 0, 4);

    // Draw the left eye
    GLfloat translatedLeftEyeVertices[8];
    for (int i = 0; i < 8; i += 2) {
        translatedLeftEyeVertices[i] = leftEyeVertices[i] + leftEyePositionX;
        translatedLeftEyeVertices[i + 1] = leftEyeVertices[i + 1] + leftEyePositionY;
    }
    glVertexPointer(2, GL_FLOAT, 0, translatedLeftEyeVertices);
    glColor3fv(leftEyeColor);
    glDrawArrays(GL_QUADS, 0, 4);

    // Draw the right eye
    GLfloat translatedRightEyeVertices[8];
    for (int i = 0; i < 8; i += 2) {
        translatedRightEyeVertices[i] = rightEyeVertices[i] + rightEyePositionX;
        translatedRightEyeVertices[i + 1] = rightEyeVertices[i + 1] + rightEyePositionY;
    }
    glVertexPointer(2, GL_FLOAT, 0, translatedRightEyeVertices);
    glColor3fv(rightEyeColor);
    glDrawArrays(GL_QUADS, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);

    // Draw Mouth
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
    else if (key == 'a') {
        facePositionX -= 0.1;
        leftEyePositionX -= 0.1;
        rightEyePositionX -= 0.1;
    } else if (key == 'd') {
        facePositionX += 0.1;
        leftEyePositionX += 0.1;
        rightEyePositionX += 0.1;
    } else if (key == 'w') {
        facePositionY += 0.1;
        leftEyePositionY += 0.1;
        rightEyePositionY += 0.1;
    } else if (key == 's') {
        facePositionY -= 0.1;
        leftEyePositionY -= 0.1;
        rightEyePositionY -= 0.1;
    }

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

