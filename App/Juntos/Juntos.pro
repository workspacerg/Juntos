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
    uifile.cpp \
    notification.cpp \
    bdd.cpp \
    settings.cpp \
    addpeopledialog.cpp \
    cuser.cpp \
    ticket.cpp \
    formaddbug.cpp \
    formupdbug.cpp \
    task.cpp \
    formaddtodo.cpp \
    formupdtodo.cpp \
    test.cpp \
    uitestunitaire.cpp \
    share.cpp \
    uimessage.cpp \
    cmessage.cpp \
    uijournal.cpp \
    cjournal.cpp

HEADERS  += mainwindow.h \
    uiacceuil.h \
    cprojet.h \
    uitask.h \
    uipref.h \
    uiticket.h \
    uifile.h \
    notification.h \
    bdd.h \
    settings.h \
    addpeopledialog.h \
    cuser.h \
    ticket.h \
    formaddbug.h \
    formupdbug.h \
    task.h \
    formaddtodo.h \
    formupdtodo.h \
    test.h \
    uitestunitaire.h \
    share.h \
    uimessage.h \
    cmessage.h \
    uijournal.h \
    cjournal.h

FORMS    += mainwindow.ui \
    uiacceuil.ui \
    uitask.ui \
    uipref.ui \
    uiticket.ui \
    uiFile.ui \
    addpeopledialog.ui \
    formaddbug.ui \
    formupdbug.ui \
    formaddtodo.ui \
    formupdtodo.ui \
    uitestunitaire.ui \
    uimessage.ui \
    uijournal.ui

RESOURCES += \
    Images.qrc

OTHER_FILES += \
    ../../../../../Google Drive/Workspace/ESGI/Ressource/windows8_icons.zip \
    icon.png
