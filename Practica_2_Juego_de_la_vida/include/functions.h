/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 2: El Juego de la Vida
 * @file functions.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <chrono>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <thread>

#include "lattice.h"

const std::string kRedBold = "\033[1;31m";
const std::string kGreenBold = "\033[1;32m";
const std::string kBold = "\033[1m";
const std::string kReset = "\033[0m";

const std::string kUsage =
    kBold + "NOMBRE\n\t" + kReset +
    "life_game - Programa que simula el juego de la vida\n\n" + kBold +
    "SINÓPSIS\n\t" + kReset + "./life_game [OPCIONES]... [FICHERO]... \n\n" +
    kBold + "DESCRIPCIÓN" + kReset + kBold + "\n\t-size <M> <N>" + kReset +
    "\n\t\t M es el número de filas y N es el numero de columnas del "
    "tablero\n\n" +
    kBold + "\t-init <fichero>" + kReset +
    "\n\t\tfichero es un nombre del fichero que contiene los valores iniciales "
    "\n\t\tpara el estado de las células del tablero." +
    "\n\n\t\tEl formato del fichero es el siguiente:" + "\n\t\tM N" +
    "\n\t\tc11 c12 c13 ... c1N" + "\n\t\tc21 c22 c23 ... c2N" +
    "\n\t\tc31 c32 c33 ... c3N" + "\n\t\t..." +
    "\n\t\tformado por M filas y N columnas, donde cada cij es un 0 o un "
    "1.\n\n" +
    kBold + "\n\t-border <b>, b=reflective" + kBold + "\n\t\t     b=noborder";

void checkFile(std::string fileIn);
void setBorder(const std::string& arg, borderType& borderTypeVar, Lattice &lattice);
void textMenu();
void menu(Lattice &lattice);
void cellEvolution(Lattice &lattice);

#endif  // FUNCTIONS_H_