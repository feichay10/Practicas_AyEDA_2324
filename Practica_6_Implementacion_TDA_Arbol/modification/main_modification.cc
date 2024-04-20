/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * @file main.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.2
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */

// Generar dos arboles, ABB y ABE con 5000 datos aleatorios que van desde 0 hasta 50000, los dos arboles con los mismos datos
// Nº valores a insertar: mostrar el numero de valores insertados
// Calcular la altura del subarbol izquierdo y la del subarbol derecho y mostrar:
// ABB - Dif altura:
// ABE - Dif altura:

// Modo traza: 49, 27, 5 rotation, 45, 40, 41 rotacion, 17

#include <iostream>
#include <random>

#include "../include/ABB.h"
#include "../include/ABE.h"
#include "../include/AB.h"
#include "../include/nif.h"
#include "../include/colors.h"

using keyType = Nif;

int main() {
  ABB<keyType> *abb;
  ABE<keyType> *abe;

  abb = new ABB<keyType>();
  abe = new ABE<keyType>();

  int countABB = 0;
  int countABE = 0;

  for (int i = 0; i < 5000; i++) {
    keyType key;
    if (abb->insert(key)) {
      countABB++;
    }
    if (abe->insert(key)) {
      countABE++;
    }
  }

  std::cout << "Numero de valores insertados en el arbol ABB: " << countABB << std::endl;
  std::cout << "Numero de valores insertados en el arbol ABE: " << countABE << std::endl;

  std::cout << "\nABB: " << std::endl;
  std::cout << "Altura del subarbol izquierdo: " << abb->heightN(abb->getRoot()->getLeft()) << std::endl;
  std::cout << "Altura del subarbol derecho: " << abb->heightN(abb->getRoot()->getRight()) << std::endl;
  std::cout << "Diferencia de altura: " << abb->heightN(abb->getRoot()->getLeft()) - abb->heightN(abb->getRoot()->getRight()) << std::endl;

  std::cout << "\nABE: " << std::endl;
  std::cout << "Altura del subarbol izquierdo: " << abe->heightN(abe->getRoot()->getLeft()) << std::endl;
  std::cout << "Altura del subarbol derecho: " << abe->heightN(abe->getRoot()->getRight()) << std::endl;
  std::cout << "Diferencia de altura: " << abe->heightN(abe->getRoot()->getLeft()) - abe->heightN(abe->getRoot()->getRight()) << std::endl;

  delete abb;
  delete abe;

  return 0;
}
