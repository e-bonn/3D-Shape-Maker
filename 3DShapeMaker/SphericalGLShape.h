#ifndef SPHERICALGLSHAPE_H
#define SPHERICALGLSHAPE_H

#include "GLShapeInterface.h"

class SphericalGLShape : public GLShapeInterface
{
public:
	SphericalGLShape();
	~SphericalGLShape();

	virtual void draw();
};

#endif //SPHERICALGLSHAPE_H