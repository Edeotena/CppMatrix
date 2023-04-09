#include <algorithm>
#include <new>
#include <stdexcept>

#include "s21_matrix_oop.h"

namespace S21Matrix {
S21Matrix::~S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  delete[] matrix_;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols)
    : rows_(rows), cols_(cols), matrix_(nullptr) {
  S21Allocate();

  std::fill(matrix_, matrix_ + rows_ * cols_, 0);
}

S21Matrix::S21Matrix() : S21Matrix(kDefaultRows, kDefaultCols) {}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(0), cols_(0), matrix_(nullptr) {
  *this = other;
}

S21Matrix::S21Matrix(S21Matrix&& other) : rows_(0), cols_(0), matrix_(nullptr) {
  if (this == &other) {
    throw std::out_of_range("Same object");
  }

  matrix_ = other.matrix_;
  rows_ = other.rows_;
  cols_ = other.cols_;

  other.cols_ = other.rows_ = 0;
  other.matrix_ = nullptr;
}

}  // namespace S21Matrix