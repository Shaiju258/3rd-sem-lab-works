#include <GL/glut.h>

// Rotation angles
float angleX = 0, angleY = 0;

// Draw cube with different colored faces
void drawCube() {
    glBegin(GL_QUADS);

    // Front (Red)
    glColor3f(1, 0, 0);
    glVertex3f(1, 1, 1); glVertex3f(-1, 1, 1);
    glVertex3f(-1, -1, 1); glVertex3f(1, -1, 1);

    // Back (Green)
    glColor3f(0, 1, 0);
    glVertex3f(1, 1, -1); glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1); glVertex3f(1, -1, -1);

    // Top (Blue)
    glColor3f(0, 0, 1);
    glVertex3f(1, 1, 1); glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1); glVertex3f(1, 1, -1);

    // Bottom (Yellow)
    glColor3f(1, 1, 0);
    glVertex3f(1, -1, 1); glVertex3f(-1, -1, 1);
    glVertex3f(-1, -1, -1); glVertex3f(1, -1, -1);

    // Right (Magenta)
    glColor3f(1, 0, 1);
    glVertex3f(1, 1, 1); glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1); glVertex3f(1, 1, -1);

    // Left (Cyan)
    glColor3f(0, 1, 1);
    glVertex3f(-1, 1, 1); glVertex3f(-1, -1, 1);
    glVertex3f(-1, -1, -1); glVertex3f(-1, 1, -1);

    glEnd();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0, 0, -6); // Move cube into view

    // Apply rotation
    glRotatef(angleX, 1, 0, 0);
    glRotatef(angleY, 0, 1, 0);

    drawCube();

    glutSwapBuffers();
}

// Arrow key controls
void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_UP) angleX -= 5;
    else if (key == GLUT_KEY_DOWN) angleX += 5;
    else if (key == GLUT_KEY_LEFT) angleY -= 5;
    else if (key == GLUT_KEY_RIGHT) angleY += 5;

    glutPostRedisplay();
}

// Initialize settings
void init() {
    glEnable(GL_DEPTH_TEST);        // Enable depth
    glClearColor(0, 0, 0, 1);       // Black background
}

// Handle window resizing
void reshape(int w, int h) {
    if (h == 0) h = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 1, 100);

    glMatrixMode(GL_MODELVIEW);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("3D Rotating Cube");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}
