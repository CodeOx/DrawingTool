#ifndef QFILEDIALOGTESTER_H
#define QFILEDIALOGTESTER_H

#include <QFileDialog>
#include <QDebug>

class QFileDialogTester : public QWidget
{
	Q_OBJECT
	public:
  		char* openFile();
  	signals:
 		void fileOpened();
};

#endif