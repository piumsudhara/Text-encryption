#-------------------------------------------------
#
# Project created by QtCreator 2017-03-06T18:20:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TextEncryption
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    simplecrypt.cpp

HEADERS  += mainwindow.h \
    simplecrypt.h

FORMS    += mainwindow.ui

RESOURCES += \
    iconresource.qrc
