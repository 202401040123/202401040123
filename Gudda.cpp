#include <GL/glut.h>
#include <iostream>
using namespace std;

int xc, yc, radius;

void Plot(int x, int y) {
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2i(x, y);
    glEnd();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void drawcircle(int xc, int yc, int radius) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    Plot(xc + x, yc + y);
    Plot(xc - x, yc + y);
    Plot(xc + x, yc - y);
    Plot(xc - x, yc - y);
    Plot(xc + y, yc + x);
    Plot(xc - y, yc + x);
    Plot(xc + y, yc - x);
    Plot(xc - y, yc - x);

    while (x <= y) {
        if (d <= 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;

        // Plot all symmetric points in octants
        Plot(xc + x, yc + y);
        Plot(xc - x, yc + y);
        Plot(xc + x, yc - y);
        Plot(xc - x, yc - y);
        Plot(xc + y, yc + x);
        Plot(xc - y, yc + x);
        Plot(xc + y, yc - x);
        Plot(xc - y, yc - x);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    //stomach
    drawcircle(200,200,100);
    //face
    drawcircle(200,350,50);
    //right eye
    drawcircle(225,350,7.5);
    //left eye
    drawcircle(175,350,7.5);
    //mouth
    drawcircle(200,325,25);
    //inside mouth
    drawcircle(200,330,7.5);
    //left ear
    drawcircle(140,380,20);
    //right ear
    drawcircle(260,380,20);
    //body
    drawcircle(200,200,50);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Teady Bear");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
