#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int my_res = 0;
  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
  } else {
    my_res = 1;
  }
  return my_res;
}
