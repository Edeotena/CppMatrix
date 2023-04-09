#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

namespace S21Matrix {

class S21Matrix {
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
  void AllocateMatrix();
  S21Matrix LessMatrix(int row_to_skip, int col_to_skip) const;

 public:
  // Additional functions
  void PrintMatrix() const;
  int GetRows() const;
  int GetCols() const;
  void SetRows(const int rows);
  void SetCols(const int cols);

private:
    // Attributes
    int rows_, cols_;
    double* matrix_;
};

constexpr double equality_epsilon = 1e-07;
enum DefaultDimensionsValues { kDefaultRows = 3, kDefaultCols = 5 };
}  // namespace S21Matrix

#endif  // SRC_S21_MATRIX_OOP_H_
