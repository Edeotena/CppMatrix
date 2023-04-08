#include <iostream>
#include <stdexcept>

#include "s21_matrix_oop.h"

namespace S21Matrix {
void S21Matrix::S21Allocate() {
  if (rows_ < 1 || cols_ < 1) {
    rows_ = cols_ = 0;
    throw std::out_of_range("Dimensions must be >= 1");
  }

  try {
    matrix_ = new double[rows_ * cols_];
  } catch (const std::bad_alloc& exc) {
    rows_ = cols_ = 0;
    throw std::out_of_range("Allocation error");
  }
}

void S21Matrix::S21Print() {
  std::cout << "Matrix(" << rows_ << ", " << cols_ << "):\n";
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      std::cout << matrix_[i * cols_ + j] << (j == cols_ - 1 ? '\n' : ' ');
    }
  }
  std::cout << '\n';
}

}  // namespace S21Matrix