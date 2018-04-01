#include "fileDialog.h"
#include <iostream> 
#include <fstream>


char* QFileDialogTester::openFile()
{
  QString filename =  QFileDialog::getOpenFileName(
        this,
        "Open Document",
        QDir::currentPath(),
        "Text files (*.txt)");

  if( !filename.isNull() )
  {
    qDebug() << "selected file path : " << filename.toUtf8();
    std::cout << "filename.toUtf8()";
    
    QByteArray file;
    file = filename.toUtf8();
    emit fileOpened();
    return file.data();

  }
  return nullptr;
}