#-------------------------------------------------
#
# Project created by QtCreator 2013-12-06T21:35:36
#
#-------------------------------------------------

QT       += core gui opengl
LIBS += -lopengl32 -glu32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-line
TEMPLATE = app

INCLUDEPATH += "C:\Users\HP\Documents\iit_acad\cop290\DrawingTool"

LIBS += "C:\Users\HP\Documents\iit_acad\cop290\DrawingTool\*.o"

SOURCES += main.cpp\
    myqgraphicsview.cpp\
    threeDOutputWidget.cpp\
    fileDialog.cpp\
    startScreen.cpp\
    twoDModelOutputTool.cpp\
    threeDModelOutputTool.cpp

HEADERS  += myqgraphicsview.h\
			threeDOutputWidget.h\
			fileDialog.h\
			startScreen.h\
			twoDModelOutputTool.h\
			threeDModelOutputTool.h