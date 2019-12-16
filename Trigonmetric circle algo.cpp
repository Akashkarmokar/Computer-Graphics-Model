#include<bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
//  Traigonmetry

#define pi 3.14159265
using namespace std;
double c_x,c_y,radius;

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
    double  value = radius/(sqrt(2));
    double x,y;
    double d_theta = 0.25 ; // If we increase it by one then for large radius we mis huge point to draw . so that we take small value and increase by this .
    glBegin(GL_POINTS);
    glVertex2d(c_x,c_y);
    for(double theta = 0;theta<=45;theta+=d_theta)
    {
        //y = sqrt(radius*radius - x*x);
        x=radius*cos(theta*pi/180.0);
        y=radius*sin(theta*pi/180.0);
        glVertex2d(round(x+c_x),round(y+c_y));
        glVertex2d(round(-x+c_x),round(y+c_y));
        glVertex2d(round(x+c_x),round(-y+c_y));
        glVertex2d(round(-x+c_x),round(-y+c_y));
        glVertex2d(round(y+c_x),round(x+c_y));
        glVertex2d(round(-y+c_x),round(x+c_y));
        glVertex2d(round(y+c_x),round(-x+c_y));
        glVertex2d(round(-y+c_x),round(-x+c_y));
    }
    glEnd();
   glFlush();
}
int main(int argc, char** argv) {
    cout<<"Enter center x and y:"<<endl;
    cin>>c_x>>c_y;
    cout<<"Enter the radius:"<<endl;
    cin>>radius;
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



