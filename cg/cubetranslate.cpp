#include <GL/glut.h>

// Translation values
float tx = 0.5, ty = 0.3;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Original Triangle (Red)
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5, -0.5);
        glVertex2f( 0.5, -0.5);
        glVertex2f( 0.0,  0.5);
    glEnd();

    // Translated Triangle (Blue)
    glColor3f(0, 0, 1);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5 + tx, -0.5 + ty);
        glVertex2f( 0.5 + tx, -0.5 + ty);
        glVertex2f( 0.0 + tx,  0.5 + ty);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1); // White background
    gluOrtho2D(-1, 1, -1, 1); // Normalized coordinates
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Triangle Translation");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
