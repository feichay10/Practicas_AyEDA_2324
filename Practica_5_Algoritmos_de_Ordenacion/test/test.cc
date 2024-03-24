#include "../include/selection.h"
#include "../include/staticSequence.h"
#include "../include/nif.h"

#include <iostream>
#include <string>

using keyType = Nif;

int main() {
  int size = 8;
  StaticSequence<keyType> sequence(size);
  Selection<keyType>* selection = new Selection<keyType>();
  
  for (int i = 0; i < size; i++) {
    keyType key;
    std::cout << "Enter key " << i << ": ";
    std::cin >> key;
    // sequence[i] = key;
    sequence.insert(key);
  }

  std::cout << "Unsorted sequence: ";
  for (int i = 0; i < size; i++) {
    std::cout << sequence[i] << " ";
  }

  selection->Sort(sequence, size);

  std::cout << "\nSorted sequence:   ";
  for (int i = 0; i < size; i++) {
    std::cout << sequence[i] << " ";
  }
}