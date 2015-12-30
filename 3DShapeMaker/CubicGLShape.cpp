#include <QtWidgets>
#include <QtOpenGL>

#include "CubicGLShape.h"

CubicGLShape::CubicGLShape()
:	GLShapeInterface()
{
}

CubicGLShape::~CubicGLShape()
{
}

void CubicGLShape::draw()
{
    // front
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);     
        glVertex3f(-1, 1, 1);
        glVertex3f(-1, -1, 1);
        glVertex3f(1, -1, 1);
        glVertex3f(1, 1, 1);   
    glEnd();

    // back
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(-1, 1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, -1, -1);
        glVertex3f(-1, -1, -1);
    glEnd();

        // top 
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-1, 1, -1);
        glVertex3f(-1, 1, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(1, 1, -1);
    glEnd();
     
    // bottom
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(-1, -1, -1);
        glVertex3f(1, -1, -1);
        glVertex3f(1, -1, 1);
        glVertex3f(-1, -1, 1);
    glEnd();
     
    // left 
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-1, 1, -1);
        glVertex3f(-1, -1, -1);
        glVertex3f(-1, -1, 1);
        glVertex3f(-1, 1, 1);
    glEnd();
     
    // right
    glBegin(GL_POLYGON);
        glNormal3f(1,0,1);
        glVertex3f(1, 1, 1);
        glVertex3f(1, -1, 1);
        glVertex3f(1, -1, -1);
        glVertex3f(1, 1, -1);
    glEnd();
}