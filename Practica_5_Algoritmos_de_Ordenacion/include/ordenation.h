/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file ordenation.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ORDENATION_H
#define ORDENATION_H

#include "sortMethod.h"
#include "staticSequence.h"
#include "functions.h"

// El codigo de los metodos de ordenacion estaran aqui
// Son plantilla de funciones

// Funciones auxiliares

template <typename Key>
void swap(Key& a, Key& b) {
  Key temp = a;
  a = b;
  b = temp;
}

template <typename Key>
void print(StaticSequence<Key>& sequence, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << sequence[i] << sequence[i].letterNif(sequence[i]) << " ";
  }
}

// Metodos de ordenacion

// Algoritmo de ordenacion por seleccion
template <typename Key>
void selection(StaticSequence<Key>& sequence, int size) {
  Key temp;
  for (int i = 0; i < size - 1; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
      if (sequence[j] < sequence[min]) {
        min = j;
      }
    }
    swap(sequence[i], sequence[min]);
    if (trace) {
      print(sequence, size);
      std::cout << std::endl;
    }
  }
}

// Algoritmo de ordenacion por QuickSort
template <typename Key>
void quickSort(StaticSequence<Key>& sequence, int begin, int end) {
  int i = begin;
  int j = end;
  int size = end + 1;
  Key pivot = sequence[(begin + end) / 2];
  if (trace) {
    std::cout << "Pivot: " << pivot << "\t    ";
  }
  while (i <= j) {
    while (sequence[i] < pivot) i++;
    while (sequence[j] > pivot) j--;
    if (i <= j) {
      swap(sequence[i], sequence[j]);
      i++;
      j--;
    }
  }
  if (trace) {
    print(sequence, size);
    std::cout << std::endl;
  }
  if (begin < j) quickSort(sequence, begin, j);
  if (i < end) quickSort(sequence, i, end);
}

// Algoritmo de ordenacion por HeapSort
template <typename Key>
void heapSort(StaticSequence<Key>& sequence, int size) {
  for (int i = size / 2; i >= 0; i--) {
    downHeap(i, sequence, size - 1);
  }
  for (int i = size - 1; i > 0; i--) {
    swap(sequence[0], sequence[i]);
    downHeap(0, sequence, i - 1);
  }
}

template <typename Key>
void downHeap(int i, StaticSequence<Key>& sequence, int size) {
  int h1, h2, h;
  while (2 * i <= size) {
    h1 = 2 * i;
    h2 = h1 + 1;
    if (h1 == size) {
      h = h1;
    } else if (sequence[h1] > sequence[h2]) {
      h = h1;
    } else {
      h = h2;
    }
    if (sequence[h] <= sequence[i]) {
      break;
    } else {
      swap(sequence[i], sequence[h]);
      i = h;
    }
    if (trace) {
      std::cout << "\t\t    ";
      print(sequence, size);
      std::cout << std::endl;
    }
  }
}

// Algoritmo de ordenacion por ShellSort
template <typename Key>
void shellSort(StaticSequence<Key>& sequence, int size) {
  int delta = size;
  while (delta > 1) {
    delta = delta / 2;
    deltaSort(delta, sequence, size);
  }
}

template <typename Key>
void deltaSort(int delta, StaticSequence<Key>& sequence, int size) {
  for (int i = delta; i < size; i++) {
    Key temp = sequence[i];
    int j = i;
    while ((j >= delta) && (temp < sequence[j - delta])) {
      sequence[j] = sequence[j - delta];
      j = j - delta;
    }
    sequence[j] = temp;
  }
  if (trace) {
    std::cout << "\t\t    ";
    print(sequence, size);
    std::cout << std::endl;
  }
}

