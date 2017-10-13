QT += core
QT -= gui

TARGET = honey-options
CONFIG += console
CONFIG -= app_bundle

CONFIG   += c++11 (Qt5)

TEMPLATE = app

SOURCES += main.cpp \
    honeyoptions.cpp

HEADERS += \
    honeyoptions.h

