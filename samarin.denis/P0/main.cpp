#include <iostream>

int** convert(const int* t, size_t n, const size_t* lns, size_t rows);

int main() {
    try {
        size_t n, rows;

        std::cin >> n >> rows;

        if (!(std::cin)) {
            return 1;
        }

        size_t* lns = new size_t[rows];

        for (size_t i = 0; i < rows; i++) {

            std::cin >> lns[i];

            if (!(std::cin)) {
                delete[] lns;
                return 1;
            }
        }

        int* t = new int[n];
        for (size_t i = 0; i < n; i++) {
            std::cin >> t[i];
            if (!(std::cin)) {
                delete[] lns;
                delete[] t;
                return 1;
            }
        }

        int** result = convert(t, n, lns, rows);

        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < lns[i]; j++) {
                std::cout << result[i][j] << "\n";
            }
        }

        for (size_t i = 0; i < rows; i++) {
            delete[] result[i];
        }
        delete[] result;
        delete[] t;
        delete[] lns;

    } catch (const std::bad_alloc& e) {
        return 1;
    }

    return 0;
}


int** convert(const int* t, size_t n, const size_t* lns, size_t rows){

  int** result = new int*[rows];
  size_t current_index = 0;

  for (size_t i = 0; i < rows; i++) {

    size_t current_length = lns[i];
    result[i] = new int[current_length];

    if (!result[i]) {
      for (size_t k = 0; k < i; k++) {
        delete[] result[k];
      }
      delete[] result;
      throw std::bad_alloc();
    }

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