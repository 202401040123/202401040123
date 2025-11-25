#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

int startX, startY, endX, endY;

void plot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void DDA_Line() {
    int dx = endX - startX;
    int dy = endY - startY;
    int steps = max(abs(dx), abs(dy));

    float x_increment = static_cast<float>(dx) / steps;
    float y_increment = static_cast<float>(dy) / steps;

    float x = startX, y = startY;

    for (int i = 0; i < steps; ++i) {
        plot(static_cast<int>(round(x)), static_cast<int>(round(y)));
        x += x_increment;
        y += y_increment;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);  // Set color to white
    DDA_Line();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(0, 500, 0, 500, 1, -1);
}

int main(int argc, char** argv) {
    cout << "Enter the coordinates of the first point (startX startY): ";
    cin >> startX >> startY;

    cout << "Enter the coordinates of the second point (endX endY): ";
    cin >> endX >> endY;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
