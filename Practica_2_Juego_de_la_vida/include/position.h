/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 2: El Juego de la Vida
 * @file position.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Espacio diminsional de dos coordenadas del reticulo, se representa
 * con esta clase Position para representar las filas y columnas del reticulo
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef POSITION_H_
#define POSITION_H_

class Position {
 public:
  Position(int row, int column);
  ~Position();

  int getRow() const;
  int getColumn() const;

  void setRow(int row);
  void setColumn(int column);

 private:
  int row_;
  int column_;
};

#endif  // POSITION_H_