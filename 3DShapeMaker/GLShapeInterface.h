#ifndef GLSHAPEINTERFACE_H
#define GLSHAPEINTERFACE_H

#include <QtWidgets>

class GLShapeInterface 
{
public:
	GLShapeInterface();
	virtual ~GLShapeInterface();

	void setLastPos(QPoint pt);
	QPoint getLastPos();

	void computeLocation();

	virtual void init();
	virtual void draw() = 0;

private:
	QPoint m_lastPos;
};


#endif //GLSHAPEINTERFACE_H