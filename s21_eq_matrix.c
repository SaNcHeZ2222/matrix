#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = FAILURE;
  if (A->matrix != NULL && B->matrix != NULL && A != NULL && B != NULL) {
    if (A->rows == B->rows && A->columns == B->columns) {
      int count = A->rows * A->columns;
      int res = 0;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) < 1e-7) {
            res++;
          }
        }
      }
      if (res == count) {
        flag = SUCCESS;
      }
    }
  }
  return flag;
}