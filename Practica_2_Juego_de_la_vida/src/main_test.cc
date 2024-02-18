// #include <iostream>
// #include <vector>
// #include <fstream>
// #include <cstdlib>
// #include <ctime>
// #include <string>

// // Definición del tipo de dato para la posición de la célula en el tablero
// struct Position {
//     int row;
//     int col;
// };

// // Clase que representa una célula en el juego de la vida
// class Cell {
// private:
//     bool alive; // Estado de la célula
//     Position position; // Posición de la célula en el tablero
//     std::vector<Cell*> neighbors; // Vecinos de la célula en la vecindad de
//     Moore

// public:
//     Cell(int row, int col) : alive(false) {
//         position.row = row;
//         position.col = col;
//     }

//     // Método para agregar un vecino a la célula
//     void addNeighbor(Cell* neighbor) {
//         neighbors.push_back(neighbor);
//     }

//     // Método para obtener el estado de la célula
//     bool isAlive() const {
//         return alive;
//     }

//     // Método para establecer el estado de la célula
//     void setAlive(bool state) {
//         alive = state;
//     }

//     // Método para calcular el número de vecinos vivos de la célula
//     int countAliveNeighbors() const {
//         int count = 0;
//         for (Cell* neighbor : neighbors) {
//             if (neighbor->isAlive()) {
//                 count++;
//             }
//         }
//         return count;
//     }

//     // Método para actualizar el estado de la célula en la siguiente
//     generación void update() {
//         int aliveNeighbors = countAliveNeighbors();
//         if (alive) {
//             alive = (aliveNeighbors == 2 || aliveNeighbors == 3);
//         } else {
//             alive = (aliveNeighbors == 3);
//         }
//     }

//     // Sobrecarga del operador de inserción para imprimir el estado de la
//     célula friend std::ostream& operator<<(std::ostream& os, const Cell&
//     cell) {
//         if (cell.isAlive()) {
//             os << 'X';
//         } else {
//             os << ' ';
//         }
//         return os;
//     }
// };

// // Clase que representa el tablero del juego de la vida
// class Lattice {
// private:
//     int rows; // Número de filas del tablero
//     int cols; // Número de columnas del tablero
//     std::vector<std::vector<Cell>> board; // Tablero como un vector
//     bidimensional de células std::size_t population; // Población del tablero
//     (número de células vivas)

//     // Método privado para inicializar el tablero con células muertas
//     void initializeBoard() {
//         for (int i = 0; i < rows; ++i) {
//             std::vector<Cell> row;
//             for (int j = 0; j < cols; ++j) {
//                 row.push_back(Cell(i, j));
//             }
//             board.push_back(row);
//         }
//     }

//     // Método privado para establecer las células vivas según un archivo de
//     inicialización void setLivingCellsFromFile(const std::string& filename) {
//         std::ifstream file(filename);
//         if (file.is_open()) {
//             char cellState;
//             for (int i = 0; i < rows; ++i) {
//                 for (int j = 0; j < cols; ++j) {
//                     file >> cellState;
//                     if (cellState == 'X') {
//                         board[i][j].setAlive(true);
//                     }
//                 }
//             }
//             file.close();
//         } else {
//             std::cerr << "Unable to open file: " << filename << std::endl;
//         }
//     }

// public:
//     // Constructor que crea un tablero de tamaño especificado con todas las
//     células muertas Lattice(int numRows, int numCols) : rows(numRows),
//     cols(numCols), population(0) {
//         initializeBoard();
//     }

//     // Constructor que crea un tablero a partir de un archivo de
//     inicialización Lattice(const std::string& filename) : population(0) {
//         std::ifstream file(filename);
//         if (file.is_open()) {
//             file >> rows >> cols;
//             initializeBoard();
//             setLivingCellsFromFile(filename);
//             file.close();
//         } else {
//             std::cerr << "Unable to open file: " << filename << std::endl;
//         }
//     }

