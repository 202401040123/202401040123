#include <iostream>
#include <GL/glut.h>
using namespace std;
// Initialize OpenGL
void init() {
glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Set up orthographic projection
}
// Function to perform flood fill algorithm
void floodFill(int x, int y, float* oldColor, float* newColor) {
float color[3];
// Read the pixel color at (x, y)
glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
// Check if the current pixel matches the old color and is not already filledwith the new color
if ((color[0] == oldColor[0] && color[1] == oldColor[1] && color[2] ==
oldColor[2]) &&
(color[0] != newColor[0] || color[1] != newColor[1] || color[2] !=
newColor[2])) {
// Set the color to the new color
glColor3f(newColor[0], newColor[1], newColor[2]);
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
glFlush();
// Recursively apply flood fill to neighboring pixels (limit recursiondepth to avoid stack overflow)
if (x < 640 && x > 0 && y < 480 && y > 0) {
floodFill(x + 1, y, oldColor, newColor); // Right
floodFill(x - 1, y, oldColor, newColor); // Left
floodFill(x, y + 2, oldColor, newColor); // Up
floodFill(x, y - 2, oldColor, newColor); // Down
}
}
}
void display() {
glClear(GL_COLOR_BUFFER_BIT);
// Draw a red boundary rectangle
glColor3f(1, 0, 0); // Red color for boundary
glBegin(GL_LINE_LOOP);
glVertex2i(200, 200);
glVertex2i(400, 200);
glVertex2i(400, 400);
glVertex2i(200, 400);
glEnd();
glFlush();
// Define old color (background color) and new fill color
float oldColor[] = {1, 1, 1}; // White (background)
float newColor[] = {0, 1, 0}; // Green (fill color)
// Start flood fill from a point inside the square
floodFill(300, 300, oldColor, newColor);
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(640, 480);
glutInitWindowPosition(200, 200);
glutCreateWindow("Flood Fill Algorithm - 8 connected");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
