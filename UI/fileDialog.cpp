#include "fileDialog.h"
#include <iostream> 
#include <fstream>


std::string QFileDialogTester::openFile()
{
  QString filename =  QFileDialog::getOpenFileName(
        this,
        "Open Document",
        QDir::currentPath(),
        "Text files (*.txt)");

  if( !filename.isNull() )
  {
    qDebug() << "selected file path : " << filename.toUtf8();

    QByteArray file;
    file = filename.toUtf8();
    std::string utf8_filename = file.constData();
    return utf8_filename;

  }
  return nullptr;
}