#include <iostream>
#include "Candidature.h"

Candidature::Candidature(){
  std::cout << "New object 'candidature' : " << this << std::endl;
}

Candidature::~Candidature(){
  std::cout << "Suppressed Object 'candidature' : " << this << std::endl;
}
