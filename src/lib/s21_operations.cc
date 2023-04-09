#include "s21_matrix_oop.h"

namespace S21Matrix {
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
  S21Matrix res;
  return res;
}

double S21Matrix::Determinant() const {
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
  S21Matrix res;
  return res;
}
}  // namespace S21Matrix