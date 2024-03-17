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

#include "../include/functions.h"

//TODO: Check when the table is full and i want to insert a new element
//TODO: Set if isFull on the StaticSequence class when inserted a new element
//TODO: Set default or by parameters fd to double dispersion

int main(int argc, char* argv[]) {
  HashTableParameters parameters;
  try {
    parameters = checkProgramParameters(argc, argv, parameters);
    makeHashTable(parameters);
  } catch (std::string message) {
    std::cerr << message << std::endl;
  }
}