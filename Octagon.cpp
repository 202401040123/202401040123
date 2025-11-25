#include <GL/glut.h>
#include <cmath>

void drawFilledOctagon() {
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0); // Set color to green (R, G, B)

    for (int i = 0; i < 8; ++i) {
        float angle = 2.0f * M_PI * i / 8.0f;
        float x = 0.5 * cosf(angle); // Radius is set to 0.5
        float y = 0.5 * sinf(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawFilledOctagon(); // Draw a filled green hexagon

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Filled Hexagon");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
