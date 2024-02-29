#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int ret_error = 0;
  *result = 0.0;
  if (A->matrix == NULL || A == NULL)
    ret_error = MATERROR;
  else if (A->rows == A->columns && A->rows > 0) {
    *result = s21_reqursive_det(A);
  } else
    ret_error = CALCERROR;

  return ret_error;
}

void s21_pre_minor(matrix_t *A, int row, int column, matrix_t *result) {
  s21_create_matrix(A->rows - 1, A->columns - 1, result);

  for (int i = 0, new_row = 0; i < A->rows; i++) {
    if (i != row) {
      for (int j = 0, new_column = 0; j < A->columns; j++) {
        if (j != column) {
          result->matrix[new_row][new_column] = A->matrix[i][j];
          new_column++;
        }
      }
      new_row++;
    }
  }
}

double s21_reqursive_det(matrix_t *A) {
  double result = 0.0;

  if (A->rows == 1) {
    result = A->matrix[0][0];
  } else if (A->rows == 2) {
    result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    int k = 1;
    for (int j = 0; j < A->columns; j++) {
      matrix_t new_matrix;
      s21_pre_minor(A, 0, j, &new_matrix);
      result += k * A->matrix[0][j] * s21_reqursive_det(&new_matrix);
      k = -k;
      s21_remove_matrix(&new_matrix);
    }
  }
  return result;
}