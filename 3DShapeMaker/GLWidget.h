// myglwidget.h

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include "GLShapeInterface.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();

    void setShape(GLShapeInterface* shape);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

private:
    GLShapeInterface* m_shape;

    int m_xRot;
    int m_yRot;
    int m_zRot;
};

#endif // GLWIDGET_H

