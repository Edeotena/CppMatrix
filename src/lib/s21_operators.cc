#include <algorithm>
#include <stdexcept>

#include "s21_matrix_oop.h"

namespace S21Matrix {

double& S21Matrix::operator()(int i, int j) const {
  if (i >= rows_ || j >= cols_) {
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
  S21Allocate();

  std::copy(other.matrix_, other.matrix_ + other.rows_ * other.cols_, matrix_);

  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (this == &other) {
    return *this;
  }

  delete[] matrix_;

  cols_ = other.cols_;
  rows_ = other.rows_;
  matrix_ = other.matrix_;

  other.cols_ = other.rows_ = 0;
  other.matrix_ = nullptr;

  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }

  if (!std::equal(matrix_, matrix_ + cols_ * rows_, other.matrix_,
                  other.matrix_ + other.cols_ * other.rows_)) {
    return false;
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

  S21Matrix result(*this);

  long size = cols_ * rows_;
  for (int i = 0; i < size; ++i) {
    result.matrix_[i] = matrix_[i] + other.matrix_[i];
  }

  return result;
}
S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("Matrix's dimensions must be equal");
  }

  S21Matrix result(*this);

  long size = cols_ * rows_;
  for (int i = 0; i < size; ++i) {
    result.matrix_[i] = matrix_[i] - other.matrix_[i];
  }

  return result;
}

S21Matrix S21Matrix::operator*(const double other) const {
  S21Matrix result(*this);

  long size = cols_ * rows_;
  for (int i = 0; i < size; ++i) {
    result.matrix_[i] = matrix_[i] * other;
  }

  return result;
}
S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  if (cols_ != other.rows_) {
    throw std::out_of_range(
        "The number of columns of the first matrix does not equal the number "
        "of rows of the second matrix");
  }

  S21Matrix result(rows_, other.cols_);

  for (int i = 0; i < result.rows_; ++i) {
    for (int j = 0; j < result.cols_; ++j) {
      double val = 0;
      for (int k = 0; k < cols_; ++k) {
        val += (*this)(i, k) * other(k, j);
      }
      result(i, j) = val;
    }
  }

  return result;
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

}  // namespace S21Matrix