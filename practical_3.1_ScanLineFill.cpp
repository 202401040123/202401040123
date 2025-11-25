// Develop a program to fill the polygon using scan line algorithm

#include <GL/glut.h>

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 500, 0, 500);
}

void setPixel(int x, int y, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void scanLineFill(int y, int edges[][2], int edgeCount, float fillColor[3]) {
    int intersections[10], count = 0;

    // Find intersections for the current scan line
    for (int i = 0; i < edgeCount; i++) {
        int x1 = edges[i][0], y1 = edges[i][1];
        int x2 = edges[(i + 1) % edgeCount][0], y2 = edges[(i + 1) % edgeCount][1];

        if ((y1 <= y && y2 > y) || (y2 <= y && y1 > y)) {
            intersections[count++] = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
        }
    }

    // Sort intersections
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (intersections[j] > intersections[j + 1]) {
                int temp = intersections[j];
                intersections[j] = intersections[j + 1];
                intersections[j + 1] = temp;
            }
        }
    }

    // Fill pixels between pairs of intersections
    for (int i = 0; i < count; i += 2) {
        for (int x = intersections[i]; x <= intersections[i + 1]; x++) {
            setPixel(x, y, fillColor[0], fillColor[1], fillColor[2]);
        }
    }
}

void drawPolygon() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(250, 400);
    glVertex2i(150, 200);
    glVertex2i(350, 200);
    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawPolygon();

    float fillColor[] = {0.0, 0.0, 1.0};
    int edges[][2] = {{250, 400}, {150, 200}, {350, 200}};
    int edgeCount = 3;

    for (int y = 200; y <= 400; y++) {
        scanLineFill(y, edges, edgeCount, fillColor);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Scan Line Fill - Triangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
