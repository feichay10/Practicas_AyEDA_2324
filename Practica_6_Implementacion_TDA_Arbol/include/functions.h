/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementacion del TDA Árbol
 * @file functions.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <set>
#include <filesystem>

#include "colors.h"
#include "nif.h"
#include "AB.h"

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
    std::string("\n\t  -ord <m>, m = selection|quick|heap|shell|radix|insertion|merge|bin|bubble|shake") + RESET +
    std::string("\n\t\tm is the code for the sorting algorithm to be used.\n") +
    BOLD + std::string("\n\t  -init <i> [f]") + RESET +
    std::string("\n\t\ti = manual. Enter sequence data manually.") +
    std::string("\n\t\ti = random. Enter sequence data randomly.") +
    std::string("\n\t\ti = file. Enter sequence data by file.") +
    std::string("\n\t\t    f = enter file name.\n") +
    BOLD + std::string("\n\t  -trace <y|n>") + RESET +
    std::string("\n\t\tIndicates whether or not the trace is displayed during execution.\n") + BOLD +
    BOLD + std::string("\n\t  -help") + RESET + std::string("\n\t\tShow this message.");

struct treeParameters {
  std::string treeType_;
  std::string init_;
  int numberGenerated_;
  std::string file_;
};

treeParameters checkProgramParameters(int argc, char* argv[], treeParameters& parameters);
void printInformation(treeParameters& parameters);
void createTree(treeParameters& parameters);
void menu();

#endif // FUNCTIONS_H
