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


// Modificacion: Probar como funciona cuando nos vamos a tamaños mas grandes
// Usar random para generar el array
// Usaremos selection y quicksort de varios tamaños
// Obtener el numero de comparaciones, osea cuando se usa el operador de comparacion
// Obtener el numero de asignaciones, osea cuando se usa el operador de asignacion

// En una ejecucion mostrara el numero de comparaciones y asignaciones de cada uno de los algoritmos
// Probaremos:
// 1. 100 elementos
// 2. 1000 elementos

// Original:
// Usar la traza con el RadixSort y con el HeapSort


int main(int argc, char* argv[]) {
  sortParameters parameters;
  try {
    parameters = checkProgramParameters(argc, argv, parameters);
    createSequence(parameters);
  } catch (std::string message) {
    std::cerr << RED_BOLD << "ERROR: " << message << RESET << std::endl;
  } catch (std::invalid_argument& e) {
    std::cerr << RED_BOLD << "ERROR: " << e.what() << RESET << std::endl;
  } catch (std::length_error& e) {
    std::cerr << RED_BOLD << "ERROR: " << e.what() << RESET << std::endl;
  } catch (std::runtime_error& e) {
    std::cerr << RED_BOLD << "ERROR: " << e.what() << RESET << std::endl;
  }
}