#include "./../s21_decimal.h"

int s21_mod(s21_decimal val1, s21_decimal val2, s21_decimal* res) {
  res->bits[0] = res->bits[1] = res->bits[2] = res->bits[3] = 0;
  int temp_res = 5;
  if (s21_is_equal(val1, val2)) {
    res->bits[0] = 0;
    res->bits[1] = 0;
    res->bits[2] = 0;
    res->bits[3] = 0;
    temp_res = 0;
  } else if (s21_is_less(val1, val2) && !s21_is_null(val1) &&
             !s21_is_null(val2)) {
    res->bits[0] = val1.bits[0];
    res->bits[1] = val1.bits[1];
    res->bits[2] = val1.bits[2];
    res->bits[3] = val1.bits[3];
    temp_res = 0;
  } else {
    s21_decimal mod = {0};
    s21_set_sign(&val1, 0);
    s21_set_sign(&val1, 0);
    temp_res = s21_div(val1, val2, &mod);
    if (!temp_res) {
      s21_truncate(mod, &mod);
      s21_mul(mod, val2, &mod);
      s21_sub(val1, mod, res);
    }
  }
  return temp_res;
}
