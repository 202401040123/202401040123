// Write a program to display an arithmetic symbol and comparison operator by using DDA Line drawing algorithm.

#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

void putPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void DDA_Line(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float x_inc = dx / (float) steps;
    float y_inc = dy / (float) steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putPixel(round(x), round(y));
        x += x_inc;
        y += y_inc;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    // Arithmetic Symbol "+"
    DDA_Line(50, 100, 150, 100); // Horizontal line for "+"
    DDA_Line(100, 50, 100, 150); // Vertical line for "+"

    //Arithmatic symbol "-"
    DDA_Line(50, 200, 150, 200);

    //Arithmatic symbol " X "
    DDA_Line(250,300,300,350);
    DDA_Line(250,350,300,300);

    //Arithmatic operator "=."
    DDA_Line(50,275,100,275);
    DDA_Line(50,285,100,285);

    //Arithmatic symbol divison /
    DDA_Line(50,325,100,375);

    // Comparison Operator ">"
    DDA_Line(200, 100, 250, 150);
    DDA_Line(200, 100, 250, 50);


    //comparison Operator "<"
    DDA_Line(350,100,300,150);
    DDA_Line(350,100,300,50);

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Arithmetic Symbol and Comparison Operator using DDA Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
