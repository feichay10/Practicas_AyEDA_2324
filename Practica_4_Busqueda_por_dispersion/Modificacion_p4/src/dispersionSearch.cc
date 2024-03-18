/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file dispersionSearch.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

#include "../include/functions.h"

// Ejecucion normal:
// 2 Ejecuciones: abierta y cerrada
// -ts 10 -fd mod -hash <open|close> -fe quadratic -bs 2 (insertar elementos que se inserten al indice 0)

// Modificacion: Crear la tabla, insertar elementos, aleatorios
// Añadimos por linea comando una nueva opcion -num n (num de nif aleatorios)
// Contar cuantas veces se ha ejecutado a a la exploracion

// Tabla aleatoria y cuantas veces se ejecuta la funcion de exploracion
// Datos a ejecutar: -num 500 y -num 3000
// -ts 151 -fd sum -hash close -fe redispersion -bs 30 -num n

int main(int argc, char* argv[]) {
  HashTableParameters parameters;
  try {
    parameters = checkProgramParameters(argc, argv, parameters);
    makeHashTable(parameters);
  } catch (std::string message) {
    std::cerr << message << std::endl;
  }
}