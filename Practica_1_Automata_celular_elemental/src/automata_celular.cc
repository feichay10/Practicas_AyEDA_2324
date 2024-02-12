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
 * @date
 *
 * @copyright Copyright (c) 2024
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
    kBold + "NOMBRE\n\t" + kReset +
    "automata_celular - Programa que simula un autómata celular elemental\n\n" +
    kBold + "SINÓPSIS\n\t" + kReset +
    "./main -size <n> -border <b [v]> [-init <file>] \n\n" + kBold +
    "DESCRIPCIÓN" + kReset + kBold + "\n\t-size <n>" + kReset +
    "\n\t\tn es el tamaño del retículo. Número de células \n\n" + kBold +
    "\t-border <b [v]>, b=open, v=[0|1]" + kBold + "\n\t\t\t b=periodic" +
    kReset +
    "\n\t\tFrontera abierta. Se considera que todas las células fuera "
    "del retículo tiene un valor fijo.\n \t\tSe dice una frontera es fría si "
    "las células fuera de la frontera tiene estado «0», y caliente\n \t\tsi"
    " tiene estado «1».\n \n\t\tFrontera periódica. Se considera que los "
    "extremos del retículo son adyacentes.\n\n" +
    kBold + "\t-init <file>" + kReset +
    "\n\t\tfile es un nombre del fichero que contiene un array de "
    "estados con la configuración \n\t\tinicial del autómata celular. "
    "Si no se especifica se utilizará la configuración inicial"
    "\n\t\tpor defecto, esto es, un «1» en la célula central del retículo.";

void check_size(int size, std::string file);

int main(int argc, char* argv[]) {
  try {
    if (argc == 2 && std::string(argv[1]) == "--help" || argc == 1) {
      std::cout << kUsage << std::endl;
      exit(EXIT_FAILURE);
    /*} else if (argc != 5 && argc != 7) {
      std::cerr << "Número de argumentos incorrecto. Use --help para más información" << std::endl; 
      exit(EXIT_FAILURE);*/
    } else {
      int size = std::stoi(argv[2]);
      borderType borderType = (std::string(argv[4]) == "open") ? kOpen : kPeriodic;
      openBorderType openBorderType = (std::string(argv[5]) == "0") ? kCold : kHot;
      std::string file = "";
      for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "-init") {
          file = argv[i + 1];
        }
      }

      check_size(size, file);

      Lattice lattice(size, borderType, openBorderType, file);
      std::cout << lattice << std::endl;
      for (int i = 0; i < 10; i++) {
        lattice.nextGeneration();
        std::cout << lattice << std::endl;
      }
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}

void check_size(int size, std::string file) {
  if (size <= 0) {
    std::cerr << "El tamaño del retículo debe ser un número mayor a cero." << std::endl;
    exit(EXIT_FAILURE);
  }

  if (file.empty()) {
    return;
  }

  int count = 0;
  if (!file.empty()) {
    std::ifstream file_config(file);
    if (file_config.is_open()) {
      std::string line;
      while (std::getline(file_config, line)) {
        count += line.size();
      }
    }
  }

  if (count != size) {
    std::cerr << "El tamaño del retículo no coincide con el tamaño del fichero." << std::endl;
    exit(EXIT_FAILURE);
  }
}