#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = 0;
  if (A == NULL || A->matrix == NULL) {
    flag = MATERROR;
  } else if (A->rows != A->columns) {
    flag = CALCERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t new_matrix;
        double result_val = 0.0;

        s21_pre_minor(A, i, j, &new_matrix);
        s21_determinant(&new_matrix, &result_val);
        s21_remove_matrix(&new_matrix);

        if ((i + j) % 2 == 0)
          result->matrix[i][j] = result_val;
        else
          result->matrix[i][j] = -result_val;

        s21_remove_matrix(&new_matrix);
      }
    }
  }
  return flag;
}
