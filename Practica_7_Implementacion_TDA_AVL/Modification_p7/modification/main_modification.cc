/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 7: Implementacion del TDA AVL
 * @file main_modification.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/functions.h"

#include <sstream>

#include "../include/ABB.h"
#include "../include/ABE.h"
#include "../include/AVL.h"

using keyType = Nif;

int main(int argc, char* argv[]) {
  AB<keyType>* treeABB = new ABB<keyType>;
  AB<keyType>* treeABE = new ABE<keyType>;
  AB<keyType>* treeAVL = new AVL<keyType>;

  std::ifstream file("data/problema1.txt");
  if (!file.is_open()) {
    throw std::runtime_error("File could not be opened.");
  }

  int numElements;
  file >> numElements;

  keyType key;
  while (file >> key) {
    std::cout << BOLD << "\nInsertada la clave: " << RESET << key << std::endl;
    treeABB->insert(key);
    treeABE->insert(key);
    treeAVL->insert(key);
  }

  std::cout << std::endl;
  treeABB->write(std::cout);

  std::cout << std::endl;
  treeABE->write(std::cout);

  std::cout << "\nIntroduce la clave a buscar: ";
  keyType nif;
  std::cin >> nif;

  if (treeABB->search(nif)) {
    std::cout << "la clave " << nif << " ha sido encontrado en el ABB." << std::endl;
    std::cout << "Veces que se ha buscado la clave en el ABB: " << treeABB->getCountSearchesABB() << std::endl; 
  } else {
    std::cout << "la clave " << nif << " no ha sido encontrado en el ABB." << std::endl;
  }

  if (treeABE->search(nif)) {
    std::cout << "la clave " << nif << " ha sido encontrado en el ABE." << std::endl;
    std::cout << "Veces que se ha buscado la clave en el ABE: " << treeABE->getCountSearchesABE() << std::endl;
  } else {
    std::cout << "la clave " << nif << " no ha sido encontrado en el ABE." << std::endl;
  }

  if (treeAVL->search(nif)) {
    std::cout << "la clave " << nif << " ha sido encontrado en el AVL." << std::endl;
    std::cout << "Veces que se ha buscado la clave en el AVL: " << treeAVL->getCountSearchesABB() << std::endl;
  } else {
    std::cout << "la clave " << nif << " no ha sido encontrado en el AVL." << std::endl;
  }
}