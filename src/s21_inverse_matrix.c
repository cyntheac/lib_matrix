#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int condition = checkOneMatrix(A, COL_ROW_FLAG);
  if (condition == OK) {
    int size = A->rows;
    double det;
    s21_determinant(A, &det);
    if (det != 0) {
      matrix_t demoMatrixOne;
      s21_create_matrix(size, size, &demoMatrixOne);
      s21_calc_complements(A, &demoMatrixOne);
      matrix_t demoMatrixTwo;
      s21_create_matrix(size, size, &demoMatrixTwo);
      s21_transpose(&demoMatrixOne, &demoMatrixTwo);

      s21_mult_number(&demoMatrixTwo, (double)-1 / det, result);
      s21_remove_matrix(&demoMatrixOne);
      s21_remove_matrix(&demoMatrixTwo);
    } else {
      condition = ERROR_2;
    }
  }
  return condition;
}
