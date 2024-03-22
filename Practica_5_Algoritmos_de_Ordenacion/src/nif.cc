#include "../include/nif.h"

const char letters[] = "TRWAGMYFPDXBNJZSQVHLCKE";

Nif::Nif() {
  // nif_ = 10000000 + rand() % 1000000;
}

Nif::Nif(const long nif) {
  nif_ = nif;
}

char Nif::letterNif(Nif nif) {
  return letters[static_cast<int>(nif) % 23];
}

bool Nif::checkNif(Nif nif) {
  std::string nif_string = std::to_string(nif.nif_);
  if (nif_string.size() != 8) {
    return false;
  }
  return true;
}

bool Nif::operator==(const Nif& other) const {
  return nif_ == other.nif_;
}

bool Nif::operator==(int other) const {
  return nif_ == other;
}

bool Nif::operator!=(const Nif& other) const {
  return nif_ != other.nif_;
}

Nif::operator long() {
  return nif_;
}

Nif::operator unsigned int() const {
  return nif_;
}

unsigned Nif::operator[](unsigned i) const {
  std::string nif_string = std::to_string(nif_);
  return nif_string[i] - '0';
}

std::ostream& operator<<(std::ostream& os, const Nif& nif) {
  os << nif.nif_;
  return os;
}

std::istream& operator>>(std::istream& is, Nif& nif) {
  is >> nif.nif_;
  return is;
}