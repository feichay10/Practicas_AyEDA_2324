/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 2: El Juego de la Vida
 * @file lattice.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/lattice.h"

/**
 * @brief Constructor que crea las celulas en memoria dinamica (doble puntero),
 * con valor inicial de muerte. Este contructor se apoya de un metodo auxiliar
 * para solicitar por teclado las posiciones de las celulas que deben estar
 * vivas en la configuracion inicial.
 *
 * @param N
 * @param M
 */
Lattice::Lattice(int N, int M) {

}

/**
 * @brief Constructor que recibe como parámetro un nombre de un fichero. La primera
 * fila del fichero contiene el numero de filas (M) y columnas (N) del reticulo.
 * A continuación contiene las M cadenas de N caracteres, donde ' ' indica una
 * celula <muerda> y 'X' indica una celula <viva>.
 * 
 * @param file 
 */
Lattice::Lattice(const char* file) {

}


/**
 * @brief Tiene la responsabilidad de conocer la población, esto es el numero de
 * celulas vivas en la generación actual.
 * 
 * @return std::size_t 
 */
std::size_t Lattice::Population() const {
  std::size_t population = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      if (lattice_[i][j].getState() == kAlive) {
        population++;
      }
    }
  }
  return population;
}