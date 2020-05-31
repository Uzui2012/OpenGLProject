#include <windows.h>  // For MS Windows

#include <GL/glew.h>
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h - OpenGL API/Library 

#include <glm/glm.hpp> // GLM, Maths functions library

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "MyTriangle.h"

using namespace std;
using namespace glm;

void InitOpenGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //Set background colour
    glEnable(GL_DEPTH_TEST);
}

void drawTriangle(vec3 triVec[3], vec3 pos, vec3 color)
{
    glLoadIdentity();   
    glTranslatef(0.0, 0.0, -5);
    glRotatef(0, 0.0, 1.0, 0.0);

    glBegin(GL_TRIANGLES);

    glColor3f(color[0], color[1], color[2]);
    glVertex3f(triVec[0][0], triVec[0][1], triVec[0][2]);
    glVertex3f(triVec[1][0], triVec[1][1], triVec[1][2]);
    glVertex3f(triVec[2][0], triVec[2][1], triVec[2][2]);

    glEnd();
} 

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //Begin of render frame
    //srand(time(0));
    //vec3 point1;
    //vec3 point2;
    
    //point1 = {rand() % 5, rand() % 5, 0};
    //point2 = {rand() % 5, rand() % 5, 0};
    //float X = point2.x - point1.x;
    //float Y = point2.y - point1.y;

    
    MyTriangle tri1 = MyTriangle({0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 1.0, 0.0}, {0.0, 0.0, -5}, {1.0, 1.0, 1.0});
    MyTriangle tri2 = MyTriangle({0.0, 0.0, 0.0}, {1.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, -5}, {1.0, 1.0, 1.0});
    glLoadIdentity();
    tri1.drawTriangle({0.0, 0.0, -5}, {1.0, 1.0, 1.0}, {0.0, 0.0, 0.0, 0.0}, false);
    tri2.drawTriangle({0.0, 0.0, -5}, {1.0, 1.0, 1.0}, {0.0, 0.0, 1.0, 0.0}, false);

    glutSwapBuffers(); //End of render frame
}

void DisplayIdle()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //Begin of render frame
    MyTriangle tri1 = MyTriangle({0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 1.0, 0.0}, {0.0, 0.0, -5}, {1.0, 1.0, 1.0});
    MyTriangle tri2 = MyTriangle({0.0, 0.0, 0.0}, {1.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, -5}, {1.0, 1.0, 1.0});
    tri1.drawTriangle({0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {1.0, 0.0, 1.0, 0.0}, false);
    tri2.drawTriangle({0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {1.0, 0.0, 1.0, 0.0}, false);
    glutSwapBuffers(); //End of render frame
}

void Reshape(int w, int h) //Occurs second, once, then when user changes window shape halts timer(), loops with display until window is no longer altered
{
    glViewport(0, 0, w, h);    // Updates window viewport with the passed API reshaped values
    glMatrixMode(GL_PROJECTION); // Changes matrix mode
    glLoadIdentity(); // Resets projection matrix
    gluPerspective(60, (GLdouble)w/h, 0.2, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

void Timer(int) //Occurs first, repeats, producing animation
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, Timer, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Project");
    glutDisplayFunc(Display);
    glutIdleFunc(DisplayIdle);
    glutReshapeFunc(Reshape);
    //glutTimerFunc(0, Timer, 0);
    InitOpenGL();

    glutMainLoop();
    
    return 0;
}