#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
void display()
{
    int x1=50,y1=50,y2=100,x2=100,x3=100,y3=10;
    int tx=-100,ty=-100;
    glClearColor(0.5,0.5,0.5,0.5);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200,200,-200,200);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
       glVertex2i(-200,0);
       glVertex2i(200,0);
    glEnd();
    glBegin(GL_LINES);
       glVertex2i(0,-200);
       glVertex2i(0,200);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
       glVertex2i(x1,y1);
       glVertex2i(x2,y2);
       glVertex2i(x3,y3);
    glEnd();
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
       glVertex2i(x1+tx,y1+ty);
       glVertex2i(x2+tx,y2+ty);
       glVertex2i(x3+tx,y3+ty);
    glEnd();
    glFlush();
}
int main(int argc, char **args)
{
    glutInit(&argc,args);
    glutCreateWindow("2d translation");
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,800);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutDisplayFunc(display);//call back function
    glutMainLoop();

}
