#include <iostream>

#include "s21_matrix_oop.h"

namespace s21_matrix {
void S21Matrix::PrintMatrix() const {
  std::cout << "Matrix(" << rows_ << ", " << cols_ << "):\n";
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      std::cout << matrix_[i * cols_ + j] << (j == cols_ - 1 ? '\n' : ' ');
    }
  }
  std::cout << '\n';
}

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(const int rows) {
  S21Matrix res(rows, cols_);

  for (int i = 0; i < cols_; ++i) {
    for (int j = 0; j < std::min(rows, rows_); ++j) {
      res.matrix_[i + j * rows] = matrix_[i + j * rows_];
    }
  }

  *this = res;
}

void S21Matrix::SetCols(const int cols) {
  S21Matrix res(rows_, cols);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < std::min(cols, cols_); ++j) {
      res.matrix_[i * cols + j] = matrix_[i * cols_ + j];
    }
  }

  *this = res;
}

}  // namespace s21_matrix
