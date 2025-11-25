// Write a program to display house as per your imagination by using DDA line drawing algorithm.

#include <GL/glut.h>
#include <cmath>

// Function to plot a point at (x, y)
void putPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// DDA Line Drawing Algorithm
void drawline(int x1, int y1, int x2, int y2) {
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

// Display function to draw the house using DDA
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the base of the house (square)
    drawline(100, 100, 200, 100);  // Bottom side
    drawline(200, 100, 200, 200);  // Right side
    drawline(200, 200, 100, 200);  // Top side
    drawline(100, 200, 100, 100);  // Left side

    // Draw the roof (triangle)
    drawline(100, 200, 150, 250);  // Left slant of roof
    drawline(150, 250, 200, 200);  // Right slant of roof

    // Draw a door
    drawline(130, 100, 130, 150);  // Left side of door
    drawline(130, 150, 170, 150);  // Top of door
    drawline(170, 150, 170, 100);  // Right side of door

    // Draw windows (two square windows)
    drawline(110, 160, 130, 160);  // Left window bottom side
    drawline(130, 160, 130, 180);  // Left window right side
    drawline(130, 180, 110, 180);  // Left window top side
    drawline(110, 180, 110, 160);  // Left window left side

    drawline(170, 160, 190, 160);  // Right window bottom side
    drawline(190, 160, 190, 180);  // Right window right side
    drawline(190, 180, 170, 180);  // Right window top side
    drawline(170, 180, 170, 160);  // Right window left side

    glFlush();
}

// Initialization for OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // White background
    glColor3f(0.0, 0.0, 0.0);          // Black drawing color
    glPointSize(2.0);                  // Set point size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 300.0, 0.0, 300.0); // Coordinate system
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("House using DDA Line Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
