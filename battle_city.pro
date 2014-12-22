#-------------------------------------------------
#
# Project created by QtCreator 2014-11-14T23:11:02
#
#-------------------------------------------------

QT       += core gui
QT       += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = battle_city
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamemanager.cpp \
    tank.cpp \
    field.cpp \
    ai.cpp \
    bullet.cpp \
    kirpich.cpp \
    basic_element.cpp \
    metall.cpp \
    basetank.cpp

HEADERS  += mainwindow.h \
    field.h \
    bullet.h \
    gamemanager.h \
    tank.h \
    player.h \
    ai.h \
    kirpich.h \
    basic_element.h \
    metall.h \
    basetank.h

FORMS    += mainwindow.ui

QT += widgets

RESOURCES += \
    res.qrc

unix|win32: LIBS += -ltinyxml
