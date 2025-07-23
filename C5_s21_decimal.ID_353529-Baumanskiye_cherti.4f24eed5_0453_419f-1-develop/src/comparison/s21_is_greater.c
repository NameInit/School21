#include "./../s21_decimal.h"

int s21_is_greater(s21_decimal val1, s21_decimal val2) {
  int res = 0;
  int sign_a = s21_get_sign(val1), sign_b = s21_get_sign(val2);
  if (!(s21_is_null(val1) && s21_is_null(val2))) {
    if (sign_a != sign_b) {
      if (sign_a == 0) {
        res = 1;
      } else {
        res = 0;
      }
    } else {
      s21_set_eq_scale(&val1, &val2);
      for (int i = 95; i >= 0; i--) {
        int bit_a = s21_get_bit(val1, i), bit_b = s21_get_bit(val2, i);
        if (bit_a != bit_b) {
          if (bit_a != 0) {
            res = (sign_a == 0) ? 1 : 0;
            break;
          } else {
            res = (sign_a == 0) ? 0 : 1;
            break;
          }
        }
      }
    }
  }
  return res;
}
