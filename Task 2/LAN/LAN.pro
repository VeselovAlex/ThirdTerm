#-------------------------------------------------
#
# Project created by QtCreator 2013-12-17T17:06:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LAN
TEMPLATE = app
CONFIG += qtestlib

SOURCES += main.cpp\
    computer.cpp \
    generator.cpp \
    lan.cpp \
    landisplay.cpp \
    filedialog.cpp \
    computertest.cpp \
    lantest.cpp

HEADERS  += \
    computer.h \
    generator.h \
    lan.h \
    landisplay.h \
    filedialog.h \
    computertest.h \
    lantest.h
