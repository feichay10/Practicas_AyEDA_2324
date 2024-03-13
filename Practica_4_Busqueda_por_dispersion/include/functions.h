/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file functions.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <string>

#include "../include/dfModule.h"
#include "../include/dfRandom.h"
#include "../include/dfSum.h"
#include "../include/dispersionFunction.h"
#include "../include/dynamicSequence.h"
#include "../include/efDoubleDispersion.h"
#include "../include/efLineal.h"
#include "../include/efQuadratic.h"
#include "../include/efRedispersion.h"
#include "../include/explorationFunction.h"
#include "../include/hashTable.h"
#include "../include/nif.h"
#include "../include/sequence.h"
#include "../include/staticSequence.h"

const std::string kRedBold = "\033[1;31m";
const std::string kGreenBold = "\033[1;32m";
const std::string kBold = "\033[1m";
const std::string kReset = "\033[0m";

const std::string kUsage =
    kBold + "NOMBRE\n" + kReset +
    "       dispersionSearch - Dispersed Search\n\n" + kBold + "SINOPSIS\n" +
    kReset +
    "       ./dispersionSearch -ts <s> -fd <f> -hash <open|close> -bs <s> -fe "
    "<f>\n\n" +
    kBold + "DESCRIPCIÓN\n" + kReset +
    "       Program that performs a dispersed search in a hash table.\n\n" +
    kBold + "OPCIONES" + kReset + kBold + "\n\t  -ts <s>" + kReset +
    "\n\t\tSize of the table.\n" + kBold +
    "\n\t  -fd <f>, f = module|sum|random" + kReset +
    "\n\t\tCode that identifies a dispersion function.\n" + kBold +
    "\n\t  -hash <open|close>" + kReset +
    "\n\t\tIndicates the dispersion technique to use.\n" + kBold +
    "\n\t  -bs <s>" + kReset +
    "\n\t\tSize of the block. Only for closed dispersion.\n" + kBold +
    "\n\t  -fe <f>, f = lineal|quadratic|double|redispersion" + kReset +
    "\n\t\tCode that identifies an exploration function. Only for closed "
    "dispersion.\n" +
    kBold + "\n\t  -help" + kReset + "\n\t\tShow this message.";

using keyType = Nif;

struct HashTableParameters {
  unsigned tableSize = 0;
  std::string df = "module";
  std::string dispersionTechnic = "open";
  unsigned blockSize = 0;
  std::string ef = "lineal";
};

HashTableParameters checkProgramParameters(int, char*[], HashTableParameters&);
void makeHashTable(HashTableParameters&);
void menu(HashTable<keyType, DynamicSequence<keyType>>&);

#endif  // FUNCTIONS_H_