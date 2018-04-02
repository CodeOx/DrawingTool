#include <QApplication>
#include <startScreen.h>
#include "twoDModelOutputTool.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    startScreen screen;
    screen.show();

    return a.exec();
}