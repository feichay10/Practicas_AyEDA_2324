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

//TODO: Check when inserted element is already in the table
//TODO: Check the enter key is a valid nif, with a length of 8 characters
//TODO: Check why the program is not working well when in the parameters set only for dispersion open and warning message is out

int main(int argc, char* argv[]) {
  HashTableParameters parameters;
  try {
    parameters = checkProgramParameters(argc, argv, parameters);
    makeHashTable(parameters);
  } catch (std::string message) {
    std::cerr << message << std::endl;
  }
}