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
    cprojet.cpp \
    uitask.cpp \
    uipref.cpp \
    uiticket.cpp \
    uitest.cpp \
    uifile.cpp

HEADERS  += mainwindow.h \
    uiacceuil.h \
    cprojet.h \
    uitask.h \
    uipref.h \
    uiticket.h \
    uitest.h \
    uifile.h

FORMS    += mainwindow.ui \
    uiacceuil.ui \
    uitask.ui \
    uipref.ui \
    uiticket.ui \
    uiTest.ui \
    uitest.ui \
    uiFile.ui

RESOURCES += \
    Images.qrc
