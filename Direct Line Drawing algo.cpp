#include<bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
double x11=2,y11=0,x21=50,y21=30;
double X,Y;
double m,b;
using namespace std;

int roundFunc(double poi)
{
    if(poi-(int)poi>=0.5)
        return (int)poi+1;
    else
        return (int)poi;
}
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   double m = (y21-y11)/(x21-x11);
   double b = y11 - m*x11;

   if(fabs(m)<1)
   {
       if(x11>x21)
       {
           swap(x11,x21);
           swap(y11,y21);
       }
       glBegin(GL_POINTS);
       glVertex2d(x11,roundFunc(y11));
       X = x11;
       while(X<x21)
       {
        X++;
        Y=m*X+b;
        glVertex2d(X,roundFunc(Y));
        printf("%lf %lf\n",X,Y);
       }
   }
   else
   {
        if(y11>y21)
        {
            swap(x11,x21);
            swap(y11,y21);
        }
        glBegin(GL_POINTS);
        glVertex2d(roundFunc(x11),y11);
        Y=y11;
        while(Y<=y21)
        {
            Y++;
            X=(Y-b)/m;
         glVertex2d(roundFunc(X),y11);
        }
   }
   glEnd();
   glFlush();

}
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(400, 300);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("Hello OpenGL");
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glutDisplayFunc(display);
   glOrtho(-200,200,-150,150,-9,9);
   glutMainLoop();
   return 0;
}
