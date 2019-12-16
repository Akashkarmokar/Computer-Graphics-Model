#include<bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
#define pi 3.14159265
using namespace std;
int num ;
vector<pair<double,double> > input_v;
vector<pair<double,double> > output_v;
double tx,ty,theta,S_x,S_y;
void input_fun()
{
    cout<<"Enter your points co-ordinate indexs:"<<endl;
    for(int i=0;i<num;i++)
    {
        double x,y;
        cin>>x>>y;
        input_v.push_back(make_pair(x,y));
    }
}
void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_LINES);
   glColor3f(1,0,1);
   glVertex2d(-200,0);
   glVertex2d(200,0);
   glVertex2d(0,-200);
   glVertex2d(0,200);
   glEnd();

    glColor3f(0,1,1);
   glBegin(GL_LINE_LOOP);
   for(int i = 0;i<input_v.size();i++)
   {
        glVertex2d(input_v[i].first,input_v[i].second);
   }
   glEnd();
   glBegin(GL_LINE_LOOP);
   glColor3f(1,0,0);
   for(int i = 0;i<output_v.size();i++)
   {
        glVertex2d(output_v[i].first,output_v[i].second);
   }
   glEnd();
   glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
   glutInitWindowSize(400, 300);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("Hello OpenGL");
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glOrtho(-200,200,-150,150,-2,2);

    cout<<"What your want : "<<endl;
    cout<<"IF Translation press : 1 "<<endl;
    cout<<"IF Rotation press : 2 "<<endl;
    cout<<"IF Scaling Translation press : 3 "<<endl;
    cout<<"IF Mirror Translation press : 4 "<<endl;
    int tmp = 0 ;
    cin>>tmp;
    if(tmp==1)
    {
        input_v.clear();
        output_v.clear();
        cout<<"HOW MANY NUMBERS : ";
        cin>>num;
        input_fun();
        cout<<"Enter tx and ty:"<<endl;
        cin>>tx>>ty;
        for(int i=0;i<num;i++)
        {
            double new_x = input_v[i].first+tx;
            double new_y = input_v[i].second+ty;
            //cout<<new_x<<" "<<new_y<<endl;
            output_v.push_back(make_pair(new_x,new_y));
        }

    }
    else if(tmp==2)
    {
        input_v.clear();
        output_v.clear();
        cout<<"HOW MANY NUMBERS : ";
        cin>>num;
        input_fun();
        cout<<"Enter theta value : "<<endl;
        cin>>theta;
        for(int i = 0 ;i<input_v.size();i++)
        {
            double new_x = input_v[i].first*cos(theta*pi/180.0)-input_v[i].second*sin(theta*pi/180.0);
            double new_y = input_v[i].first*sin(theta*pi/180.0)+input_v[i].second*cos(theta*pi/180.0);
            output_v.push_back(make_pair(new_x,new_y));
        }

    }
    else if(tmp==3)
    {
        input_v.clear();
        output_v.clear();
        cout<<"HOW MANY NUMBERS : ";
        cin>>num;
        input_fun();
        cout<<"Enter S_x & S_y value: ";
        cin>>S_x>>S_y;
        for(int i = 0 ;i<input_v.size();i++)
        {
            double new_x = S_x*input_v[i].first;
            double new_y = S_y*input_v[i].second;
            output_v.push_back(make_pair(new_x,new_y));
        }
    }
    else if(tmp==4)
    {
        input_v.clear();
        output_v.clear();
        cout<<"HOW MANY NUMBERS : ";
        cin>>num;
        input_fun();
        int tmpp= 0;
        cout<<"Which axis respect : "<<endl;
        cout<<"IF x-axis press : 1 "<<endl;
        cout<<"IF y-axis press : 2 "<<endl;
        cin>>tmpp;
        if(tmpp==1)
        {
            for(int i = 0 ;i<input_v.size();i++)
            {
                double new_x = input_v[i].first;
                double new_y = input_v[i].second*(-1);
                output_v.push_back(make_pair(new_x,new_y));
            }
        }
        else if(tmpp==2)
        {
            for(int i = 0 ;i<input_v.size();i++)
            {
                double new_x = input_v[i].first*(-1);
                double new_y = input_v[i].second;
                output_v.push_back(make_pair(new_x,new_y));
            }
        }
    }
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
/*
  2D translation code
  1.Translation
  2.Scaling
  3.Rotation
  4.Miror
*/
