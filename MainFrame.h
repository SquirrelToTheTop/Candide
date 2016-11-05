#ifndef DEF_MAINFRAME
#define DEF_MAINFRAME

#include <QWidget>
#include <QMainWindow>
#include <QList>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>

class MainFrame : public QMainWindow{

  Q_OBJECT

 public:
  MainFrame();

  private slots:
    void newApplication();
    void delApplication();
    void loadApplicationData();
    void saveApplicationData();      

 private:

  /* QWidget */
  QWidget *mainWidget;

  /* Menus */
  QMenu *menuCand, *menuData;
  QAction *addCand, *delCand, *loadData, *saveData;

  /* windows size */
  static const int width_mf = 500;
  static const int height_mf = 400;

  /* space between border and inside stuff */
  static const int off_border_x = 10;
  static const int off_border_y = 10;

};

#endif

