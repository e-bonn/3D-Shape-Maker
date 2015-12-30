#include "GLShapeInterface.h"

GLShapeInterface::GLShapeInterface()
{
}

GLShapeInterface::~GLShapeInterface()
{
}

void GLShapeInterface::setLastPos(QPoint pt)
{
	m_lastPos = pt;
}

QPoint GLShapeInterface::getLastPos()
{
	return m_lastPos;
}

void GLShapeInterface::computeLocation() {
   double x = 2 * cos(0);     // my x-, y-, and z-coordinates
   double y = 2 * sin(0);
   double z = 0;
   double d = sqrt(x * x + y * y + z * z); // distance to origin

   glMatrixMode(GL_PROJECTION);        // Set projection parameters.
   glLoadIdentity();
   glFrustum(-d * 0.5, d * 0.5, -d * 0.5, d * 0.5, d - 1.1, d + 1.1);
}

void GLShapeInterface::init()
{
   GLfloat sun_direction[] = { 0.0, 2.0, -1.0, 1.0 };
   GLfloat sun_intensity[] = { 0.7, 0.7, 0.7, 1.0 };
   GLfloat ambient_intensity[] = { 0.3, 0.3, 0.3, 1.0 };

   glClearColor(1.0, 1.0, 1.0, 0.0);   // Set window color to white.
   computeLocation();

   glEnable(GL_DEPTH_TEST);            // Draw only closest surfaces

   glEnable(GL_LIGHTING);              // Set up ambient light.
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_intensity);

   glEnable(GL_LIGHT0);                // Set up sunlight.
   glLightfv(GL_LIGHT0, GL_POSITION, sun_direction);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_intensity);

   glEnable(GL_COLOR_MATERIAL);        // Configure glColor().
   glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}