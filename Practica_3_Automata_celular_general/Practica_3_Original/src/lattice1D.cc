/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file lattice1D.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/lattice1D.h"
#include "../include/positionDim.h"

Lattice1D::Lattice1D(int& size, const FactoryCell& factory, borderType border) {
  dim_ = 1;
  size_ = size + 2;
  lattice_ = new Cell*[size_];
  borderType_ = border;
  Position* position;
  for (int i = 0; i < size_; i++) {
    position = new PositionDim<1>(1, i);
    lattice_[i] = factory.createCell(*position, kDead);
  }

  loadInitialLattice();
  if (borderType_ == kPeriodic) {
    lattice_[0]->setState(lattice_[size_ - 2]->getState());
    lattice_[size_ - 1]->setState(lattice_[1]->getState());
  }
}

Lattice1D::Lattice1D(const std::string& fileName, const FactoryCell& factory, borderType border) {
  std::ifstream file(fileName);
  std::string line;
  State state;
  borderType_ = border;
  Position* position;

  if (!file.is_open()) {
    std::cerr << "Error: File not found" << std::endl;
    exit(1);
  }

  file >> dim_;
  if (dim_ != 1) {
    std::cerr << "Error: Dimension mismatch" << std::endl;
    exit(1);
  }

  file >> size_;
  size_ += 2;
  lattice_ = new Cell*[size_];

  while (file >> line) {
    for (int i = 0; i < size_ - 2; i++) {
      position = new PositionDim<1>(1, i + 1);
      state = (line[i] == '0') ? kDead : kAlive;
      lattice_[i + 1] = factory.createCell(*position, state);
    }
  }

  if (borderType_ == kPeriodic) {
    lattice_[0]->setState(lattice_[size_ - 2]->getState());
    lattice_[size_ - 1]->setState(lattice_[1]->getState());
  }
}

Lattice1D::~Lattice1D() {
  for (int i = 0; i < size_; i++) {
    delete lattice_[i];
  }
  delete[] lattice_;
}

void Lattice1D::nextGeneration() {
  for (int i = 1; i < size_ - 1; i++) {
    lattice_[i]->nextState(*this);
  }
  for (int i = 1; i < size_ - 1; i++) {
    lattice_[i]->updateState();
  }

  if (borderType_ == kPeriodic) {
    lattice_[0]->setState(lattice_[size_ - 2]->getState());
    lattice_[size_ - 1]->setState(lattice_[1]->getState());
  }
}

std::size_t Lattice1D::Population() const {
  std::size_t population = 0;
  for (int i = 0; i < size_; i++) {
    if (lattice_[i]->getState() == kAlive) {
      population++;
    }
  }
  return population;
}

void Lattice1D::saveToFile(const std::string& fileName) const {
  std::ofstream output(fileName);
  if (!output.is_open()) {
    std::cerr << "Error: File could not be opened." << fileName << std::endl;
    exit(EXIT_FAILURE);
  }
  
  output << dim_ << std::endl;
  output << size_ - 2<< std::endl;
  for (int i = 1; i < size_ - 1; i++) {
    output << lattice_[i]->getState();
  }
  
  output.close();
}

std::ostream& Lattice1D::display(std::ostream& os) const {
  os << *lattice_[0] << "|";
  for (int i = 1; i < size_ - 1; i++) {
    os << *lattice_[i];
  }
  os << "|" << *lattice_[size_ - 1];
  return os;
}

void Lattice1D::loadInitialLattice() {
  std::string pos;
  int population = 0;
  std::cout << "Enter the position of the live cells." << std::endl;
  std::cout << "To finish, press 'q'. " << std::endl;
  std::cout << "\nCell " << population + 1 << std::endl;

  while (population <= size_ - 2) {
    std::cin >> pos;
    if (pos == "q") {
      break;
    }
    int position = std::stoi(pos);

    if (position < 1 || position > size_ - 1) {
      std::cerr << "Error: Position out of range" << std::endl;
      continue;
    }

    lattice_[position]->setState(kAlive);
    population++;
    std::cout << "\nCell " << population + 1 << std::endl;
  }

  system("clear");
}