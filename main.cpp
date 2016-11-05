#include <QApplication>
#include "MainFrame.h"

int main(int argc, char *argv[]){

  QApplication app(argc, argv);

  MainFrame mf;
  
  mf.show();

  return app.exec();
}
