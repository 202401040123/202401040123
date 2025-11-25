// Develop a program to draw a triangle using OpenGL

#include<GL/glut.h>

void init(){
    glClearColor(0,0,0, 1.0);
    gluOrtho2D(-250, 250, -250, 250);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.4, 0.7);
    glVertex2i(-100,-75);
    glColor3f(0.4, 0.9, 0.1);
    glVertex2i(0, 75);
    glColor3f(0.5, 0.6, 0.1);
    glVertex2i(100, -75);
    glEnd();

    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Print Triangle");
    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}



