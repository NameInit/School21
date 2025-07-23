#include "./../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal in, int *out) {
  int res = 1;
  if (in.bits[1] == 0 && in.bits[2] == 0) {
    *out = in.bits[0];
    if (s21_get_sign(in)) {
      *out *= -1;
    }
    *out /= (int)pow(10, s21_get_scale(in));
    res = 0;
  }
  return res;
}
