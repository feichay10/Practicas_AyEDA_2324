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
#include "../include/functions.h"

Lattice::Lattice() {}

Lattice::Lattice(int N, int M) {
  rows_ = N;
  columns_ = M;
  population_ = 0;
  lattice_.resize(N);
  for (int i = 0; i < N; i++) {
    lattice_[i].resize(M);
    for (int j = 0; j < M; j++) {
      lattice_[i][j] = new Cell(Position(i, j), kDead);
    }
  }
  loadInitialConfiguration(N, M);
  setFrontier();
}

Lattice::Lattice(const char* file) {
  std::ifstream input(file);
  if (!input.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo " << file << std::endl;
    exit(EXIT_FAILURE);
  }

  // Guardar el contenido del fichero sin comentarios que estaran seguidas por //
  std::string line;
  std::vector<std::string> fileContent;
  while (std::getline(input, line)) {
    if (line.substr(0, 2) != "//") {
      fileContent.push_back(line);
    }
  }

  rows_ = std::stoi(fileContent[0].substr(0, fileContent[0].find(' ')));
  columns_ = std::stoi(fileContent[0].substr(fileContent[0].find(' ') + 1, fileContent[0].size()));

  lattice_.resize(rows_);
  for (int i = 0; i < rows_; i++) {
    lattice_[i].resize(columns_);
    for (int j = 0; j < columns_; j++) {
      lattice_[i][j] = new Cell(Position(i, j), kDead);
    }
  }

  int i, j;
  for (int k = 1; k < fileContent.size(); k++) {
    i = std::stoi(fileContent[k].substr(0, fileContent[k].find(' ')));
    j = std::stoi(fileContent[k].substr(fileContent[k].find(' ') + 1, fileContent[k].size()));
    lattice_[i][j]->setState(kAlive);
  }

  input.close();
  setFrontier();
}

Lattice::~Lattice() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      delete lattice_[i][j];
    }
  }
  lattice_.clear();
}

int Lattice::getRows() const { return rows_; }

int Lattice::getColumns() const { return columns_; }

Cell& Lattice::getCell(const Position& position) const {
  return *lattice_[position.getRow()][position.getColumn()];
}

void Lattice::setBorderType(borderType borderType) {
  borderType_ = borderType;
}

borderType Lattice::getBorderType() const {
  return borderType_;
}

void Lattice::nextGeneration() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      lattice_[i][j]->nextState(*this);
    }
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      lattice_[i][j]->updateState();
    }
  }

  expandLattice();
}

std::size_t Lattice::Population() const { 
  size_t count = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      if (lattice_[i][j]->getState() == kAlive) {
        count++;
      }
    }
  }
  return count;
}

void Lattice::saveToFile(const std::string& fileOut) const {
  std::ofstream output(fileOut);
  if (!output.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo " << fileOut << std::endl;
    exit(EXIT_FAILURE);
  }
  output << rows_ << " " << columns_ << std::endl;

  // for (int i = 0; i < rows_; i++) {
  //   for (int j = 0; j < columns_; j++) {
  //     if (lattice_[i][j]->getState() == kAlive) {
  //       output << i << " " << j;
  //       output << std::endl;
  //     }
  //   }
  // }
  
  output << *this;
  output.close();
}

Cell& Lattice::operator[](const Position& position) {
  return getCell(position);
}

// Añade bordes al tablero para ver los limites del tablero
std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  os << kGreenBold << "+-";
  for (int i = 0; i < lattice.columns_ ; i++) {
    os << "--";
  }
  os << "+" << std::endl;
  for (int i = 0; i < lattice.rows_; i++) {
    os << "| " << kReset;
    for (int j = 0; j < lattice.columns_; j++) {
      os << lattice.lattice_[i][j]->getState() << " ";
      // os << kRedBold << *lattice.lattice_[i][j] << " " << kReset;
    }
    os << kGreenBold << "|" << std::endl;
  }
  os << "+-";
  for (int i = 0; i < lattice.columns_ ; i++) {
    os << "--";
  }
  os << "+" << kReset << std::endl;

  return os;
}

