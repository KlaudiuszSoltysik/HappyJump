INCLUDEPATH += "C:/SFML-2.5.1/include"
LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}
TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bee.cpp \
        guy.cpp \
        main.cpp \
        object.cpp \
        platform.cpp \
        platform2.cpp \
        platform3.cpp

HEADERS += \
    bee.h \
    guy.h \
    object.h \
    platform.h \
    platform2.h \
    platform3.h
