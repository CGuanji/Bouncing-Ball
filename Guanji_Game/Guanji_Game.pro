TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11

#WINDOWS
# put SFML file in the same location as project
#LIBS += -L"..\..\SFML-2.5.1\lib" #change this
#LIBS += -L"..\..\SFML-2.5.1\bin" #change this

#MAC
LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
#INCLUDEPATH += "..\..\SFML-2.5.1\include" #change this
#DEPENDPATH  += "..\..\SFML-2.5.1\include" #change this

#MAC
INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"

#To Here


SOURCES += main.cpp \
    ../../../CS3/Graphing/Graphing/random.cpp \
    ../Game/Game.cpp \
    ../Game/GameText.cpp \
    ../Game/Game_Interface.cpp \
    ../Game/Thumbnail.cpp \
    my_game.cpp \
    round_manger.cpp \
    system.cpp

HEADERS += \
    ../../../CS3/Graphing/Graphing/random.h \
    ../Game/Game.h \
    ../Game/GameText.h \
    ../Game/Game_Interface.h \
    ../Game/Thumbnail.h \
    About_This_Game.h \
    blocks.h \
    my_game.h \
    round_manger.h \
    system.h
