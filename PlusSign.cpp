#include <GL/glut.h>
#include <iostream>

using namespace std;

void myInit() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 500, 0, 250, -1, 1);
}

void draw_pixel(int x, int y, int color) {
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void draw_line(int x1, int y1, int x2, int y2) {
    int dx, dy, x, y, p;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    x = x1;
    y = y1;
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    if (dx > dy) {
        p = 2 * dy - dx;
        while (x != x2) {
            draw_pixel(x, y, 1);
            if (p > 0) {
                y = y + sy;
                p = p - 2 * dx;
            }
            p = p + 2 * dy;
            x = x + sx;
        }
    }
    else {
        p = 2 * dx - dy;
        while (y != y2) {
            draw_pixel(x, y, 1);
            if (p > 0) {
                x = x + sx;
                p = p - 2 * dy;
            }
            p = p + 2 * dx;
            y = y + sy;
        }
    }
}

void draw_cross() {
    glColor3f(0.0, 1.0, 1.0);
    draw_line(250, 50, 270, 50);
    draw_line(250, 50, 250, 110);
    draw_line(250, 110, 190, 110);
    draw_line(190, 110, 190, 130);
    draw_line(190, 130, 250, 130);
    draw_line(250, 130, 250, 200);
    draw_line(270, 50, 270, 110);
    draw_line(270, 110, 330, 110);
    draw_line(330, 110, 330, 130);
    draw_line(270, 130, 330, 130);
    draw_line(270, 130, 270, 200);
    draw_line(250, 200, 270, 200);
}

void myDisplay() {
    draw_cross();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Medical Plus Sign");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
