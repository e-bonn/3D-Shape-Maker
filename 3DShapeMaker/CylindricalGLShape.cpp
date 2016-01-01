#include <QtWidgets>
#include <QtOpenGL>
#include <math.h>

#include "CylindricalGLShape.h"

CylindricalGLShape::CylindricalGLShape()
:	GLShapeInterface()
{
}

CylindricalGLShape::~CylindricalGLShape()
{
}

void CylindricalGLShape::draw()
{
    int numMajor = 10;
    int numMinor = 20;
    float height = 2.0;
    float radius = 0.7;

    double majorStep = height / numMajor;
    double minorStep = 2.0 * M_PI / numMinor;
    int i, j;

    drawCircle(radius,height/2);

    for (i = 0; i < numMajor; ++i) {
        GLfloat z0 = 0.5 * height - i * majorStep;
        GLfloat z1 = z0 - majorStep;

        glBegin(GL_TRIANGLE_STRIP);
        for (j = 0; j <= numMinor; ++j) {
            double a = j * minorStep;
            GLfloat x = radius * cos(a);
            GLfloat y = radius * sin(a);
            glNormal3f(x / radius, y / radius, 0.0);
            glTexCoord2f(j / (GLfloat) numMinor, i / (GLfloat) numMajor);
            glVertex3f(x, y, z0);

            glNormal3f(x / radius, y / radius, 0.0);
            glTexCoord2f(j / (GLfloat) numMinor, (i + 1) / (GLfloat) numMajor);
            glVertex3f(x, y, z1);
        }
        glEnd();
    }
    drawCircle(radius,-height/2);
}

void CylindricalGLShape::drawCircle(float radius, float zCoord)
{
    float x1,y1,x2,y2;
    float angle;
     
    x1 = 0;
    y1 = 0;
     
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,zCoord);
     
    for (angle=1.0f;angle<361.0f;angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,zCoord);
    }
     
    glEnd();
}



