#-------------------------------------------------
#
# Project created by QtCreator 2013-12-21T17:15:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Juntos
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    uiacceuil.cpp \
    ../cprojet.cpp \
    cprojet.cpp

HEADERS  += mainwindow.h \
    uiacceuil.h \
    cprojet.h

FORMS    += mainwindow.ui \
    uiacceuil.ui

RESOURCES += \
    Images.qrc
