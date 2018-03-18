#include "startScreen.h"

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

		test = new QFileDialogTester();

		connect(button1, SIGNAL (clicked(bool)), this, SLOT (button1Clicked(bool)));
		connect(test, SIGNAL (fileOpened()), this, SLOT (fileOpen()));
	}

void startScreen::button1Clicked(bool checked)
{
 	filename = test->openFile();
}

void startScreen::button2Clicked(bool checked)
{
 	filename = test->openFile();
}

void startScreen::fileOpened()
{	
	//perform file parsing here
	//view.setThreeDModel(model);
	view.drawOutput2D();
	view.show();
}