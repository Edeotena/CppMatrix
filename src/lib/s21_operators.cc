// Copyright 2023 guinicyb

#include <algorithm>
#include <cstdint>
#include <stdexcept>

#include "../s21_matrix_oop.h"

namespace s21_matrix {

double& S21Matrix::operator()(int i, int j) const {
  if (i >= rows_ || j >= cols_ || i < 0 || j < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[i * cols_ + j];
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this == &other) {
    return *this;
  }

  delete[] matrix_;

  cols_ = other.cols_;
  rows_ = other.rows_;
  AllocateMatrix();

  std::copy(other.matrix_, other.matrix_ + other.rows_ * other.cols_, matrix_);

  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (other == *this) {
    return *this;
  }

  delete[] matrix_;
  cols_ = std::exchange(other.cols_, 0);
  rows_ = std::exchange(other.rows_, 0);
  matrix_ = std::exchange(other.matrix_, nullptr);

  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }

  uint16_t size = rows_ * cols_;
  for (int i = 0; i < size; ++i) {
    if (std::abs(matrix_[i] - other.matrix_[i]) > equality_epsilon) {
      return false;
    }
  }

  return true;
}

bool S21Matrix::operator!=(const S21Matrix& other) const {
  return !(*this == other);
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("Matrix's dimensions must be equal");
  }

  S21Matrix res(*this);

  uint16_t size = cols_ * rows_;
  for (int i = 0; i < size; ++i) {
    res.matrix_[i] = matrix_[i] + other.matrix_[i];
  }

  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("Matrix's dimensions must be equal");
  }

  S21Matrix res(*this);

  uint16_t size = cols_ * rows_;
  for (int i = 0; i < size; ++i) {
    res.matrix_[i] = matrix_[i] - other.matrix_[i];
  }

  return res;
}

S21Matrix S21Matrix::operator*(const double other) const {
  S21Matrix res(*this);

  uint16_t size = cols_ * rows_;
  for (int i = 0; i < size; ++i) {
    res.matrix_[i] = matrix_[i] * other;
  }

  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  if (cols_ != other.rows_) {
    throw std::out_of_range(
        "The number of columns of the first matrix does not equal the number "
        "of rows of the second matrix");
  }

  S21Matrix res(rows_, other.cols_);

  for (int i = 0; i < res.rows_; ++i) {
    for (int j = 0; j < res.cols_; ++j) {
      double val = 0;
      for (int k = 0; k < cols_; ++k) {
        val += (*this)(i, k) * other(k, j);
      }
      res(i, j) = val;
    }
  }

  return res;
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  *this = *this + other;
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  *this = *this - other;
  return *this;
}

S21Matrix S21Matrix::operator*=(const double num) {
  *this = *this * num;
  return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
  *this = *this * other;
  return *this;
}

}  // namespace s21_matrix
