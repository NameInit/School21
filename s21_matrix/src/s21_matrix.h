#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define ERROR 1
#define UNDEFINED_BEHAVIOR 2
#define MEMORY_ERROR 3

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int s21_error_matrix(matrix_t *A);
double s21_get_det(matrix_t *A, int size);
int s21_error_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sub_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result, int znak);
void s21_calc_minor(double **A, double **aux, int skipRow, int skipCol,
                    int size);

#endif
