#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
void display()
{
   int x1=50,y1=50,x2=100,y2=80;
   int dx=x2-x1,dy=y2-y1;
   int steps;
   float xin,yin;
   int x=x1,y=y1;
   float xn=x1,yn=y1;
   glClearColor(1.0,1.0,0.0,1.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(-200,200,-200,200);
   if(abs(dx)>abs(dy))
    steps=dx;
   else
    steps=dy;
   xin=dx/steps;
   yin=dy/steps;
   for(int i=0;i<steps;i++)
   {
       glColor3f(0.0,0.0,0.0);
       glBegin(GL_POINTS);
       glVertex2i(x,y);
       glEnd();
       xn=xn+xin;
       yn=yn+yin;
       x=int(xn);
       y=int(yn);
   }
   glFlush();


}
int main(int arge,char**argv)
{

    glutInit(&arge,argv);
    glutCreateWindow("DDA Line");
    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutDisplayFunc(display);
    glutMainLoop();
}
