#ifndef DEF_CANDIDATURE
#define DEF_CANDIDATURE

#include <QString>

class Candidature {

 public:
  Candidature();
  ~Candidature();

 private:
  QString company;
  QString date_of_application;
  bool answer;

};

#endif
