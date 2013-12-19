TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qtestlib

SOURCES += main.cpp \
    matrixFunctions.cpp \
    test_robots.cpp \
    robots.cpp

HEADERS += \
    matrixFunctions.h \
    test_robots.h \
    robots.h

