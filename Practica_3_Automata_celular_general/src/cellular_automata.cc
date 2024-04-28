/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file cellular_automata.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

#include "../include/functions.h"

int main(int argc, char* argv[]) {
  parameters params;

  try {
    checkParameters(argc, argv, params);
    createLattice(params);
  } catch (std::string message) {
    std::cerr << RED_BOLD << "ERROR: " << message << RESET << std::endl;
  } catch (std::invalid_argument& e) {
    std::cerr << RED_BOLD << "ERROR: " << e.what() << RESET << std::endl;
  } catch (std::length_error& e) {
    std::cerr << RED_BOLD << "ERROR: " << e.what() << RESET << std::endl;
  } catch (std::runtime_error& e) {
    std::cerr << RED_BOLD << "ERROR: " << e.what() << RESET << std::endl;
  }

  return 0;
}