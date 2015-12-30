QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3DShapeMaker
TEMPLATE = app


SOURCES += main.cpp\
        Window.cpp \
    GLWidget.cpp \
    GLShapeInterface.cpp \
    PyramidGLShape.cpp \
    CubicGLShape.cpp \
    SphericalGLShape.cpp

HEADERS  += Window.h \
    GLWidget.h \
    GLShapeInterface.h \
    PyramidGLShape.h \
    CubicGLShape.h \
    SphericalGLShape.h

FORMS    += Window.ui
