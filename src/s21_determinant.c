#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int condition = checkOneMatrix(A, COL_ROW_FLAG);
  if (condition == OK) *result = findDeterminant(A);
  return condition;
}
