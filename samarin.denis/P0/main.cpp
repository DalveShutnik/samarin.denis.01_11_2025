#include <iostream>

int** convert(const int* t, size_t n, const size_t* lens, size_t rows);

int main() {

}


int** convert(const int* t, size_t n, const size_t* lens, size_t rows){

  int** result = new int*[rows];
  size_t current_index = 0;

  for (size_t i = 0; i < rows; i++) {

    size_t current_length = lens[i];
    result[i] = new int[current_length];

    for (size_t j = 0; j < current_length; j++) {
      if (current_index < n) {
        result[i][j] = t[current_index];
        current_index++;
      } else {
        result[i][j] = 0;
      }
    }
  }

  return result;
}