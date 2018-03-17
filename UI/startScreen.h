#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QWidget>
#include <QPushButton>

class startScreen : public QWidget
{
 Q_OBJECT
 public:
  explicit startScreen(QWidget *parent = 0);
  char* getFilename();
 private slots:
   void button1Clicked(bool checked);
 private:
  QPushButton *button1,*button2;
  char* filename;

 signals:
 public slots:
};

#endif // WINDOW_H