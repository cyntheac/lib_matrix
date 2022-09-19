#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int condition = checkOneMatrix(A, NOT_FLAG);
  if (condition == OK) {
    int rows = A->rows;
    int colums = A->columns;
    s21_create_matrix(rows, colums, result);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < colums; j++)
        result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return condition;
}
