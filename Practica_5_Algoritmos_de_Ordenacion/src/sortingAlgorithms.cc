/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file sortingAlgorithms.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

#include "../include/functions.h"

// TODO: Trace -> Set with color (green for ordered, red for unordered)
// TODO: Implement all sorting algorithms -> bubbleSort, shakeSort
// TODO: Check if the sequence in the file is ordered or not
// TODO: Check if the sequence in the file is the same size as the one in the parameters

int main(int argc, char* argv[]) {
  sortParameters parameters;
  try {
    parameters = checkProgramParameters(argc, argv, parameters);
    createSequence(parameters);
  } catch (std::string message) {
    std::cerr << message << std::endl;
  }
}