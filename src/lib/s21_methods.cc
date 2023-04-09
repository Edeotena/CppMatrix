#include <new>
#include <stdexcept>

#include "s21_matrix_oop.h"

namespace S21Matrix {
S21Matrix::~S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  if (matrix_ == nullptr) {
    return;
  }

  delete[] matrix_;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  try {
    S21Allocate();
  } catch (const std::out_of_range& exp) {
    throw;
  }
  std::fill(matrix_, matrix_ + rows_ * cols_, 0);
}

S21Matrix::S21Matrix() try : S21Matrix(kDefaultRows, kDefaultCols) {
} catch (const std::out_of_range& exp) {
  throw;
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  try {
    S21Allocate();
  } catch (const std::out_of_range& exp) {
    throw;
  }
  std::copy(other.matrix_, other.matrix_ + other.rows_ * other.cols_, matrix_);
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  if (this == &other) {
    throw std::out_of_range("Same object");
  }

  other.cols_ = other.rows_ = 0;
  other.matrix_ = nullptr;
}

}  // namespace S21Matrix