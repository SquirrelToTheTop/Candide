#include <iostream>
#include <QApplication>
#include "MainFrame.h"

MainFrame::MainFrame() : QMainWindow(){

  setFixedSize(width_mf, height_mf);

  mainWidget = new QWidget();

  menuCand = menuBar()->addMenu("&Candidature");
  menuData = menuBar()->addMenu("&Data");

  addCand = new QAction("New", this);
  delCand = new QAction("Delete", this);

  loadData = new QAction("Load data", this);
  saveData = new QAction("Save data", this);

  menuCand->addAction(addCand);
  menuCand->addAction(delCand);

  menuData->addAction(loadData);
  menuData->addAction(saveData);

  connect(addCand, SIGNAL(triggered()), this, SLOT(newApplication()));
  connect(delCand, SIGNAL(triggered()), this, SLOT(delApplication()));
  connect(loadData, SIGNAL(triggered()), this, SLOT(loadApplicationData()));
  connect(saveData, SIGNAL(triggered()), this, SLOT(saveApplicationData()));

  setCentralWidget(mainWidget);  

}

void MainFrame::newApplication(){
  std::cout << "Request for new an application..." << std::endl;
  statusBar()->showMessage(tr("Adding new candidature"));
}

void MainFrame::delApplication(){
  std::cout << "Request for delete an application..." << std::endl;
  statusBar()->showMessage(tr("Removing old candidature"));
}

void MainFrame::loadApplicationData(){
  std::cout << "Request for loading application data..." << std::endl;
  statusBar()->showMessage(tr("Loading candidature"));
}

void MainFrame::saveApplicationData(){
  std::cout << "Request for saving application data..." << std::endl;
  statusBar()->showMessage(tr("Saving candidature"));
}
