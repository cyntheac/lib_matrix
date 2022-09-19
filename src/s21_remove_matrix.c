#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A) {
    int rows = A->rows;
    for (int i = 0; i < rows; i++) free(A->matrix[i]);
    free(A->matrix);
  }
}
