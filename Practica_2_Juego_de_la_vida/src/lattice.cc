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

Lattice::Lattice(int size, borderType borderType, openBorderType openBorderType,
                 std::string file) {}

Lattice::~Lattice() {}

Cell& Lattice::getCell(const Position& position) const {}

int Lattice::getSize() const {}

void Lattice::setSize(int size) {}

borderType Lattice::getBorderType() {}

void Lattice::setBorderType(borderType borderType) {}

void Lattice::nextGeneration() {}

std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {}

void Lattice::printLatticeInformation(std::string file) {}

void Lattice::loadInitialConfiguration(std::string file) {}

void Lattice::setFrontier() {}