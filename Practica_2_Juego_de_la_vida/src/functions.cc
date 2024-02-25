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

#include <limits>
#include <thread>
#include <chrono>
#include "../include/functions.h"

void setBorder(Lattice &lattice, borderType borderType) {
  lattice.setBorderType(borderType);
}

void initialMenu(Lattice &lattice) {
  std::cout << "Initial lattice: " << std::endl;
  std::cout << lattice;
  std::cout << "Poblacion actual: " << lattice.Population() << std::endl;
  std::cout << "Tipo de frontera: " << (lattice.getBorderType() == kReflective ? "Reflective" : "No Border") << std::endl;
  while (true) {
    menu(lattice);
  }
}

void textMenu() {
  std::cout << kBold << "\nComandos disponibles: " << kReset << std::endl;
  std::cout << kRedBold << "\t[x]" << kReset << " Salir del programa." << std::endl;
  std::cout << kRedBold << "\t[n]" << kReset << " Muestra la siguiente generacion." << std::endl;
  std::cout << kRedBold << "\t[L]" << kReset << " Muestra las siguientes 5 generaciones." << std::endl;
  std::cout << kRedBold << "\t[c]" << kReset << " Mostrar solo la población." << std::endl;
  std::cout << kRedBold << "\t[s]" << kReset << " Guardar la configuración actual en un fichero." << std::endl;
  std::cout << kRedBold << "\t[a]" << kReset << " Generación automática" << std::endl << std::endl;
}

void menu(Lattice &lattice) {
  std::string fileOut;
  char command;

  // Limpiar el búfer de entrada para descartar el carácter de nueva línea
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
        std::cout << lattice;
        // cellEvolution(lattice);
        for (int i = 0; i < 5; i++) {
          lattice.nextGeneration();
          std::cout << lattice;
        }
        break;
      case 'c':
        std::cout << "Poblacion actual: " << lattice.Population() << std::endl;
        break;
      case 's':
        std::cout << "Introduzca el nombre del fichero: ";
        std::cin >> fileOut;
        lattice.saveToFile(fileOut);
        break;
      case 'a':
        cellEvolution(lattice);
        break;
      default:
        std::cout << "Comando no valido." << std::endl;
        break;
    }
    
    textMenu();

  } while (true);
}

void cellEvolution(Lattice &lattice) {
  std::cout << "Use ctrl + z para salir." << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(800));

  while (true) {
    lattice.nextGeneration();
    std::cout << lattice;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    system("clear");
  }
}