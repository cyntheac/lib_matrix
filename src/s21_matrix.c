#include "s21_matrix.h"

int checkOneMatrix(matrix_t *A, int checkFlag) {
  int condition = ERROR_1;
  if (A) {
    if (A->rows > 0 && A->columns > 0) {
      switch (checkFlag) {
        case COL_ROW_FLAG:
          if (A->columns == A->rows)
            condition = OK;
          else
            condition = ERROR_2;
          break;
        default:
          condition = OK;  // NOT_FLAG
      }
    }
  }
  return condition;
}

int checkTwoMatrix(matrix_t *A, matrix_t *B, int checkFlag) {
  int condition = ERROR_1;
  if (A && B) {
    if (A->rows > 0 && B->rows > 0 && A->columns > 0 && B->columns > 0) {
      switch (checkFlag) {
        case MULT_MATRIX_FLAG:
          if (A->columns == B->rows)
            condition = OK;
          else
            condition = ERROR_2;
          break;
        case EQ_FLAG:
          if (A->rows == B->rows && A->columns == B->columns)
            condition = OK;
          else
            condition = ERROR_2;
          break;
        default:
          condition = OK;  // NOT_FLAG
      }
    }
  }
  return condition;
}

double findDeterminant(matrix_t *A) {
  int size = A->rows;
  if (size == 1) return A->matrix[0][0];
  double det = 0;
  int minorSize = size - 1;
  matrix_t minor;
  s21_create_matrix(minorSize, minorSize, &minor);
  for (int i = 0; i < size; i++) {
    getMinor(A, &minor, 0, i, size);
    det += pow(-1, i) * A->matrix[0][i] * findDeterminant(&minor);
  }
  s21_remove_matrix(&minor);
  return det;
}

void getMinor(matrix_t *A, matrix_t *minor, int x, int y, int size) {
  int xCount = 0, yCount = 0;
  for (int i = 0; i < size; i++) {
    if (i != x) {
      yCount = 0;
      for (int j = 0; j < size; j++) {
        if (j != y) {
          minor->matrix[xCount][yCount] = A->matrix[i][j];
          yCount++;
        }
      }
      xCount++;
    }
  }
}
