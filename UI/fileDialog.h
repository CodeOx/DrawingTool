#ifndef QFILEDIALOGTESTER_H
#define QFILEDIALOGTESTER_H

#include <QFileDialog>
#include <QDebug>

class QFileDialogTester : public QWidget
{
public:
  char* openFile();
};

#endif