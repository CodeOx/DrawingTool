#include <QApplication>
#include <startScreen.h>
#include "twoDModelOutputTool.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    
    //MyQGraphicsView view;
    //threeDOutputWidget view3D;

    startScreen screen;
    screen.show();

    return a.exec();
}