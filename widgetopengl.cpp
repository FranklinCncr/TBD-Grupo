#include "widgetopengl.h"
//#include <iostream>
#include <fstream>
#include <iostream>
using namespace std;
ifstream dbg;

WidgetOpenGL::WidgetOpenGL(QWidget *parent):QOpenGLWidget(parent)
{

}

void WidgetOpenGL::initializeGL()
{
    initializeOpenGLFunctions();
      glEnable(GL_DEPTH_TEST);


}

void WidgetOpenGL::resizeGL(int w, int h)
{

}

void WidgetOpenGL::paintGL()
{

    int numuser1=0;
    int numuser2=200;
    dbg.open("E:/Proyectos/QT/TBD/TBD/Jester/jester.csv");
    char linea[10];
    string str;
    double d;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(numuser1,numuser2,0,100,1,-1);
    glMatrixMode(GL_MODELVIEW);
    glColor3f(1.0,1.0,1.0);
    glPointSize(2);
    glBegin(GL_POINTS);

    for(int u=numuser1;u<=numuser2;u++) {
              dbg >> linea;
              for(int i=1;i<=100;i++){
                  dbg >> linea;
                  str=linea;
                  d=atof(str.c_str());
                  if(d!=0){
                     //cout<<user<<" "<<i<<endl;
                     glVertex2f(u, i);
                  }
              }
    }
    dbg.close();
    glEnd();
    glFlush();
    this->makeCurrent();

}



