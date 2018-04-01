#-------------------------------------------------
#
# Project created by QtCreator 2018-03-29T13:26:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app
CONFIG+=c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    basicLoopEdgeSet.cpp \
    bodyLoop.cpp \
    EdgeList2D.cpp \
    faceLoop.cpp \
    generalMethods.cpp \
    Plane.cpp \
    structs.cpp \
    TwoDObj.cpp \
    wireframe.cpp \
    VertexList2D.cpp \
    options.cpp \
    selection.cpp

HEADERS  += mainwindow.h \
    EdgeList2D.h \
    bodyLoop.h \
    basicLoopEdgeSet.h \
    faceLoop.h \
    generalMethods.h \
    structs.h \
    Plane.h \
    TwoDObj.h \
    wireframe.h \
    VertexList2D.h \
    options.h \
    selection.h

FORMS    += mainwindow.ui \
    selection.ui
