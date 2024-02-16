/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Autómata celular elemental
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

#include <iostream>
#include <string>
#include <fstream>

#include "lattice.h"

const std::string kBold = "\033[1m";
const std::string kReset = "\033[0m";

const std::string kUsage = 
    kBold + "NOMBRE\n\t" + kReset +
    "automata_celular - Programa que simula un autómata celular elemental\n\n" +
    kBold + "SINÓPSIS\n\t" + kReset +
    "./automata_celular [OPTION]... [FILE]... \n\n" + kBold +
    "DESCRIPCIÓN" + kReset + kBold + "\n\t-size <n>" + kReset +
    "\n\t\tn es el tamaño del retículo. Número de células \n\n" + kBold +
    "\t-border <b [v]>, b=open, v=[0|1]" + kBold + "\n\t\t\t b=periodic" +
    kReset +
    "\n\t\tFrontera abierta. Se considera que todas las células fuera "
    "del retículo tiene un valor fijo.\n \t\tSe dice una frontera es fría si "
    "las células fuera de la frontera tiene estado «0», y caliente\n \t\tsi"
    " tiene estado «1».\n \n\t\tFrontera periódica. Se considera que los "
    "extremos del retículo son adyacentes.\n\n" +
    kBold + "\t-init <file> -> opcion opcional" + kReset +
    "\n\t\tfile es un nombre del fichero que contiene un array de "
    "estados con la configuración \n\t\tinicial del autómata celular. "
    "Si no se especifica se utilizará la configuración inicial"
    "\n\t\tpor defecto, esto es, un «1» en la célula central del retículo." + 
    kBold + "\n\n\t-help" + kReset + "\n\t\tMuestra esta ayuda y finaliza.\n\n";

void checkSize(int size, std::string file);
void checkFile(std::string file);
// void setCellEvolutionOnFile(Lattice &lattice, std::string file);
void cellEvolution(Lattice &lattice, std::string file);

#endif  // FUNCTIONS_H_