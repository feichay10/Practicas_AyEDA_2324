/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file functions.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/functions.h"

/**
 * @brief Check the program parameters and return the sort parameters.
 * 
 * @param argc 
 * @param argv 
 * @param parameters 
 * @return sortParameters 
 */
sortParameters checkProgramParameters(int argc, char* argv[], sortParameters parameters) { 
  if (argc == 2 && std::string(argv[1]) == "-help") {
    std::cout << kUsage << std::endl;
    exit(EXIT_SUCCESS);
  } else if (argc == 1) {
    throw std::runtime_error("No arguments provided. Use " + std::string(argv[0]) + " -help for more information.");
  }

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "modification") {
      parameters.modification_ = true;
    }
  }

  return parameters;
}

/**
 * @brief Create the sequence with the sort parameters.
 * 
 * @param parameters 
 */
void createSequence(sortParameters parameters) {
  StaticSequence<keyType> sequenceOneHundred(100);
  StaticSequence<keyType> sequenceOneThousands(1000);

  SortMethod<keyType>* selectionMethodOneHundred = new Selection<keyType>(sequenceOneHundred, 100);
  SortMethod<keyType>* quickMethodOneHundred = new QuickSort<keyType>(sequenceOneHundred, 100);
  SortMethod<keyType>* selectionMethodOneThousands = new Selection<keyType>(sequenceOneThousands, 1000);
  SortMethod<keyType>* quickMethodOneThousands = new QuickSort<keyType>(sequenceOneThousands, 1000);

  for (int i = 0; i < 100; i++) {
    keyType key;
    sequenceOneHundred[i] = key;
  }

  for (int i = 0; i < 1000; i++) {
    keyType key;
    sequenceOneThousands[i] = key;
  }

  selectionMethodOneHundred->Sort();
  quickMethodOneHundred->Sort();
  selectionMethodOneThousands->Sort();
  quickMethodOneThousands->Sort();

  std::cout << "+------------+---------+---------------+" << RESET << std::endl;
  std::cout << "| Metodo     | Size    | Comparaciones |" << std::endl;
  std::cout << "+------------+---------+---------------+" << RESET << std::endl;
  std::cout << "| Selection  | 100     | " << selectionMethodOneHundred->getCountComparation() << std::setw(11) << " |" << std::endl;
  std::cout << "| Quick      | 100     | " << quickMethodOneHundred->getCountComparation() << std::setw(12) << " |" << std::endl;
  std::cout << "| Selection  | 1000    | " << selectionMethodOneThousands->getCountComparation() << std::setw(9) << " |" << std::endl;
  std::cout << "| Quick      | 1000    | " << quickMethodOneThousands->getCountComparation() << std::setw(11) << " |" << std::endl;
  std::cout << "+------------+---------+---------------+" << RESET << std::endl;
}