// Write a program to display the following character A,E.F,H,I,K,L,M,N,T,V,W,X,Y,Z by using DDA Line drawing algorithm

#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

// Function to plot a point at (x, y)
void putPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// DDA Line Drawing Algorithm
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

// Function to draw character 'A'
void drawA(int x, int y) {
    DDA_Line(x, y, x + 20, y + 40);    // Left diagonal
    DDA_Line(x + 40, y, x + 20, y + 40); // Right diagonal
    DDA_Line(x + 10, y + 20, x + 30, y + 20); // Middle bar
}

// Function to draw character 'E'
void drawE(int x, int y) {
    DDA_Line(x, y, x, y + 40);  // Vertical bar
    DDA_Line(x, y + 40, x + 30, y + 40); // Top horizontal
    DDA_Line(x, y + 20, x + 20, y + 20); // Middle horizontal
    DDA_Line(x, y, x + 30, y);   // Bottom horizontal
}

// Function to draw character 'F'
void drawF(int x, int y) {
    DDA_Line(x, y, x, y + 40);  // Vertical bar
    DDA_Line(x, y + 40, x + 30, y + 40); // Top horizontal
    DDA_Line(x, y + 20, x + 20, y + 20); // Middle horizontal
}

// Function to draw character 'H'
void drawH(int x, int y) {
    DDA_Line(x, y, x, y + 40);  // Left vertical
    DDA_Line(x + 30, y, x + 30, y + 40); // Right vertical
    DDA_Line(x, y + 20, x + 30, y + 20); // Middle horizontal
}

// Function to draw character 'I'
void drawI(int x, int y) {
    DDA_Line(x + 15, y, x + 15, y + 40);  // Vertical bar
}

// Function to draw character 'K'
void drawK(int x, int y) {
    DDA_Line(x, y, x, y + 40);  // Left vertical
    DDA_Line(x + 30, y, x, y + 20); // Right diagonal down
    DDA_Line(x, y + 20, x + 30, y + 40); // Right diagonal up
}

// Function to draw character 'L'
void drawL(int x, int y) {
    DDA_Line(x, y, x, y + 40);  // Vertical bar
    DDA_Line(x, y, x + 30, y);   // Bottom horizontal
}

// Function to draw character 'M'
void drawM(int x, int y) {
    DDA_Line(x, y, x, y + 40);  // Left vertical
    DDA_Line(x + 30, y, x + 30, y + 40); // Right vertical
    DDA_Line(x, y + 40, x + 15, y);  // Left diagonal
    DDA_Line(x + 30, y + 40, x + 15, y); // Right diagonal
}

// Function to draw character 'N'
void drawN(int x, int y) {
    DDA_Line(x, y, x, y + 40);  // Left vertical
    DDA_Line(x + 30, y, x + 30, y + 40); // Right vertical
    DDA_Line(x, y + 40, x + 30, y);  // Diagonal
}

// Function to draw character 'T'
void drawT(int x, int y) {
    DDA_Line(x + 15, y, x + 15, y + 40);  // Vertical bar
    DDA_Line(x, y + 40, x + 30, y + 40);  // Top horizontal
}

// Function to draw character 'V'
void drawV(int x, int y) {
    DDA_Line(x, y + 40, x + 15, y);  // Left diagonal
    DDA_Line(x + 15, y, x + 30, y + 40); // Right diagonal
}

// Function to draw character 'W'
void drawW(int x, int y) {
    DDA_Line(x, y + 40, x + 10, y);  // Left diagonal
    DDA_Line(x + 10, y, x + 20, y + 20); // Middle diagonal up
    DDA_Line(x + 20, y + 20, x + 30, y); // Middle diagonal down
    DDA_Line(x + 30, y, x + 40, y + 40); // Right diagonal
}

// Function to draw character 'X'
void drawX(int x, int y) {
    DDA_Line(x, y, x + 30, y + 40);  // Left diagonal
    DDA_Line(x, y + 40, x + 30, y);  // Right diagonal
}

// Function to draw character 'Y'
void drawY(int x, int y) {
    DDA_Line(x, y + 40, x + 15, y + 20);  // Left diagonal
    DDA_Line(x + 30, y + 40, x + 15, y + 20);  // Right diagonal
    DDA_Line(x + 15, y, x + 15, y + 20);  // Vertical bar
}

// Function to draw character 'Z'
void drawZ(int x, int y) {
    DDA_Line(x, y + 40, x + 30, y + 40);  // Top horizontal
    DDA_Line(x + 30, y + 40, x, y);  // Diagonal
    DDA_Line(x, y, x + 30, y);  // Bottom horizontal
}

// Display function for rendering all characters
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Drawing characters on screen
    drawA(10, 300);   // A
    drawE(70, 300);   // E
    drawF(130, 300);  // F
    drawH(190, 300);  // H
    drawI(250, 300);  // I
    drawK(310, 300);  // K
    drawL(370, 300);  // L
    drawM(430, 300);  // M
    drawN(490, 300);  // N
    drawT(10, 200);   // T
    drawV(70, 200);   // V
    drawW(130, 200);  // W
    drawX(190, 200);  // X
    drawY(250, 200);  // Y
    drawZ(310, 200);  // Z

    glFlush();
}

// Initialization for OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Background color white
    glColor3f(0.0, 0.0, 0.0);          // Draw color black
    glPointSize(2.0);                  // Point size for lines
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0); // Coordinate system
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Characters using DDA Line Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
