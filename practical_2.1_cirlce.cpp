// Implement Bresenham’s circle drawing algorithm.

#include <iostream>
#include <GL/glut.h>

using namespace std;

int xc, yc, r;

void setPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;

    while (x <= y)
    {

        setPixel(xc + x, yc + y);
        setPixel(xc - x, yc + y);
        setPixel(xc + x, yc - y);
        setPixel(xc - x, yc - y);
        setPixel(xc + y, yc + x);
        setPixel(xc - y, yc + x);
        setPixel(xc + y, yc - x);
        setPixel(xc - y, yc - x);

        if (d < 0)
        {
            d += 4 * x + 6;
        }
        else
        {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    drawCircle(xc, yc, r);
    glFlush();
}

void init()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Circle");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(0, 800, 0, 800, -1, 1);
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
}

int main(int argc, char** argv)
{
    cout << "Enter the center coordinates (xc yc) and radius (r): ";
    cin >> xc >> yc >> r;

    glutInit(&argc, argv);
    init();
    glutMainLoop();

    return 0;
}
