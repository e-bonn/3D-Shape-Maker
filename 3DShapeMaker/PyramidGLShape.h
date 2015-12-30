#ifndef PYRAMIDGLSHAPE_H
#define PYRAMIDGLSHAPE_H

#include "GLShapeInterface.h"

class PyramidGLShape : public GLShapeInterface
{
public:
	PyramidGLShape();
	~PyramidGLShape();

	virtual void draw();
};

#endif //PYRAMIDGLSHAPE_H