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
}