//     // Método para obtener la población del tablero
//     std::size_t Population() const {
//         return population;
//     }

//     // Operador de acceso para obtener una referencia a una célula en una
//     posición dada Cell& operator[](const Position& pos) {
//         return board[pos.row][pos.col];
//     }

//     // Método para actualizar el estado del tablero en la siguiente
//     generación void updateBoard() {
//         for (int i = 0; i < rows; ++i) {
//             for (int j = 0; j < cols; ++j) {
//                 board[i][j].update();
//             }
//         }
//     }

//     // Método para imprimir el tablero en la consola
//     void printBoard() const {
//         for (int i = 0; i < rows; ++i) {
//             for (int j = 0; j < cols; ++j) {
//                 std::cout << board[i][j] << ' ';
//             }
//             std::cout << std::endl;
//         }
//     }
// };

// int main(int argc, char* argv[]) {
//     // Manejo de argumentos de línea de comandos
//     if (argc < 4 || argc > 6) {
//         std::cerr << "Usage: " << argv[0] << " -size <M> <N> [-init <file>]
//         -border <b>" << std::endl; return 1;
//     }

//     int rows, cols;
//     std::string filename = "";
//     std::string borderType = "";

//     for (int i = 1; i < argc; ++i) {
//         std::string arg = argv[i];
//         if (arg == "-size") {
//             if (i + 2 < argc) {
//                 rows = std::stoi(argv[i + 1]);
//                 cols = std::stoi(argv[i + 2]);
//             } else {
//                 std::cerr << "Missing arguments for -size option" <<
//                 std::endl; return 1;
//             }
//         } else if (arg == "-init") {
//             if (i + 1 < argc) {
//                 filename = argv[i + 1];
//             } else {
//                 std::cerr << "Missing argument for -init option" <<
//                 std::endl; return 1;
//             }
//         } else if (arg == "-border") {
//             if (i + 1 < argc) {
//                 borderType = argv[i + 1];
//             } else {
//                 std::cerr << "Missing argument for -border option" <<
//                 std::endl; return 1;
//             }
//         }
//     }

//     // Crear el tablero según los argumentos proporcionados
//     Lattice board(rows, cols);
//     if (!filename.empty()) {
//         board = Lattice(filename);
//     }

//     // Imprimir el tablero inicial
//     std::cout << "Initial board:" << std::endl;
//     board.printBoard();
//     std::cout << std::endl;

//     // Actualizar el tablero y mostrarlo en la consola
//     std::cout << "Next generation:" << std::endl;
//     board.updateBoard();
//     board.printBoard();

//     return 0;
// }

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Definición de la clase Position
class Position {
 public:
  int x;
  int y;
  Position(int x = 0, int y = 0) : x(x), y(y) {}
};

// Definición de la clase Cell
class Cell {
 private:
  bool alive;
  Position pos;
  std::vector<Position> neighbors;

 public:
  Cell(bool state = false, int x = 0, int y = 0) : alive(state), pos(x, y) {}

  void setAlive(bool state) { alive = state; }

  bool isAlive() const { return alive; }

  void setPosition(int x, int y) {
    pos.x = x;
    pos.y = y;
  }

  const Position& getPosition() const { return pos; }

  void addNeighbor(const Position& neighbor) { neighbors.push_back(neighbor); }

  int countAliveNeighbors(const std::vector<std::vector<Cell>>& lattice) const {
    int count = 0;
    for (const auto& neighborPos : neighbors) {
      int x = pos.x + neighborPos.x;
      int y = pos.y + neighborPos.y;
      if (x >= 0 && x < lattice.size() && y >= 0 && y < lattice[0].size()) {
        if (lattice[x][y].isAlive()) {
          count++;
        }
      }
    }
    return count;
  }

  void updateState(const std::vector<std::vector<Cell>>& lattice) {
    int aliveNeighbors = countAliveNeighbors(lattice);
    if (alive) {
      if (aliveNeighbors != 2 && aliveNeighbors != 3) {
        alive = false;
      }
    } else {
      if (aliveNeighbors == 3) {
        alive = true;
      }
    }
  }
};

