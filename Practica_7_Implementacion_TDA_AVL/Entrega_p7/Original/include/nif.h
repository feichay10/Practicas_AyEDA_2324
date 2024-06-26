/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 7: Implementacion del TDA AVL
 * @file nif.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef NIF_H
#define NIF_H

#include <ctime>
#include <iostream>
#include <random>
#include <string>

class Nif {
 public:
  Nif();
  Nif(const long nif);
  Nif(std::string nif) {
    nif_ = std::stol(nif);
  }

  char letterNif(Nif nif);
  bool checkNif(Nif nif);

  bool operator==(const Nif& other) const;
  bool operator==(int other) const;
  bool operator!=(const Nif& other) const;
  operator long();
  operator unsigned int() const;
  unsigned operator[](unsigned i) const;
  Nif& operator=(const Nif& other);  

  friend std::ostream& operator<<(std::ostream& os, const Nif& nif);
  friend std::istream& operator>>(std::istream& is, Nif& nif);

 private:
  long nif_;
};

#endif  // NIF_H