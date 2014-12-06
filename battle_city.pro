#-------------------------------------------------
#
# Project created by QtCreator 2014-11-14T23:11:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = battle_city
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamemanager.cpp \
    tank.cpp \
    field.cpp \
    ai.cpp

HEADERS  += mainwindow.h \
    field.h \
    bullet.h \
    gamemanager.h \
    tank.h \
    player.h \
    ai.h

FORMS    += mainwindow.ui
