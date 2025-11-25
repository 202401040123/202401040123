// Draw a color cube and spin it using OpenGL transformation matrices.


#include <GL/glut.h>
#include <math.h>

GLfloat v0[] = { -0.5, -0.5, -0.5 };
GLfloat v1[] = { 0.5, -0.5, -0.5 };
GLfloat v2[] = { 0.5, 0.5, -0.5 };
GLfloat v3[] = { -0.5, 0.5, -0.5 };
GLfloat v4[] = { -0.5, 0.5, 0.5 };
GLfloat v5[] = { -0.5, -0.5, 0.5 };
GLfloat v6[] = { 0.5, -0.5, 0.5 };
GLfloat v7[] = { 0.5, 0.5, 0.5 };

GLfloat angle = 0.0;


void rotateCube()
{
    GLfloat radian_angle = angle * M_PI / 180.0;
    //GLfloat radian_angle = angle;

    GLfloat rotation_matrix[] =
    {
        cos(radian_angle), -sin(radian_angle), 0.0, 0.0,
        sin(radian_angle), cos(radian_angle), 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    };

    glMultMatrixf(rotation_matrix);
}

void drawCube()
{

    rotateCube();

    glBegin(GL_TRIANGLES);

    // Front face
    glColor3f(1.0, 0.0, 0.0);//red
    glVertex3fv(v0);
    glVertex3fv(v1);
    glVertex3fv(v2);

    glVertex3fv(v2);
    glVertex3fv(v3);
    glVertex3fv(v0);

    // Right face
    glColor3f(0.0, 1.0, 0.0);//green
    glVertex3fv(v0);
    glVertex3fv(v3);
    glVertex3fv(v4);

    glVertex3fv(v4);
    glVertex3fv(v5);
    glVertex3fv(v0);

    // Top face
    glColor3f(0.0, 0.0, 1.0);//blue
    glVertex3fv(v0);
    glVertex3fv(v5);
    glVertex3fv(v6);

    glVertex3fv(v6);
    glVertex3fv(v1);
    glVertex3fv(v0);

    // Back face
    glColor3f(1.0, 1.0, 0.0);//yellow
    glVertex3fv(v1);
    glVertex3fv(v6);
    glVertex3fv(v7);

    glVertex3fv(v7);
    glVertex3fv(v2);
    glVertex3fv(v1);

    // Left face
    glColor3f(0.0, 1.0, 1.0);//Teal
    glVertex3fv(v7);
    glVertex3fv(v4);
    glVertex3fv(v3);

    glVertex3fv(v3);
    glVertex3fv(v2);
    glVertex3fv(v7);

    // Bottom face
    glColor3f(1.0, 0.0, 1.0);//purple
    glVertex3fv(v4);
    glVertex3fv(v7);
    glVertex3fv(v6);

    glVertex3fv(v6);
    glVertex3fv(v5);
    glVertex3fv(v4);

    glEnd();

}


void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);



    glLoadIdentity();
    glRotatef(45.0, 1.0, 1.0, 0.0);

    drawCube();

    angle += 0.1;

    glFlush();

    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotating Cube");
    glutDisplayFunc(displayMe);
    glutIdleFunc(displayMe); //for continuous animation
    glutMainLoop();
    return 0;
}
