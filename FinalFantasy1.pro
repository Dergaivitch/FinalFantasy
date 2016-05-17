#-------------------------------------------------
#
# Project created by QtCreator 2013-11-12T19:58:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FinalFantasy1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamecanvas.cpp \
    gamelogic.cpp \
    mageunit.cpp \
    gameobject.cpp \
    gameunit.cpp \
    monsterunit.cpp \
    actionbutton.cpp \
    ../factory/unitsfactory.cpp \
    ../unitfactory.cpp

HEADERS  += mainwindow.h \
    gamecanvas.h \
    gamelogic.h \
    mageunit.h \
    gameobject.h \
    gameunit.h \
    monsterunit.h \
    actionbutton.h \
    ../factory/unitsfactory.h \
    ../unitfactory.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
