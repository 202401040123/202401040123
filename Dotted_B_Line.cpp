#include <GL/glut.h>
#include <cmath>

void draw_pixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void dotted_bresenham_line(int x1, int y1, int x2, int y2) {
    int dx, dy, x, y, p;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    x = x1;
    y = y1;
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int dotCounter = 0;
    int dotSpacing = 5; // Adjust the spacing between dots

    if (dx > dy) {
        p = 2 * dy - dx;
        while (x != x2) {
            if (dotCounter >= dotSpacing) {
                draw_pixel(x, y);
                dotCounter = 0;
            } else {
                dotCounter++;
            }
            if (p > 0) {
                y = y + sy;
                p = p - 2 * dx;
            }
            p = p + 2 * dy;
            x = x + sx;
        }
    } else {
        p = 2 * dx - dy;
        while (y != y2) {
            if (dotCounter >= dotSpacing) {
                draw_pixel(x, y);
                dotCounter = 0;
            } else {
                dotCounter++;
            }
            if (p > 0) {
                x = x + sx;
                p = p - 2 * dy;
            }
            p = p + 2 * dx;
            y = y + sy;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white

    // Draw a dotted Bresenham line with increased spacing
    dotted_bresenham_line(50, 50, 200, 150);

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set clear color to black
    glOrtho(0, 400, 0, 300, 1, -1);        // Set the coordinate system
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Dotted Bresenham Line with Increased Spacing");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
