#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QWidget>
#include <QPushButton>
#include <myqgraphicsview.h>
#include "fileDialog.h"

class startScreen : public QWidget
{
 Q_OBJECT
 public:
  explicit startScreen(QWidget *parent = 0);
 private slots:
	void button1Clicked(bool checked);
	void button2Clicked(bool checked);
 	void fileOpened();
 private:
  QPushButton *button1,*button2;
  QFileDialogTester *test;
  MyQGraphicsView view;
  char* filename;

 signals:
 public slots:
};

#endif // WINDOW_H