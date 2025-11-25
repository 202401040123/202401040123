#include <GL/glut.h>
#include <math.h>

GLfloat angle = 0.0;

void rotateArrow() {
    GLfloat radian_angle = angle * M_PI / 180.0;

    GLfloat rotation_matrix[] = {
        cos(radian_angle), -sin(radian_angle), 0.0, 0.0,
        sin(radian_angle), cos(radian_angle),  0.0, 0.0,
        0.0,               0.0,                1.0, 0.0,
        0.0,               0.0,                0.0, 1.0
    };

    glMultMatrixf(rotation_matrix);
}

void drawArrow() {
    rotateArrow();

    glBegin(GL_POLYGON);
    // Arrowhead (triangle)
    glColor3f(1.0, 0.0, 0.0); // Red color
    glVertex3f(0.0f, 0.5f, 0.0f);
    glVertex3f(-0.2f, 0.2f, 0.0f);
    glVertex3f(0.2f, 0.2f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    // Arrow shaft (rectangle)
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glVertex3f(-0.1f, 0.2f, 0.0f);
    glVertex3f(0.1f, 0.2f, 0.0f);
    glVertex3f(0.1f, -0.5f, 0.0f);
    glVertex3f(-0.1f, -0.5f, 0.0f);
    glEnd();
}

void displayMe(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glLoadIdentity();
    drawArrow();

    angle += 0.1; // Increment the angle for rotation

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay(); // Ensure continuous animation
}

void initOpenGL() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotating Arrow");
    initOpenGL();
    glutDisplayFunc(displayMe);
    glutIdleFunc(displayMe); // Continuous animation
    glutMainLoop();
    return 0;
}
