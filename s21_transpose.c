#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = 0;
  if (A->columns == 0 || A->rows == 0 || A->matrix == NULL) {
    flag = MATERROR;
  } else {
    s21_create_matrix(A->columns, A->rows, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
    flag = OK;
  }
  return flag;
}