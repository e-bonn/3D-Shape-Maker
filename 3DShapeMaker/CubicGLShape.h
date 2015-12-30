#ifndef CUBICGLSHAPE_H
#define CUBICGLSHAPE_H

#include "GLShapeInterface.h"

class CubicGLShape : public GLShapeInterface
{
public:
	CubicGLShape();
	~CubicGLShape();

	virtual void draw();
};

#endif //CUBICGLSHAPE_H