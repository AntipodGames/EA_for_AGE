#-------------------------------------------------
#
# Project created by QtCreator 2015-10-19T20:55:41
#
#-------------------------------------------------

QT -= core gui

TARGET = EA_for_AntipodGameEngine
TEMPLATE = lib
#CONFIG += staticlib

SOURCES += cell.cpp \
    population.cpp

HEADERS += cell.h \
    parameters.h \
    population.h \
    environment_descriptor.hpp
unix {
    target.path = /usr/local/lib
    headers.files = cell.h parameters.h population.h environment_descriptor.hpp
    headers.path = /usr/local/include/ea4age
    INSTALLS += target headers
}
