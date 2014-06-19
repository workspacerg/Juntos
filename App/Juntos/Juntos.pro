#-------------------------------------------------
#
# Project created by QtCreator 2013-12-21T17:15:53
#
#-------------------------------------------------

QT       += core gui
QT       += sql # On rajoute SQL

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Juntos
TEMPLATE = app


CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    uiacceuil.cpp \
    cprojet.cpp \
    uitask.cpp \
    uipref.cpp \
    uiticket.cpp \
    uitest.cpp \
    uifile.cpp \
    notification.cpp \
    bdd.cpp

HEADERS  += mainwindow.h \
    uiacceuil.h \
    cprojet.h \
    uitask.h \
    uipref.h \
    uiticket.h \
    uitest.h \
    uifile.h \
    notification.h \
    bdd.h

FORMS    += mainwindow.ui \
    uiacceuil.ui \
    uitask.ui \
    uipref.ui \
    uiticket.ui \
    uiTest.ui \
    uiFile.ui

RESOURCES += \
    Images.qrc

OTHER_FILES += \
    ../../../../../Google Drive/Workspace/ESGI/Ressource/windows8_icons.zip \
    icon.png
