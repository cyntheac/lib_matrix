#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int condition = checkOneMatrix(A, COL_ROW_FLAG);
  if (condition == OK) {
    int size = A->rows;
    s21_create_matrix(size, size, result);
    double det = findDeterminant(A);
    if (det > 0)
      det = -1;
    else
      det = 1;
    int minorSize = size - 1;
    matrix_t minor;
    s21_create_matrix(minorSize, minorSize, &minor);
    for (int j = 0; j < size; j++) {
      for (int i = 0; i < size; i++) {
        getMinor(A, &minor, j, i, size);
        if ((i + j) % 2 == 0)
          result->matrix[j][i] = det * findDeterminant(&minor);
        else
          result->matrix[j][i] = -det * findDeterminant(&minor);
      }
    }
    s21_remove_matrix(&minor);
  }
  return condition;
}
