#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int condition = checkTwoMatrix(A, B, EQ_FLAG);
  if (condition == OK) {
    int rows = A->rows;
    int colums = A->columns;
    s21_create_matrix(rows, colums, result);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < colums; j++)
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return condition;
}
