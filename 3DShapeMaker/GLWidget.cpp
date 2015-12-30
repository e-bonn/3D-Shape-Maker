// myglwidget.cpp

#include <QtWidgets>
#include <QtOpenGL>

#include "GLWidget.h"
#include "PyramidGLShape.h"
#include "CubicGLShape.h"
#include "SphericalGLShape.h"

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    m_xRot = 0;
    m_yRot = 0;
    m_zRot = 0;
    m_shape = new CubicGLShape();
}

GLWidget::~GLWidget()
{
    delete m_shape;
}

void GLWidget::setShape(GLShapeInterface* shape)
{
    if (m_shape) delete m_shape;
    m_shape = shape;
    updateGL();
}

QSize GLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}

void GLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_xRot) {
        m_xRot = angle;
        updateGL();
    }
}

void GLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_yRot) {
        m_yRot = angle;
        updateGL();
    }
}

void GLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_zRot) {
        m_zRot = angle;
        updateGL();
    }
}

void GLWidget::initializeGL()
{
    m_shape->init();
    glClearColor(0.6235,0.7176,0.7490,0);
    updateGL();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(m_xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(m_yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(m_zRot / 16.0, 0.0, 0.0, 1.0);
    m_shape->draw();
}

void GLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    m_shape->setLastPos(event->pos());
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - m_shape->getLastPos().x();
    int dy = event->y() - m_shape->getLastPos().y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(m_xRot + 6 * dy);
        setYRotation(m_yRot + 6 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(m_xRot + 6 * dy);
        setZRotation(m_zRot + 6 * dx);
    }

    m_shape->setLastPos(event->pos());
}

