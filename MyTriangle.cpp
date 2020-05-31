#include <GL/glew.h>
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#include <glm/glm.hpp> 
#include <iostream>
#include <stdio.h>
#include "MyTriangle.h"
using namespace glm;

MyTriangle :: MyTriangle(vec3 Point1 = {0.0, 0.0, 0.0}, vec3 Point2 = {0.0, 0.0, 0.0}, vec3 Point3 = {0.0, 0.0, 0.0}, vec3 pos = {0.0, 0.0, 0.0}, vec3 col = {0.0, 0.0, 0.0})
{
    vectors[0] = Point1;
    vectors[1] = Point2;
    vectors[2] = Point3;
    position = pos;
    color = col;
}

void MyTriangle::drawTriangle(vec3 pos, vec3 col, vec4 rot, bool init)
{
    //printf("%f, %f, %f...", pos[0], pos[1], pos[2]);
    if(init){
        glLoadIdentity();
    }
    glRotatef(rot[0], rot[1], rot[2], rot[3]);
    glTranslatef(pos[0], pos[1], pos[2]);    
    glBegin(GL_TRIANGLES);
    glColor3f(col[0], col[1], col[2]);
    glVertex3f(vectors[0][0], vectors[0][1], vectors[0][2]);
    glVertex3f(vectors[1][0], vectors[1][1], vectors[1][2]);
    glVertex3f(vectors[2][0], vectors[2][1], vectors[2][2]);
    glEnd();
}