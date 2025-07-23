#include "./../s21_decimal.h"

int s21_is_equal(s21_decimal val1, s21_decimal val2) {
  int res = 1;
  if (s21_get_sign(val1) == s21_get_sign(val2)) {
    s21_set_eq_scale(&val1, &val2);
    for (int i = 95; i >= 0; i--) {
      if (s21_get_bit(val1, i) != s21_get_bit(val2, i)) {
        res = 0;
        break;
      }
    }
  } else if (!(s21_is_null(val1) && s21_is_null(val2))) {
    res = 0;
  }
  return res;
}
