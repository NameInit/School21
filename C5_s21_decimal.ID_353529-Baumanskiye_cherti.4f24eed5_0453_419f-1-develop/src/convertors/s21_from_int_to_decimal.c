#include "./../s21_decimal.h"

int s21_from_int_to_decimal(int in, s21_decimal *out) {
  int res = 1;
  if (out) {
    out->bits[0] = 0;
    out->bits[1] = 0;
    out->bits[2] = 0;
    out->bits[3] = 0;
    if (in < 0) {
      s21_set_sign(out, 1);
      in *= -1;
    }
    out->bits[0] = in;
    res = 0;
  }
  return res;
}
