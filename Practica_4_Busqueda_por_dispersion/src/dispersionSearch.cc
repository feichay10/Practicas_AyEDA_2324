/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file dispersionSearch.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

#include "../include/nif.h"

typedef Nif KeyType;

int main() {
  Nif nif1(12345678);
  Nif nif2(87654321);
  std::cout << "NIF1: " << nif1 << std::endl;
  std::cout << "NIF2: " << nif2 << std::endl;

  Nif nif3;
  std::cout << "NIF3: " << nif3 << std::endl;
}