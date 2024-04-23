/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 7: Implementacion del TDA AVL
 * @file treeTDA.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/functions.h"

// TODO: Fix DD rotation when a key is removed

int main(int argc, char* argv[]) {
  treeParameters parameters;
  try {
    parameters = checkProgramParameters(argc, argv, parameters);
    printInformation(parameters);
    createTree(parameters);
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