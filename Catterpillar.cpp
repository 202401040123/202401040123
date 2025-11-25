// Write a C++ program to display a Catterpillar

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

void displayBody(int xc,int yc,int radius){
    glColor3f(1.0f,1.0f,1.0f);
        int x = 0, y = radius;
    int d = 3 - 2 * radius;

    Plot(xc + x, yc + y);  // Octant 1
Plot(xc - x, yc + y);  // Octant 4
Plot(xc + x, yc - y);  // Octant 8
Plot(xc - x, yc - y);  // Octant 5
Plot(xc + y, yc + x);  // Octant 2
//Plot(xc - y, yc + x);  // Octant 3
Plot(xc + y, yc - x);  // Octant 7
//Plot(xc - y, yc - x);  // Octant 6


    while (x <= y) {
        if (d <= 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;

        // Plot all symmetric points in octants
        Plot(xc + x, yc + y);  // Octant 1
Plot(xc - x, yc + y);  // Octant 4
Plot(xc + x, yc - y);  // Octant 8
Plot(xc - x, yc - y);  // Octant 5
Plot(xc + y, yc + x);  // Octant 2
//Plot(xc - y, yc + x);  // Octant 3
Plot(xc + y, yc - x);  // Octant 7
//Plot(xc - y, yc - x);  // Octant 6

    }
}
void displayDetails(){
    //left eye
   drawcircle(60,275,7.5);
   //right eye
   drawcircle(90,275,7.5);
   //right ear
   drawcircle(105,300,10);
   //left ear
   drawcircle(45,300,10);

}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawcircle(75,250,50);//1 face
    displayBody(150,250,40);//2
    displayBody(210,250,35);//3
    displayBody(260,250,30);//4
    displayBody(300,250,20);//5
    displayDetails();
    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Catterpillar");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
