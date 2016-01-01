// window.cpp

#include <QtWidgets>
#include "Window.h"
#include "ui_Window.h"

#include "GLWidget.h"

#include "PyramidGLShape.h"
#include "CubicGLShape.h"
#include "SphericalGLShape.h"
#include "CylindricalGLShape.h"

Window::Window(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Window)
{
    m_ui->setupUi(this);

    m_ui->groupBoxShape->setStyleSheet("background:rgb(159,183,191);");
    connect(m_ui->radioButtonCube,SIGNAL(toggled(bool)),this,SLOT(radioButtonChanged()));
    connect(m_ui->radioButtonPyramid,SIGNAL(toggled(bool)),this,SLOT(radioButtonChanged()));
    connect(m_ui->radioButtonSphere,SIGNAL(toggled(bool)),this,SLOT(radioButtonChanged()));
    connect(m_ui->radioButtonCylinder,SIGNAL(toggled(bool)),this,SLOT(radioButtonChanged()));
}

Window::~Window()
{
    delete m_ui;
}

void Window::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}

void Window::radioButtonChanged()
{
    if (m_ui->radioButtonCube->isChecked())
    {
        m_ui->myGLWidget->setShape(new CubicGLShape());
    }
    else if (m_ui->radioButtonPyramid->isChecked())
    {
        m_ui->myGLWidget->setShape(new PyramidGLShape());
    }
    else if (m_ui->radioButtonSphere->isChecked())
    {
        m_ui->myGLWidget->setShape(new SphericalGLShape());
    }
    else if (m_ui->radioButtonCylinder->isChecked())
    {
        m_ui->myGLWidget->setShape(new CylindricalGLShape());
    }
}