#ifndef QFILEDIALOGTESTER_H
#define QFILEDIALOGTESTER_H

#include <QFileDialog>
#include <QDebug>
#include <string>

class QFileDialogTester : public QWidget
{
	Q_OBJECT
	public:
  		std::string openFile();
  	signals:
 		void fileOpened();
};

#endif