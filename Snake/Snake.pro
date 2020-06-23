TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        CFood.cpp \
        CGame.cpp \
        CSnake.cpp \
        CTools.cpp \
        CUnit.cpp \
        demo.cpp

HEADERS += \
    CFood.h \
    CGame.h \
    CSnake.h \
    CTools.h \
    CUnit.h


LIBS += User32.LIB
