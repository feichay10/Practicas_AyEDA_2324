/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementacion del TDA Árbol 
 * @file nif.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef NIF_H
#define NIF_H

#include <ctime>
#include <iostream>
#include <random>

class Nif {
 public:
  Nif();
  Nif(const long nif);

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

  auto begin() const { return std::to_string(nif_).begin(); }
  auto end() const { return std::to_string(nif_).end(); }

 private:
  long nif_;
};

#endif  // NIF_H