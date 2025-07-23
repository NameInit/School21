#include "./../s21_decimal.h"

int s21_div(s21_decimal val1, s21_decimal val2, s21_decimal *res) {
  res->bits[0] = res->bits[1] = res->bits[2] = res->bits[3] = 0;

  int status = 0;
  int sign = s21_get_sign(val1) ^ s21_get_sign(val2);

  s21_set_sign(&val1, 0);
  s21_set_sign(&val2, 0);

  if (val2.bits[0] == 0 && val2.bits[1] == 0 && val2.bits[2] == 0) {
    status = 3;
  } else {
    s21_decimal remainder = {0};
    int scale = 0;

    for (int i = s21_get_last_bit(val1); i >= 0; i--) {
      s21_left_shift(&remainder, 1);
      if (s21_get_bit(val1, i)) {
        s21_set_bit(&remainder, 0, 1);
      }

      s21_left_shift(res, 1);

      if (s21_is_greater_or_equal(remainder, val2)) {
        s21_sub(remainder, val2, &remainder);
        s21_set_bit(res, 0, 1);
      }
    }

    s21_set_scale(res, scale);
    s21_set_sign(res, sign);
  }

  return status;
}