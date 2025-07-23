#ifndef SRC_S21_CONVERTORS_H_
#define SRC_S21_CONVERTORS_H_

int s21_from_int_to_decimal(int in, s21_decimal* out);
int s21_from_decimal_to_int(s21_decimal in, int* out);
int s21_from_float_to_decimal(float in, s21_decimal* out);
int s21_from_decimal_to_float(s21_decimal in, float* out);

#endif
