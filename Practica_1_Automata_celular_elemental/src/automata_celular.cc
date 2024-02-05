/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Autómata celular elemental
 * @file main.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../include/cell.h"
#include "../include/lattice.h"

const std::string kBold = "\033[1m";
const std::string kReset = "\033[0m";

std::string kUsage =
    kBold + "NAME\n\t" + kReset 
    + "automata_celular - Programa que simula un autómata celular elemental\n\n" +
    kBold + "SYNOPSIS\n\t" + kReset +
    "./main  -size <n> -border <b [v]> [-init <file>] \n\n" + kBold +
    "DESCRIPTION" + kReset + kBold + "\n\t-size <n>" + kReset +
    "\n\t\tn es el tamaño del retículo. Número de células \n\n" + kBold +
    "\t-border <b [v]>, b=open, v=[0|1]" + kBold + "\n\t\t\t b=periodic" +
    kReset + "\n\t\tFrontera abierta, fría o caliente.\n\n" + kBold +
    "\t-init <file>" + kReset +
    "\n\t\tfile es un nombre del fichero que contiene un array de estados con "
    "la configuración"
    "\n\t\tinicial del autómata celular. Si no se especifica se utilizará la "
    "configuración inicial"
    "\n\t\tpor defecto, esto es, un «1» en la célula central del retículo.";

int main(int argc, char* argv[]) {
  

  // return 0;
}