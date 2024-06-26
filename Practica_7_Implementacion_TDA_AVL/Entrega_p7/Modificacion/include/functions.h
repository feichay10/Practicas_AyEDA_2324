/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 7: Implementacion del TDA AVL
 * @file functions.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-29
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
#include <fstream>

#include "colors.h"
#include "nif.h"
#include "AB.h"
#include "ABB.h"
#include "ABE.h"
#include "AVL.h"

using keyType = Nif;

const std::string kUsage =
    BOLD + std::string("NAME\n") + RESET +
    std::string("       treeTDA - Type Data Abstract Tree\n\n") + BOLD + std::string("SYNOPSIS\n") +
    RESET +
    std::string("       ./bin/treeTDA -ab <abe|abb|avl> -init <i> [s] [f]\n\n") +
    BOLD + std::string("DESCRIPTION\n") + RESET +
    std::string("       Program that performs an implementation of its algorithms and empirically tests the computational complexity of TDA.\n\n") +
    BOLD + std::string("OPTIONS") + RESET + BOLD + std::string("\n\t  -ab <abe|abb|avl>") + RESET +
    std::string("\n\t\tTo indicate the type of tree to work with.\n") + BOLD +
    BOLD + std::string("\n\t  -init <i> [s] [f]") + RESET +
    std::string("\n\t\ti = manual. Enter elements tree data manualy.") +
    std::string("\n\t\ti = random [s]. Enter elements tree data randomly.") +
    std::string("\n\t\ti = file [s] [f]. Enter elements tree data by file.") +
    std::string("\n\t\t    s = enter number of elements to generate.") +
    std::string("\n\t\t    f = enter file name.\n") +
    std::string("\n\t  -trace <y|n>") + std::string("\n\t\tTo show the trace of the AVL tree. Mandatory option if AVL type tree is executed\n") +
    BOLD + std::string("\n\t  -help") + RESET + std::string("\n\t\tShow this message.");

struct treeParameters {
  std::string treeType_;
  std::string init_;
  int numberGenerated_;
  std::string file_;
  bool trace_;
};

treeParameters checkProgramParameters(int argc, char* argv[], treeParameters& parameters);
void printInformation(treeParameters& parameters);
void createTree(treeParameters& parameters);
void menu(AB<keyType>* tree, treeParameters& parameters);

#endif // FUNCTIONS_H
