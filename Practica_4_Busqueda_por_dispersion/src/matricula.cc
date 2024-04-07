#include "../include/matricula.h"

Matricula::Matricula() {}

Matricula::Matricula(std::string matricula) : matricula_(matricula) {}

bool Matricula::operator==(const Matricula& matricula) const {
  return matricula_ == matricula.matricula_;
}

bool Matricula::operator!=(const Matricula& matricula) const {
  return matricula_ != matricula.matricula_;
}

Matricula &Matricula::operator=(const Matricula &matricula) {
  if (this != &matricula) {
    matricula_ = matricula.matricula_;
  }
  return *this;
}

Matricula &Matricula::operator=(const int &matricula) {
  matricula_ = std::to_string(matricula);
  return *this;
}

Matricula::operator long() const {
  long result = 0;
  for (unsigned i = 0; i < matricula_.size(); i++) {
    result += matricula_[i];
  }
  return result;
}

unsigned Matricula::operator[](unsigned i) const {
  return matricula_[i];
}


std::ostream& operator<<(std::ostream& os, const Matricula& matricula) {
  os << matricula.matricula_;
  return os;
}

std::istream& operator>>(std::istream& is, Matricula& matricula) {
  is >> matricula.matricula_;
  return is;
}

