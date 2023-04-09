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
  // Constructors and destructors (methods)
  S21Matrix(int rows, int cols);
  S21Matrix();
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  // Matrix operations
  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  // Matrix operators
  S21Matrix& operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other) const;
  bool operator!=(const S21Matrix& other) const;
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const double other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(const double num);
  S21Matrix operator*=(const S21Matrix& other);
  double& operator()(int i, int j) const;

 private:
  // Helpers
  void S21Allocate();
  S21Matrix S21LessMatrix(int row_to_skip, int col_to_skip) const;

 public:
  // Additional functions
  void S21Print() const;
  int S21GetRows() const;
  int S21GetCols() const;
  void S21SetRows(const int rows);
  void S21SetCols(const int cols);
};

constexpr double equality_epsilon = 1e-07;
}  // namespace S21Matrix

#endif  // S21_MATRIX_OOP_H_
