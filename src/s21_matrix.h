#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define FRACTIONAL_PART 1e-7

enum {
  OK,       // OK
  ERROR_1,  // Ошибка, некорректная матрица
  ERROR_2   // Ошибка вычисления
           // (несовпадающие размеры матриц; матрица, для которой нельзя
           // провести вычисления и т.д.)
};

enum {
  NOT_FLAG,  // Без флага
  EQ_FLAG,   // Флаг для сравнения матриц
  MULT_MATRIX_FLAG,  // Флан для сравнения Сols и Rows разных матриц
  COL_ROW_FLAG  // Флаг для квадратной матрицы
};

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);     // ++
void s21_remove_matrix(matrix_t *A);                                // ++
int s21_eq_matrix(matrix_t *A, matrix_t *B);                        // ++
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);     // ++
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);     // ++
int s21_mult_number(matrix_t *A, double number, matrix_t *result);  // ++
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);    // ++
int s21_transpose(matrix_t *A, matrix_t *result);                   // ++
int s21_calc_complements(matrix_t *A, matrix_t *result);            // ++
int s21_determinant(matrix_t *A, double *result);                   // ++
int s21_inverse_matrix(matrix_t *A, matrix_t *result);              // ++

// DOP
int checkOneMatrix(matrix_t *A, int checkFlag);
int checkTwoMatrix(matrix_t *A, matrix_t *B, int checkFlag);
double findDeterminant(matrix_t *A);
void getMinor(matrix_t *A, matrix_t *minor, int x, int y, int size);

#endif  // SRC_S21_MATRIX_H_
