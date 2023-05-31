#include <GL/glut.h>
#include <stdio.h>

void drawLine(int x1, int y1, int x2, int y2)
{
   int dx, dy, p, x, y;

   dx = x2 - x1;
   dy = y2 - y1;

   x = x1;
   y = y1;

   p = 2 * dy - dx;

   glBegin(GL_POINTS);
   while (x < x2)
   {
      x++;
      if (p < 0)
         p += 2 * dy;
      else
      {
         y++;
         p += 2 * (dy - dx);
      }
      glVertex2i(x, y);
   }
   glEnd();
   glFlush();
}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   drawLine(100, 100, 500, 500);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(350, 350);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("Bresenham's Line Drawing");
   glClearColor(1.0, 1.0, 1.0, 0);
   glColor3f(0.0, 0.0, 0.0);
   gluOrtho2D(0, 500, 0, 500);
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
