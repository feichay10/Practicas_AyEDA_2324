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
#include "../include/sortMethod.h"
#include "../include/selection.h"
#include "../include/quickSort.h"
#include "../include/heapSort.h"
#include "../include/shellSort.h"
#include "../include/radixSort.h"
#include "../include/insertion.h"

using keyType = Nif;

const std::string kUsage =
    BOLD + std::string("NAME\n") + RESET +
    std::string("       sortingAlgorithm - Sorting algorithms\n\n") + BOLD + std::string("SYNOPSIS\n") +
    RESET +
    std::string("       ./bin/sortingAlgorithm -size <s> -ord <m> -init <i> -trace <y|n>\n\n") +
    BOLD + std::string("DESCRIPTION\n") + RESET +
    std::string("       Program that allows to sort data a sequence in a specific order.\n\n") +
    BOLD + std::string("OPTIONS") + RESET + BOLD + std::string("\n\t  -size <s>") + RESET +
    std::string("\n\t\tSize of the sequence.\n") + BOLD +
    std::string("\n\t  -ord <m>, m = selection|quick|heap|shell|radix") + RESET +
    std::string("\n\t\tm is de code who identifies the sort method.\n") +
    BOLD + std::string("\n\t  -init <i> [f]") + RESET +
    std::string("\n\t\ti = manual. Enter sequence data manually") +
    std::string("\n\t\ti = random. Enter sequence data randomly") +
    std::string("\n\t\ti = manual. Enter sequence data by file") +
    std::string("\n\t\t    f = enter file name\n") +
    BOLD + std::string("\n\t  -trace <y|n>") + RESET +
    std::string("\n\t\tIndicates whether or not the trace is displayed during execution\n") + BOLD +
    BOLD + std::string("\n\t  -help") + RESET + std::string("\n\t\tShow this message.");

// Lista de los algoritmos de ordenacion disponibles
const std::set<std::string> kAvailableOrders = {"selection", "quick", "heap", "shell", "radix", "insertion", "merge"};

struct sortParameters {
  int size_;
  std::string order_;
  std::string init_;
  std::string file_;
  bool trace_;
};

sortParameters checkProgramParameters(int argc, char* argv[], sortParameters parameters);
void createSequence(sortParameters parameters);

#endif  // FUNCTIONS_H_