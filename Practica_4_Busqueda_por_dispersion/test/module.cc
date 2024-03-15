#include <iostream>

int main(int argc, char* argv[]) {
  int operation = atoi(argv[1]) % 5;

  std::cout << "Resultado: " << operation << std::endl;
}