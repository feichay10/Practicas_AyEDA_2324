/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file explorationFunction.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef EXPLORATIONFUNCTION_H
#define EXPLORATIONFUNCTION_H

/**
 * @brief Abstract class that represents the exploration function
 * 
 * @tparam Key 
 */
template <class Key>
class ExplorationFunction {
 public:
  virtual unsigned operator()(const Key&, unsigned) const = 0;
};

#endif  // EXPLORATIONFUNCTION_H