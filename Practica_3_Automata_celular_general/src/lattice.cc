/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file lattice.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Tiene la responsabilidad de crear y almacenar las células que
 * representan el espacio celular. Como la representación del espacio celular
 * requiere una estructura de datos diferente, según la dimensión del espacio,
 * se delega a las clases derivadas la especificación del atributo. a. A partir
 * de la clase base Lattice se derivan las clases para cada dimensión.
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/lattice.h"

// El constructor del reticulo inicializa los punteros de la estructura de
// datos con la dirección de la célula creada en memoria dinámica
Lattice::Lattice() {}

// El constructor del reticulo inicializa los punteros de la estructura de
// datos con la dirección de la célula creada en memoria dinámica
Lattice::Lattice(const char* filename, const FactoryCell& factory) {
  switch (factory) {
    
  }
}
