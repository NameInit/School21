#include "./../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal in, float* out) {
  int res = 1;
  if (out) {
    double tmp = 0;
    int exp = 0;
    for (int i = 0; i < 96; i++) {
      if ((in.bits[i / 32] & (1 << i % 32)) != 0) tmp += pow(2, i);
    }
    if ((exp = s21_get_scale(in)) > 0) {
      for (int i = exp; i > 0; i--, tmp /= 10.0);
    }
    *out = (float)tmp;
    if (s21_get_sign(in)) {
      *out *= -1;
    }
    res = 0;
  }
  return res;
}
