#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int condition = ERROR_1;
  if (rows > 0 && columns > 0) {
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      result->columns = columns;
      result->rows = rows;
      int check = 0;
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          check++;
          s21_remove_matrix(result);
          break;
        }
      }
      if (!check) condition = OK;
    }
  }
  return condition;
}
