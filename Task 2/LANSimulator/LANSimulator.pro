#-------------------------------------------------
#
# Project created by QtCreator 2013-09-15T15:34:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LANSimulator
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    lan.cpp

HEADERS  += widget.h \
    computer.h \
    lan.h \
    opsystem.h

FORMS    += widget.ui
