#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS); // Begin drawing a red rectangle
    glColor3f(0.0, 1.0, 0.0); // Set color to red (R, G, B)
    glVertex2f(-0.5, -0.5); // Define vertices (bottom-left)
    glVertex2f(0.5, -0.5);  // (bottom-right)
    glVertex2f(0.5, 0.5);   // (top-right)
    glVertex2f(-0.5, 0.5);  // (top-left)
    glEnd(); // End drawing the red rectangle

    glBegin(GL_QUADS); // Begin drawing a green rectangle
    glColor3f(1.0, 0.0, 0.0); // Set color to green (R, G, B)
    glVertex2f(0.5, 0.0); // Define vertices (bottom-left)
    glVertex2f(-0.5, 0.0);  // (bottom-right)
    glVertex2f(0.0, 0.5);   // (top-right)
    glVertex2f(0.0, -0.5);  // (top-left)
    glEnd(); // End drawing the green rectangle



    glFlush(); // Flush the OpenGL buffer
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Rectangles");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
