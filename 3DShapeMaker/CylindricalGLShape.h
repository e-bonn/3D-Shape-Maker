#ifndef CYLINDRICALGLSHAPE_H
#define CYLINDRICALGLSHAPE_H

#include "GLShapeInterface.h"

class CylindricalGLShape : public GLShapeInterface
{
public:
	CylindricalGLShape();
	~CylindricalGLShape();

	void drawCircle(float radius, float zCoord);

	virtual void draw();
};

#endif //CYLINDRICALGLSHAPE_H