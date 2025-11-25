#include <iostream>
#include <GL/glut.h>
using namespace std;

int winWidth = 400;
int winHeight = 400;

void setPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawCircle(int xc, int yc, int r, float red, float green, float blue, int lineWidth)
{
    glColor3f(red, green, blue); // Set the circle color

    for (int width = 0; width < lineWidth; width++)
        {
        int x = 0;
        int y = r - width;
        int d = 3 - 2 * (r - width);

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

            x++;

            if (d > 0)
            {
                y--;
                d = d + 4 * (x - y) + 10;
            }
            else
            {
                d = d + 4 * x + 6;
            }
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawCircle(69, 200, 50, 0.0, 0.0, 0.0, 5);

    drawCircle(127, 200, 50, 0.0, 0.0, 0.0, 5);

    drawCircle(184, 200, 50, 0.0, 0.0, 0.0, 5);

    drawCircle(241, 200, 50, 0.0, 0.0, 0.0, 5);


    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Thicker Circle Drawing");

    glClearColor(1.0, 1.0, 1.0, 0.0); // Set background color to black
    glOrtho(0, winWidth, 0, winHeight, -1, 1);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
