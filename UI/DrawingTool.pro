#-------------------------------------------------
#
# Project created by QtCreator 2013-12-06T21:35:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DrawingTool
TEMPLATE = app

INCLUDEPATH += "C:\Users\HP\Documents\iit_acad\cop290\DrawingTool"

LIBS += "C:\Users\HP\Documents\iit_acad\cop290\DrawingTool\*.o"

SOURCES += main.cpp\
    twoDOutputWidget.cpp\
    threeDOutputWidget.cpp\
    fileDialog.cpp\
    startScreen.cpp\
    twoDModelOutputTool.cpp\
    threeDModelOutputTool.cpp

HEADERS  += twoDOutputWidget.h\
			threeDOutputWidget.h\
			fileDialog.h\
			startScreen.h\
			twoDModelOutputTool.h\
			threeDModelOutputTool.h