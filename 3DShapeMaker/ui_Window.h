/********************************************************************************
** Form generated from reading UI file 'Window.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "GLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QVBoxLayout *verticalLayout;
    GLWidget *myGLWidget;
    QGroupBox *groupBoxShape;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButtonCube;
    QRadioButton *radioButtonPyramid;
    QRadioButton *radioButtonSphere;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(350, 380);
        verticalLayout = new QVBoxLayout(Window);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        myGLWidget = new GLWidget(Window);
        myGLWidget->setObjectName(QStringLiteral("myGLWidget"));
        myGLWidget->setMinimumSize(QSize(200, 250));
        groupBoxShape = new QGroupBox(myGLWidget);
        groupBoxShape->setObjectName(QStringLiteral("groupBoxShape"));
        groupBoxShape->setGeometry(QRect(0, 0, 150, 106));
        verticalLayout_2 = new QVBoxLayout(groupBoxShape);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 0, 0, -1);
        radioButtonCube = new QRadioButton(groupBoxShape);
        radioButtonCube->setObjectName(QStringLiteral("radioButtonCube"));
        radioButtonCube->setChecked(true);

        verticalLayout_2->addWidget(radioButtonCube);

        radioButtonPyramid = new QRadioButton(groupBoxShape);
        radioButtonPyramid->setObjectName(QStringLiteral("radioButtonPyramid"));

        verticalLayout_2->addWidget(radioButtonPyramid);

        radioButtonSphere = new QRadioButton(groupBoxShape);
        radioButtonSphere->setObjectName(QStringLiteral("radioButtonSphere"));

        verticalLayout_2->addWidget(radioButtonSphere);

        groupBoxShape->raise();

        verticalLayout->addWidget(myGLWidget);


        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", 0));
        groupBoxShape->setTitle(QApplication::translate("Window", "Shape", 0));
        radioButtonCube->setText(QApplication::translate("Window", "Cube", 0));
        radioButtonPyramid->setText(QApplication::translate("Window", "Pyramid", 0));
        radioButtonSphere->setText(QApplication::translate("Window", "Sphere", 0));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
