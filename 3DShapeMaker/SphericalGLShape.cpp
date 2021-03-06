#include <QtWidgets>
#include <QtOpenGL>
#include <GL/glu.h>

#include "SphericalGLShape.h"

SphericalGLShape::SphericalGLShape()
:	GLShapeInterface()
{
}

SphericalGLShape::~SphericalGLShape()
{
}

void SphericalGLShape::draw()
{
    glShadeModel(GL_SMOOTH);
    int i, j;
    int lats = 30;
    int longs = 30;
    for(i = 0; i <= lats; i++) {
        double lat0 = M_PI * (-0.5 + (double) (i - 1) / lats);
        double z0  = sin(lat0);
        double zr0 =  cos(lat0);

        double lat1 = M_PI * (-0.5 + (double) i / lats);
        double z1 = sin(lat1);
        double zr1 = cos(lat1);

        glBegin(GL_QUAD_STRIP);
        for(j = 0; j <= longs; j++) {
           double lng = 2 * M_PI * (double) (j - 1) / longs;
           double x = cos(lng);
           double y = sin(lng);

           glNormal3f(x * zr0, y * zr0, z0);
           glVertex3f(x * zr0, y * zr0, z0);
           glNormal3f(x * zr1, y * zr1, z1);
           glVertex3f(x * zr1, y * zr1, z1);
        }
        glEnd();
    }
}