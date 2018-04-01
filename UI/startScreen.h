#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QWidget>
#include <QPushButton>
#include <twoDOutputWidget.h>
#include <twoDModelOutputTool.h>
#include <threeDOutputWidget.h>
#include <threeDModelOutputTool.h>
#include "fileDialog.h"
#include "../TwoDModelGenerator.h"

class startScreen : public QWidget
{
 Q_OBJECT
 public:
  explicit startScreen(QWidget *parent = 0);
 private slots:
	void button1Clicked(bool checked);
	void button2Clicked(bool checked);
 	void fileOpened3D();
 	void fileOpened2D();
 private:
  QPushButton *button1,*button2;
  QFileDialogTester *openFile3D,*openFile2D;
  twoDOutputWidget view2D;
  threeDOutputWidget view3D;
  char* filename;

 signals:
 public slots:
};

#endif // WINDOW_H