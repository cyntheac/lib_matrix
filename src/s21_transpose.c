#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int condition = checkOneMatrix(A, NOT_FLAG);
  if (condition == OK) {
    int rows = A->columns;
    int columns = A->rows;
    condition = s21_create_matrix(rows, columns, result);
    if (condition == OK) {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
          result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return condition;
}
