/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 7: Implementacion del TDA AVL
 * @file treeTDA_modification.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

// TODO: Modificacion
// Comparar ABB y AVL y en el metodo de insercion, contabilizar las comparaciones a la hora de insertar
// Calcular numero de comparaciones en el AVL y ABB
// Insertar de forma aleatoria y hacer una grafica de las comparaciones
// insertar: 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, ...

// Tabla de comparaciones
// | Numero de claves  | Comparaciones ABB  | Comparaciones AVL |
// |-------------------|--------------------|-------------------|
// | 16                |        51          |       46          |
// | 32                |       130          |      114          |
// | 64                |       323          |      310          |
// | 128               |       870          |      756          |

#include "../include/functions.h"

#include "../include/ABB.h"
#include "../include/AVL.h"

using keyType = Nif;

int main(int argc, char* argv[]) {
  AB<keyType>* treeABB = new ABB<keyType>;
  AB<keyType>* treeAVL = new AVL<keyType>;

  int numKeys = 0;
  numKeys = std::stoi(argv[1]);

  for (int i = 0; i < numKeys; i++) {
    keyType key;
    treeABB->insert(key);
    treeAVL->insert(key);
  }

  std::cout << "Number of comparisons on ABB: " << treeABB->getComparisons() << std::endl;
  std::cout << "Number of comparisons on AVL: " << treeAVL->getComparisons() << std::endl;

  delete treeABB;
  delete treeAVL;
}