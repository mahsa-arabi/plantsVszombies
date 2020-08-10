#-------------------------------------------------
#
# Project created by QtCreator 2020-08-07T20:36:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlantsVsZombie
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    Model/zombie.cpp \
    Model/sun.cpp \
    Model/shooterplant.cpp \
    Model/sunflower.cpp \
    Model/shovel.cpp \
    Model/oak.cpp \
    Model/bullet.cpp \
    Model/bosszombie.cpp \
    Model/bomb.cpp \
    Model/score.cpp \
    Controller/controller.cpp \
    View/view.cpp \
    View/level.cpp

HEADERS += \
    Model/zombie.h \
    Model/sun.h \
    Model/shooterplant.h \
    Model/sunflower.h \
    Model/shovel.h \
    Model/oak.h \
    Model/bullet.h \
    Model/bosszombie.h \
    Model/bomb.h \
    Model/score.h \
    Controller/controller.h \
    View/view.h \
    View/level.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
