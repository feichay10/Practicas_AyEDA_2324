/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 2: El Juego de la Vida
 * @file functions.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/functions.h"

void textMenu() {
  std::cout << kBold << "\nComandos disponibles: " << kReset << std::endl;
  std::cout << kRedBold << "\t[x]" << kReset << " Salir del programa." << std::endl;
  std::cout << kRedBold << "\t[n]" << kReset << " Muestra la siguiente generacion." << std::endl;
  std::cout << kRedBold << "\t[L]" << kReset << " Muestra las siguientes 5 generaciones." << std::endl;
  std::cout << kRedBold << "\t[c]" << kReset << " Mostrar solo la población." << std::endl;
  std::cout << kRedBold << "\t[s]" << kReset << " Guardar la configuración actual en un fichero." << std::endl << std::endl;
}

void menu(Lattice &lattice) {
  std::string fileOut;
  char command;

  textMenu();
  
  do {
    std::cout << "Introduzca un comando: ";
    std::cin >> command;
    system("clear");
    switch (command) {
      case 'x':
        exit(EXIT_SUCCESS);
        break;
      case 'n':
        std::cout << std::endl;
        lattice.nextGeneration();
        std::cout << lattice;
        break;
      case 'L':
        cellEvolution(lattice);
        break;
      case 'c':
        std::cout << "Poblacion actual: " << lattice.Population() << std::endl;
        break;
      case 's':
        std::cout << "Introduzca el nombre del fichero: ";
        std::cin >> fileOut;
        lattice.saveToFile(fileOut);
        break;
      default:
        std::cout << "Comando no valido." << std::endl;
        break;
    }
    
    textMenu();

  } while (true);
}

void cellEvolution(Lattice &lattice) {
  std::cout << std::endl;
  for (int i = 0; i < 5; i++) {
    lattice.nextGeneration();
    std::cout << lattice;
  }
}