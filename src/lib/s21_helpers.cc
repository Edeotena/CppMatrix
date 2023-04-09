#include <new>
#include <stdexcept>

#include "s21_matrix_oop.h"

namespace S21Matrix {
void S21Matrix::S21Allocate() {
  if (rows_ < 0 || cols_ < 0) {
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

S21Matrix S21Matrix::S21LessMatrix(int row_to_skip, int col_to_skip) const {
  if (row_to_skip < 0 || col_to_skip < 0 || row_to_skip >= rows_ ||
      col_to_skip >= cols_) {
    throw std::out_of_range("Wrong dimensions for less matrix");
  }

  S21Matrix res = S21Matrix(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_ - 1; ++i) {
    for (int j = 0; j < cols_ - 1; ++j) {
      res(i, j) = (*this)(i + (i >= row_to_skip ? 1 : 0),
                          j + (j >= col_to_skip ? 1 : 0));
    }
  }

  return res;
}
}  // namespace S21Matrix