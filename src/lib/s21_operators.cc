#include <algorithm>

#include "s21_matrix_oop.h"

namespace S21Matrix {
S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  delete[] matrix_;

  cols_ = other.cols_;
  rows_ = other.rows_;
  S21Allocate();

  std::copy(other.matrix_, other.matrix_ + other.rows_ * other.cols_, matrix_);

  return *this;
}
}  // namespace S21Matrix