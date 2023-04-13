// Copyright 2023 guinicyb

#include <stdexcept>

#include "../s21_matrix_oop.h"

namespace s21_matrix {
bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  return *this == other;
}

void S21Matrix::SumMatrix(const S21Matrix& other) { *this += other; }

void S21Matrix::SubMatrix(const S21Matrix& other) { *this -= other; }

void S21Matrix::MulNumber(const double num) { *this *= num; }

void S21Matrix::MulMatrix(const S21Matrix& other) { *this *= other; }

S21Matrix S21Matrix::Transpose() const {
  S21Matrix res(cols_, rows_);

  for (int i = 0; i < cols_; ++i) {
    for (int j = 0; j < rows_; ++j) {
      res(i, j) = (*this)(j, i);
    }
  }

  return res;
}

S21Matrix S21Matrix::CalcComplements() const {
  S21Matrix res(rows_, cols_);

  for (int i = 0; i < res.rows_; ++i) {
    for (int j = 0; j < res.cols_; ++j) {
      S21Matrix small_matrix = (*this).LessMatrix(i, j);

      res(i, j) = small_matrix.Determinant() * ((i + j) % 2 == 0 ? 1 : -1);
    }
  }

  return res;
}

double S21Matrix::Determinant() const {
  if (rows_ != cols_) {
    throw std::out_of_range("Matrix should have rows == cols");
  }

  if (rows_ == 1) {
    return (*this)(0, 0);
  } else if (rows_ == 2) {
    return (*this)(0, 0) * (*this)(1, 1) - (*this)(1, 0) * (*this)(0, 1);
  }

  S21Matrix cp(*this);
  for (int k = 0; k < cp.cols_ - 1; k++) {
    for (int i = k + 1; i < cp.cols_; i++) {
      double tmp = -cp(i, k) / cp(k, k);
      for (int j = 0; j < cp.cols_; j++) {
        cp(i, j) += cp(k, j) * tmp;
      }
    }
  }

  double d = 1;
  for (int i = 0; i < cp.cols_; i++) {
    d *= cp(i, i);
  }

  return d;
}

S21Matrix S21Matrix::InverseMatrix() const {
  double d = Determinant();
  if (std::abs(d) < equality_epsilon) {
    throw std::out_of_range("Zero determinant (zero division)");
  }

  S21Matrix result = CalcComplements().Transpose() * (1.0 / d);
  return result;
}
}  // namespace s21_matrix