/**
 * @brief Metodo auxiliar que solicita por teclado las posiciones de las celulas
 * 
 * @param N: Numero de filas
 * @param M: Numero de columnas
 */
void Lattice::loadInitialConfiguration(int N, int M) {
  std::cout << "Introduce las posiciones de las celulas vivas (i j): " << std::endl;
  std::cout << "Para terminar, pulsa 'q'" << std::endl;
  int i, j;

  std::cout << "\nCelula " << population_ + 1 << std::endl;
  while (std::cin >> i >> j) {
    if (i >= N || j >= M) {
      std::cerr << "Error: Posicion fuera del tablero." << std::endl;
      continue;
    } else if (i < 0 || j < 0) {
      std::cerr << "Error: Posicion fuera del tablero." << std::endl;
      continue;
    } else if (std::cin.get() == 'q') {
      break;
    } else {
      lattice_[i][j]->setState(kAlive);
      population_++;
    }
    std::cout << "\nCelula " << population_ + 1 << std::endl;
  }
  std::cin.clear();
  system("clear");
}

void Lattice::setFrontier() {
  if (borderType_ == kReflective) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < columns_; j++) {
        if (i == 0 || i == rows_ - 1 || j == 0 || j == columns_ - 1) {
          lattice_[i][j]->setState(kDead);
        }
      }
    }
  } else {
    expandLattice();
  }
}

// Si se encuentra una celula viva en el borde, se expande el tablero una fila o
// columna más
void Lattice::expandLattice() {
  bool left = false;
  bool right = false;
  bool top = false;
  bool bottom = false;
  
  for (int i = 0; i < rows_; i++) {
    // Si hay una celula sobre el borde izquierdo
    if (lattice_[i][0]->getState() == kAlive) { 
      left = true;
    }
    // Si hay una celula sobre el borde derecho
    if (lattice_[i][columns_ - 1]->getState() == kAlive) {
      right = true;
    }
  }
  
  for (int j = 0; j < columns_; j++) {
    // Si hay una celula sobre el borde superior
    if (lattice_[0][j]->getState() == kAlive) {
      top = true;
    }
    // Si hay una celula sobre el borde inferior
    if (lattice_[rows_ - 1][j]->getState() == kAlive) { 
      bottom = true;
    }
  }

  // std::cout << "\nSe expande el tablero..." << std::endl;
  if (left) {
    columns_++;
    for (int i = 0; i < rows_; i++) {
      lattice_[i].resize(columns_);
      for (int j = columns_ - 1; j > 0; j--) {
        lattice_[i][j] = lattice_[i][j - 1];
      }
      lattice_[i][0] = new Cell(Position(i, 0), kDead);
    }
  } 
  
  if (right) {
    columns_++;
    for (int i = 0; i < rows_; i++) {
      lattice_[i].resize(columns_);
    }
    for (int i = 0; i < rows_; i++) {
      lattice_[i][columns_ - 1] = new Cell(Position(i, columns_ - 1), kDead);
    }
  }

  if (top) {
    rows_++;
    lattice_.resize(rows_);
    for (int i = rows_ - 1; i > 0; i--) {
      lattice_[i].resize(columns_);
      for (int j = 0; j < columns_; j++) {
        lattice_[i][j] = lattice_[i - 1][j];
      }
    }
    for (int j = 0; j < columns_; j++) {
      lattice_[0][j] = new Cell(Position(0, j), kDead);
    }
  }
  
  if (bottom) {
    rows_++;
    lattice_.resize(rows_);
    for (int i = rows_ - 1; i > 0; i--) {
      lattice_[i].resize(columns_);
    }
    for (int j = 0; j < columns_; j++) {
      lattice_[rows_ - 1][j] = new Cell(Position(rows_ - 1, j), kDead);
    }
  } 
}