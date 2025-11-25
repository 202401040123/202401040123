#include <GL/glut.h>

void displayMe(void)

{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
        glColor3f(1.0,1.0,0.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.15, 0.15);
        glVertex2f(0.0,1.0);
        glVertex2f(-0.20, 0.20);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.20, 0.20);
        glVertex2f(1.0,0.0);
        glVertex2f(0.20, -0.20);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0,1.0,0.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.20, -0.20);
        glVertex2f(0.0,-1.0);
        glVertex2f(-0.20, -0.20);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0,0.0,1.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(-0.20, 0.20);
        glVertex2f(-1.0,0.0);
        glVertex2f(-0.20, -0.20);
    glEnd();


    glFlush();
}
int main(int argc, char ** argv)
{
glutInit(&argc, argv);

glutInitDisplayMode (GLUT_SINGLE);
glutInitWindowSize (1200, 1200);
glutInitWindowPosition (800, 50);
glutCreateWindow("SAMPLE TEST");
glutDisplayFunc (displayMe);
glutMainLoop();

return 0;

}

