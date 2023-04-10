#include <algorithm>
#include <new>

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
  AllocateMatrix();
}

S21Matrix::S21Matrix() : S21Matrix(0, 0) {}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(0), cols_(0), matrix_(nullptr) {
  *this = other;
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(0), cols_(0), matrix_(nullptr) {
  *this = std::move(other);
}

}  // namespace S21Matrix
