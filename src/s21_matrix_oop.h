#ifndef S21_MATRIX_OOP_H_  // TODO: CHECK CORRECT
#define S21_MATRIX_OOP_H_

enum DefaultDimensionsValues { kDefaultRows = 3, kDefaultCols = 5 };

namespace S21Matrix {

class S21Matrix {
 private:
  // Attributes
  int rows_, cols_;
  double* matrix_;

 public:
  // Constructors and destructors
  S21Matrix(int rows, int cols);
  S21Matrix();
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // Matrix operations
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);
  bool operator==(const S21Matrix& other);
  bool operator!=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(double other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(double num);
  S21Matrix operator*=(const S21Matrix& other);
  double& operator()(int i, int j);
  const double& operator()(int i, int j) const;

 public:
  // helpers
  void S21Allocate();
  void S21Print();
};
}  // namespace S21Matrix

#endif  // S21_MATRIX_OOP_H_
