TARGET = theHunt
QT       += gui core widgets opengl multimedia
TEMPLATE = app

win32 {
    CONFIG += console #Notwendig in 5.5, da sonst qMain gesucht wird und nicht gefunden wird... eher ein Bug in Qt5.5?
    LIBS += -lopengl32
}
macx {
    QMAKE_MAC_SDK = macosx10.12
    #QMAKE_MAC_SDK = macosx10.9
}
SGFRAMEWORKINCLUDEPATH = "$$PWD/../SGFrameworkLib"
SGFRAMEWORKPATH = $${SGFRAMEWORKINCLUDEPATH}
PRE_TARGETDEPS += $${SGFRAMEWORKPATH}/libSGFramework.a
INCLUDEPATH += $${SGFRAMEWORKINCLUDEPATH}

LIBS += $${SGFRAMEWORKPATH}/libSGFramework.a
DEFINES += SRCDIR=\\\"$${_PRO_FILE_PWD_}\\\"

SOURCES += myscene.cpp \
    world.cpp \
    smell.cpp \
    smellpool.cpp \
    animal.cpp \
    calmstate.cpp \
    controller.cpp \
    kreatur.cpp \
    animatedmodel.cpp \
    warnedstate.cpp \
    player.cpp \
    wind.cpp

HEADERS += \
    world.h \
    smell.h \
    terrain.h \
    smellpool.h \
    animal.h \
    animalstate.h \
    calmstate.h \
    controller.h \
    kreatur.h \
    animatedmodel.h \
    warnedstate.h \
    player.h \
    wind.h

RESOURCES += \
    MyShaders.qrc

DISTFILES +=

