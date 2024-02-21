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

#include <fstream>
#include <iostream>
#include <string>

#include "lattice.h"

const std::string kRedBold = "\033[1;31m";
const std::string kBold = "\033[1m";
const std::string kReset = "\033[0m";

const std::string kUsage =
    kBold + "\n\nNOMBRE\n\t" + kReset +
    "life_game - Programa que simula el juego de la vida\n\n" +
    kBold + "SINÓPSIS\n\t" + kReset +
    "./life_game [OPCIONES]... [FICHERO]... \n\n" + kBold +
    "DESCRIPCIÓN" + kReset + kBold + "\n\t-size <n>" + kReset +
    "\n\t\tn es el tamaño del retículo. Número de células \n\n" + kBold +
    "\t-border <b [v]>, b=open, v=[0|1]" + kBold + "\n\t\t\t b=periodic" +
    "\n\t\t\t b=reflector" + kReset +
    "\n\t\tFrontera abierta. Se considera que todas las células fuera "
    "del retículo tiene un valor fijo.\n \t\tSe dice una frontera es fría si "
    "las células fuera de la frontera tiene estado «0», y caliente\n \t\tsi"
    " tiene estado «1».\n \n\t\tFrontera periódica. Se considera que los "
    "extremos del retículo son adyacentes.\n" +
    "\n\t\tFrontera reflectora. Se considera que las células fuera del "
    "retículo reflejan a las células \n\t\tadyacentes al borde dentro del "
    "retículo.\n\n " +
    kBold + "\t-init <fichero> -> opcional" + kReset +
    "\n\t\tfichero es un nombre del fichero que contiene un array de "
    "estados con la configuración \n\t\tinicial del autómata celular. "
    "Si no se especifica se utilizará la configuración inicial"
    "\n\t\tpor defecto, esto es, un «1» en la célula central del retículo.";

void cellEvolution(Lattice &lattice);
void menu();

#endif  // FUNCTIONS_H_