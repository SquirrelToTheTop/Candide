#ifndef DEF_CANDIDATURE
#define DEF_CANDIDATURE

#include <QString>

class Candidature {

 public:
  Candidature();
  ~Candidature();
  QString get_company_name();
  QString get_application_date();

 private:
  QString company;
  QString date_of_application;
  bool answer;

};

#endif
