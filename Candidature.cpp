#include <iostream>
#include "Candidature.h"

Candidature::Candidature(){
  std::cout << "New object 'candidature' : " << this << std::endl;
  answer = false;
}

Candidature::~Candidature(){
  std::cout << "Suppressed Object 'candidature' : " << this << std::endl;
}

QString Candidature::get_company_name(){
  return company;
}

QString Candidature::get_application_date(){
  return date_of_application;
}