// Definición de la clase Lattice
class Lattice {
 private:
  std::vector<std::vector<Cell>> grid;
  size_t population;

 public:
  Lattice(int M, int N) : population(0) {
    grid.resize(M, std::vector<Cell>(N));
  }

  Lattice(const char* filename) : population(0) {
    std::ifstream file(filename);
    if (!file.is_open()) {
      std::cerr << "Error: Unable to open file " << filename << std::endl;
      exit(EXIT_FAILURE);
    }
    int M, N;
    file >> M >> N;
    grid.resize(M, std::vector<Cell>(N));
    for (int i = 0; i < M; ++i) {
      std::string line;
      file >> line;
      for (int j = 0; j < N; ++j) {
        if (line[j] == 'X') {
          grid[i][j].setAlive(true);
          population++;
        }
      }
    }
    file.close();
  }

  size_t Population() const { return population; }

  const Cell& operator[](const Position& pos) const {
    return grid[pos.x][pos.y];
  }

  Cell& operator[](const Position& pos) { return grid[pos.x][pos.y]; }

  void print() const {
    for (const auto& row : grid) {
      for (const auto& cell : row) {
        std::cout << (cell.isAlive() ? 'X' : ' ');
      }
      std::cout << std::endl;
    }
  }

  void update() {
    population = 0;
    for (auto& row : grid) {
      for (auto& cell : row) {
        cell.updateState(grid);
        if (cell.isAlive()) {
          population++;
        }
      }
    }
  }
};

int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::cerr << "Usage: " << argv[0]
              << " -size <M> <N> [-init <file>] -border <reflective|noborder>"
              << std::endl;
    return 1;
  }

  int M = 0, N = 0;
  const char* filename = nullptr;
  std::string borderType;

  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg == "-size") {
      if (i + 2 < argc) {
        M = std::stoi(argv[++i]);
        N = std::stoi(argv[++i]);
      } else {
        std::cerr << "Error: Missing argument for -size" << std::endl;
        return 1;
      }
    } else if (arg == "-init") {
      if (i + 1 < argc) {
        filename = argv[++i];
      } else {
        std::cerr << "Error: Missing argument for -init" << std::endl;
        return 1;
      }
    } else if (arg == "-border") {
      if (i + 1 < argc) {
        borderType = argv[++i];
      } else {
        std::cerr << "Error: Missing argument for -border" << std::endl;
        return 1;
      }
    }
  }

  if (M <= 0 || N <= 0) {
    std::cerr << "Error: Invalid dimensions for lattice" << std::endl;
    return 1;
  }

  Lattice lattice(M, N);
  if (filename != nullptr) {
    lattice = Lattice(filename);
  }

  while (true) {
    lattice.print();
    std::cout << "Population: " << lattice.Population() << std::endl;
    std::cout << "Enter command (x: exit, n: next generation, L: next 5 "
                 "generations, c: toggle board display, s: save to file): ";
    char command;
    std::cin >> command;

    if (command == 'x') {
      break;
    } else if (command == 'n') {
      lattice.update();
    } else if (command == 'L') {
      for (int i = 0; i < 5; ++i) {
        lattice.update();
      }
    } else if (command == 'c') {
      lattice.print();
    } else if (command == 's') {
      std::string filename;
      std::cout << "Enter filename: ";
      std::cin >> filename;
      std::ofstream file(filename);
      if (file.is_open()) {
        file << M << ' ' << N << std::endl;
        for (int i = 0; i < M; ++i) {
          for (int j = 0; j < N; ++j) {
            file << (lattice[{i, j}].isAlive() ? 'X' : ' ');
          }
          file << std::endl;
        }
        file.close();
      } else {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
      }
    } else {
      std::cerr << "Unknown command" << std::endl;
    }
  }

  return 0;
}
