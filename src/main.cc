#include <iostream>

#include "s21_matrix_oop.h"

int main() {
  S21Matrix::S21Matrix a(3, 4), b, c(a);
  a.S21Print();
  b.S21Print();
  c.S21Print();
  S21Matrix::S21Matrix o(std::move(a));
  o.S21Print();
  a.S21Print();
  //  try {
  //    S21Matrix::S21Matrix k(-1, -1);
  //  } catch (const std::out_of_range& ex) {
  //    std::cout << ex.what();
  //  }
  try {
    a.S21SetRows(1);
    a.S21SetCols(1);
    a.S21Print();
  } catch (const std::out_of_range& ex) {
    std::cout << ex.what();
  }
}