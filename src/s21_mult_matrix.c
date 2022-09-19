#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int condition = checkTwoMatrix(A, B, MULT_MATRIX_FLAG);
  if (condition == OK) {
    int rowsA = A->rows;
    int rowsB = B->rows;
    int columnsB = B->columns;
    condition = s21_create_matrix(rowsA, columnsB, result);
    if (condition == OK) {
      for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
          result->matrix[i][j] = 0;
          for (int k = 0; k < rowsB; k++)
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return condition;
}
