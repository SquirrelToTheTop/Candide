#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include "MainFrame.h"
#include "Candidature.h"

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

void MainFrame::newApplication() {
  std::cout << "Request for new an application..." << std::endl;
  statusBar()->showMessage(tr("Adding new candidature"));

  /* popup window to get data for candidature */
  int w_popup, h_popup;
  int h_qte = 30, inter_stuff = 10;
  int w_lb = 75, w_coms = 150, h_coms = 150;
  int w_btn;

  QWidget *popup = new QWidget();

  QLabel *company_name_lb = new QLabel("Company :", popup);
  QLabel *apply_date_lb = new QLabel("Date :", popup);
  QLabel *contact_name_lb = new QLabel("Contact :", popup);
  QLabel *coms_lb = new QLabel("Commentaires : ", popup);

  QPushButton *ok = new QPushButton("Validate", popup);
  QPushButton *cancel = new QPushButton("Cancel", popup);

  QTextEdit *company_name = new QTextEdit("Company", popup);
  QTextEdit *apply_date = new QTextEdit("Date", popup);
  QTextEdit *contact_name = new QTextEdit("Contact", popup);
  QTextEdit *coms = new QTextEdit("", popup);

  w_popup = 400;
  h_popup = 400;
  popup->setFixedSize(w_popup, h_popup);
  
  company_name_lb->setFixedHeight(h_qte);
  company_name_lb->setFixedWidth(w_lb);
  apply_date_lb->setFixedHeight(h_qte);
  apply_date_lb->setFixedWidth(w_lb);
  contact_name_lb->setFixedHeight(h_qte);
  contact_name_lb->setFixedWidth(w_lb);
  coms_lb->setFixedHeight(h_qte);
  coms_lb->setFixedWidth(w_lb*2);

  company_name->setFixedHeight(h_qte);  
  apply_date->setFixedHeight(h_qte);
  contact_name->setFixedHeight(h_qte);
  coms->setFixedHeight(h_coms);
  coms->setFixedWidth(w_popup-2*off_border_x);

  company_name_lb->move(off_border_x, off_border_y);  
  company_name->move(off_border_x+w_lb+inter_stuff, off_border_y );
  
  apply_date_lb->move(off_border_x, off_border_y+inter_stuff+h_qte);
  apply_date->move(off_border_x+w_lb+inter_stuff, off_border_y+inter_stuff+h_qte);

  contact_name_lb->move(off_border_x, off_border_y+2*inter_stuff+2*h_qte);
  contact_name->move(off_border_x+w_lb+inter_stuff, off_border_y+2*inter_stuff+2*h_qte);

  coms_lb->move(off_border_x, off_border_y+3*inter_stuff+3*h_qte);
  coms->move(off_border_x, off_border_y+4*inter_stuff+4*h_qte);

  w_btn = (w_popup-2*off_border_x-inter_stuff)/2;
  ok->setFixedHeight(h_qte);
  ok->setFixedWidth(w_btn);
  cancel->setFixedHeight(h_qte);
  cancel->setFixedWidth(w_btn);

  ok->move(off_border_x, off_border_y+5*inter_stuff+4*h_qte+h_coms);
  cancel->move(off_border_x+inter_stuff+w_btn, off_border_y+5*inter_stuff+4*h_qte+h_coms);
  
  connect(cancel, SIGNAL(clicked()), popup, SLOT(exec()));
  connect(ok, SIGNAL(clicked()), popup, SLOT(getNewCandidatureData()));

  popup->show();
  /* ---------------------------------------- */

  Candidature *cand1 = new Candidature();
  all_candidatures << cand1;

}

void MainFrame::getNewCandidatureData(){
  std::cout << "Trying to get new application data..." << std::endl;
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
