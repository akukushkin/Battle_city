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
    tank.cpp \
    field.cpp \
    bullet.cpp \
    kirpich.cpp

HEADERS  += mainwindow.h \
    field.h \
    bullet.h \
    gamemanager.h \
    tank.h \
    player.h \
    ai.h \
    kirpich.h \
    basic_element.h

FORMS    += mainwindow.ui

QT += widgets

RESOURCES += \
    res.qrc
