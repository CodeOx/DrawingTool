#include <QApplication>
#include <startScreen.h>
#include <myqgraphicsview.h>
#include <fileParser.h> 


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    startScreen screen;
 	screen.show();

    MyQGraphicsView view;
    view.show();

    return a.exec();
}