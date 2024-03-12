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
#include "../include/functions.h"
#include "../include/hashTable.h"
#include "../include/nif.h"
#include "../include/sequence.h"
#include "../include/staticSequence.h"

const std::string kRedBold = "\033[1;31m";
const std::string kGreenBold = "\033[1;32m";
const std::string kBold = "\033[1m";
const std::string kReset = "\033[0m";

const std::string kUsage =
    "Usage: ./dispersionSearch -ts <s> -fd <f> -hash <open|close> -bs <s> -fe "
    "<f>"
    "\n\nOptions:"
    "\n  -ts <s>  Size of the table."
    "\n  -fd <f>  Code that identifies a dispersion function."
    "\n  -hash <open|close>  Indicates the dispersion technique to use."
    "\n  -bs <s>  Size of the block. Only for closed dispersion."
    "\n  -fe <f>  Code that identifies an exploration function. Only for "
    "closed dispersion."
    "\n  -help  Show this message.";

using keyType = Nif;

void makeHashTable(unsigned, std::string, std::string, unsigned, std::string);

#endif  // FUNCTIONS_H_