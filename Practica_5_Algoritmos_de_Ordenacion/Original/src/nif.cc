/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file nif.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/nif.h"

const char letters[] = "TRWAGMYFPDXBNJZSQVHLCKE";

/**
 * @brief Construct a new Nif:: Nif object with a random nif.
 * 
 */
Nif::Nif() {
  srand(time(0));
  
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<long> dis(10000000, 99999999);

  nif_ = dis(gen);
}

/**
 * @brief Construct a new Nif:: Nif object with a given nif.
 * 
 * @param nif 
 */
Nif::Nif(const long nif) {
  nif_ = nif;
}

/**
 * @brief Function that returns the letter of the nif.
 * 
 * @param nif 
 * @return char 
 */
char Nif::letterNif(Nif nif) {
  return letters[static_cast<int>(nif) % 23];
}

/**
 * @brief Function that checks if the nif is valid.
 * 
 * @param nif 
 * @return true 
 * @return false 
 */
bool Nif::checkNif(Nif nif) {
  std::string nif_string = std::to_string(nif.nif_);
  if (nif_string.size() != 8) {
    return false;
  }
  return true;
}

/**
 * @brief Overloaded operator == that checks if two nifs are equal.
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool Nif::operator==(const Nif& other) const {
  return nif_ == other.nif_;
}

/**
 * @brief Overloaded operator == that checks if a nif is equal to an integer.
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool Nif::operator==(int other) const {
  return nif_ == other;
}

/**
 * @brief Overloaded operator != that checks if two nifs are different.
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool Nif::operator!=(const Nif& other) const {
  return nif_ != other.nif_;
}

/**
 * @brief Overloaded operator that converts a nif to a long.
 * 
 * @return long 
 */
Nif::operator long() {
  return nif_;
}

/**
 * @brief Overloaded operator that converts a nif to an unsigned int.
 * 
 * @return unsigned int 
 */
Nif::operator unsigned int() const {
  return nif_;
}

/**
 * @brief Overloaded operator [] that returns the digit at the given position.
 * 
 * @param i 
 * @return unsigned 
 */
unsigned Nif::operator[](unsigned i) const {
  std::string nif_string = std::to_string(nif_);
  return nif_string[i] - '0';
}

/**
 * @brief Overloaded operator = that assigns a nif to another nif.
 * 
 * @param other 
 * @return Nif& 
 */
Nif& Nif::operator=(const Nif& other) {
  nif_ = other.nif_;
  return *this;
}

/**
 * @brief Overloaded operator << that prints a nif.
 * 
 * @param os 
 * @param nif 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Nif& nif) {
  os << nif.nif_;
  return os;
}

/**
 * @brief Overloaded operator >> that reads a nif.
 * 
 * @param is 
 * @param nif 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& is, Nif& nif) {
  is >> nif.nif_;
  return is;
}