// Algoritmo de ordenacion por RadixSort
template <typename Key>
void radixSort(StaticSequence<Key>& sequence, int size) {
  int max = sequence[0];
  for (int i = 1; i < size; i++) {
    if (sequence[i] > max) {
      max = sequence[i];
    }
  }

  for (int exp = 1; max / exp > 0; exp *= 10) {
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++) {
      count[(sequence[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
      output[count[(sequence[i] / exp) % 10] - 1] = sequence[i];
      count[(sequence[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++) {
      sequence[i] = output[i];
    }
    if (trace) {
      std::cout << "\t\t    ";
      print(sequence, size);
      std::cout << std::endl;
    }
  }
}

// Algoritmo de ordenacion por Insertion
template <typename Key>
void insertion(StaticSequence<Key>& sequence, int size) {
  for (int i = 1; i < size; i++) {
    Key temp = sequence[i];
    int j = i - 1;
    while ((j >= 0) && (sequence[j] > temp)) {
      sequence[j + 1] = sequence[j];
      j--;
    }
    sequence[j + 1] = temp;
    if (trace) {
      std::cout << "\ti = " << i;
      std::cout << "\t    "; 
      print(sequence, size);
      std::cout << "\tj = " << j + 1;
      std::cout << std::endl;
    }
  }
}

// Algoritmo de ordenacion por MergeSort
template <typename Key>
void mergeSort(StaticSequence<Key>& sequence, int begin, int end) {
  if (begin < end) {
    int middle = (begin + end) / 2;
    mergeSort(sequence, begin, middle);
    mergeSort(sequence, middle + 1, end);
    mix(sequence, begin, middle, end);
  }
}

template <typename Key>
void mix(StaticSequence<Key>& sequence, int begin, int middle, int end) {
  int i = begin;
  int j = middle + 1;
  int size = end + 1;
  StaticSequence<Key> temp(end + 1);

  for (int k = begin; k <= end; k++) {
    if (i <= middle && (j > end || sequence[i] <= sequence[j])) {
      temp[k] = sequence[i];
      i++;
    } else {
      temp[k] = sequence[j];
      j++;
    }
  }

  for (int k = begin; k <= end; k++) {
    sequence[k] = temp[k];
  }

  if (trace) {
    std::cout << "\t\t    ";
    print(sequence, size);
  }
}

// Algoritmo de ordenacion por binSort
template <typename Key>
void binSort(StaticSequence<Key>& sequence, int size) {
  for (int i = 1; i < size; i++) {
    int j = i;
    Key temp = sequence[i];
    int start = 0;
    int end = i - 1;
    while (start <= end) {
      int middle = (start + end) / 2;
      if (sequence[middle] < temp) {
        start = middle + 1;
      } else {
        end = middle - 1;
      }
    }
    for (int k = i - 1; k >= start; k--) {
      sequence[k + 1] = sequence[k];
    }
    sequence[start] = temp;
    if (trace) {
      std::cout << "\t\t    "; 
      print(sequence, size);
      std::cout << std::endl;
    }
  }
}

// Algoritmo de ordenacion por bubbleSort
template <typename Key>
void bubbleSort(StaticSequence<Key>& sequence, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (sequence[j] > sequence[j + 1]) {
        std::swap(sequence[j], sequence[j + 1]);
      }
    }
    if (trace) {
      std::cout << "\t\t    ";
      print(sequence, size);
      std::cout << std::endl;
    }
  }
}

template <typename Key>
void shakeSort(StaticSequence<Key>& sequence, int size) {
  int start = 1;
  int end = size - 1;
  int cam = size;
  while (start <= end) {
    for (int i = end; i >= start; i--) {
      if (sequence[i] < sequence[i - 1]) {
        swap(sequence[i - 1], sequence[i]);
        cam = i;
      }
      if (trace) {
        std::cout << "\t\t    ";
        print(sequence, size);
        std::cout << std::endl;
      }
    }
    start = cam + 1;
    for (int i = start; i <= end; i++) {
      if (sequence[i] < sequence[i - 1]) {
        swap(sequence[i - 1], sequence[i]);
        cam = i;
      }
      if (trace) {
        std::cout << "\t\t    ";
        print(sequence, size);
        std::cout << std::endl;
      }
    }
    end = cam - 1;
  }
}

#endif // ORDENATION_H