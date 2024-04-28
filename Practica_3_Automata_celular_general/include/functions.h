/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
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

#include "../include/Cell/cell.h"
#include "../include/Cell/cellACE110.h"
#include "../include/Cell/cellACE30.h"
#include "../include/Lattice/lattice.h"
#include "../include/Lattice/lattice1D.h"
#include "../include/Lattice/lattice1D_open.h"
#include "../include/Lattice/lattice1D_periodic.h"
#include "../include/Lattice/lattice2D.h"
#include "../include/Lattice/lattice2D_reflective.h"
#include "../include/Factory/factoryCell.h"
#include "../include/Factory/factoryCellACE110.h"
#include "../include/Factory/factoryCellACE30.h"
#include "../include/Factory/factoryCellLife23_3.h"
#include "../include/colors.h"

const std::string kUsage = "hola";
//     BOLD + "NOMBRE\n\t" + RESET +
//     "life_game - Programa que simula el juego de la vida\n\n" + BOLD +
//     "SINÓPSIS\n\t" + RESET + "./life_game [OPCIONES]... [FICHERO]... \n\n" +
//     BOLD + "DESCRIPCIÓN" + RESET + BOLD + "\n\t-size <M> <N>" + RESET +
//     "\n\t\t M es el número de filas y N es el numero de columnas del "
//     "tablero\n\n" +
//     BOLD + "\t-init <fichero>" + RESET +
//     "\n\t\tfichero es un nombre del fichero que contiene los valores iniciales "
//     "\n\t\tpara el estado de las células del tablero." +
//     "\n\n\t\tEl formato del fichero es el siguiente:" + "\n\t\tM N" +
//     "\n\t\tc11 c12 c13 ... c1N" + "\n\t\tc21 c22 c23 ... c2N" +
//     "\n\t\tc31 c32 c33 ... c3N" + "\n\t\t..." +
//     "\n\t\tformado por M filas y N columnas, donde cada cij es un 0 o un "
//     "1.\n\n" +
//     BOLD + "\n\t-border <b>, b=reflective" + BOLD + "\n\t\t     b=noborder";

enum cellType { ACE30 = 0, ACE110 = 1, Life23_3 = 2, Life51_346 = 3};
enum borderType { kOpen = 0, kPeriodic = 1, kNoBorder = 2, kReflective = 3};

struct parameters {
    int dimension;
    int rows = 0;
    int columns = 0;
    bool flagFile = false;
    std::string file;
    FactoryCell* factory;
    borderType border_Type;
    openBorderType open_BorderType;
};

void checkParameters(int argc, char* argv[], parameters &parameters);
void createLattice(parameters &parameters);

void textMenu();
void menu(Lattice &lattice);
void cellEvolution(Lattice &lattice);

#endif  // FUNCTIONS_H_