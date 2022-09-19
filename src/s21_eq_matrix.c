#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int condition = FAILURE;
  if (checkTwoMatrix(A, B, EQ_FLAG) == OK) {
    int rows = A->rows;
    int colums = A->columns;
    int check = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < colums; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > FRACTIONAL_PART) {
          check++;
          break;
        }
      }
      if (check) break;
    }
    if (!check) condition = SUCCESS;
  }
  return condition;
}
