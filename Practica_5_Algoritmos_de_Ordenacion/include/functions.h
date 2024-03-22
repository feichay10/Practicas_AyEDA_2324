/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file functions.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <string>
#include <iomanip>
#include <set>
#include <filesystem>

#include "../include/nif.h"
#include "../include/sequence.h"
#include "../include/staticSequence.h"
#include "../include/colors.h"

const std::string kUsage =
    BOLD + std::string("NAME\n") + RESET +
    std::string("       dispersionSearch - Dispersed Search\n\n") + BOLD + std::string("SYNOPSIS\n") +
    RESET +
    std::string("       ./dispersionSearch -ts <s> -fd <f> -hash <open|close> -bs <s> -fe <f>\n\n") +
    BOLD + std::string("DESCRIPTION\n") + RESET +
    std::string("       Program that performs a dispersed search in a hash table.\n\n") +
    BOLD + std::string("OPCIONES") + RESET + BOLD + std::string("\n\t  -ts <s>") + RESET +
    std::string("\n\t\tSize of the table.\n") + BOLD +
    std::string("\n\t  -fd <f>, f = module|sum|random") + RESET +
    std::string("\n\t\tCode that identifies a dispersion function. If dispersion function is not \n\t\tprovided, the default will be the modulus function\n") +
    BOLD + std::string("\n\t  -hash <open|close>") + RESET +
    std::string("\n\t\tIndicates the dispersion technique to use. If dispersion technique is not \n\t\tprovided, the default will be the open.\n") +
    BOLD + std::string("\n\t  -bs <s>") + RESET +
    std::string("\n\t\tSize of the block. Only for closed dispersion.\n") + BOLD +
    std::string("\n\t  -fe <f>, f = lineal|quadratic|double|redispersion [fd]") + RESET +
    std::string( "\n\t\tCode that identifies an exploration function. Only for closed dispersion. \n\t\tIf explotration function is not provided, the default will be the lineal \n\t\tfunction.\n") +
    std::string("\n\t\tIf redispersion functions is provided, in the next parameters it must \n\t\tprovided a avalaible dispersion function") +
    BOLD + std::string("\n\t  -help") + RESET + std::string("\n\t\tShow this message.");

using keyType = Nif;

struct sortParameters {
  int size_;
  std::string order_;
  std::string init_;
  std::string file_;
  bool trace_;
};

// Crear una lista de los algoritmos de ordenacion disponibles
const std::set<std::string> kAvailableOrders = {"selection", "quick", "heap", "shell", "radix"};

sortParameters checkProgramParameters(int argc, char* argv[], sortParameters parameters);

#endif  // FUNCTIONS_H_