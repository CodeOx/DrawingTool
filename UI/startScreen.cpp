#include "startScreen.h"
#include <fileDialog.h>

startScreen::startScreen(QWidget *parent) :
	QWidget(parent)
	{
		// Set size of the window
		setFixedSize(800, 300);

		// Create and position the button
		button1 = new QPushButton("3D to 2D conversion", this);
		button1->setGeometry(100, 75, 200, 150);

		button2 = new QPushButton("3D to 2D conversion", this);	
		button2->setGeometry(500, 75, 200, 150);

		connect(button1, SIGNAL (clicked(bool)), this, SLOT (button1Clicked(bool)));
	}

void startScreen::button1Clicked(bool checked)
{
	QFileDialogTester test;
 	filename = test.openFile();
}

char* startScreen::getFilename(){
	return filename;
}