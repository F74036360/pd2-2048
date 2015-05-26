#-------------------------------------------------
#
# Project created by QtCreator 2015-05-23T23:19:50
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048
TEMPLATE = app


SOURCES += main.cpp\
        game.cpp \
    caution.cpp

HEADERS  += game.h \
    caution.h

FORMS    += game.ui \
    caution.ui

RESOURCES += \
    blk.qrc

DISTFILES +=
