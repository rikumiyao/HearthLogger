#-------------------------------------------------
#
# Project created by QtCreator 2015-03-27T22:43:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HearthLogger
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp

HEADERS  += mainwindow.h \
    game.h

FORMS    += mainwindow.ui

RESOURCES += \
    HearthLogger.qrc
