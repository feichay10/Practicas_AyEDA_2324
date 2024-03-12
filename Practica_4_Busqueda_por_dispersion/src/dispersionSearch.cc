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

int main(int argc, char* argv[]) {
  HashTableParameters parameters; // TODO: Paso por referencia

  try {
    checkProgramParameters(argc, argv);
    makeHashTable(tableSize, df, dispersionTechnic, blockSize, ef);
  } catch (std::string message) {
    std::cerr << message << std::endl;
  }
}