#include "./../s21_decimal.h"

int s21_negate(s21_decimal val, s21_decimal* res) {
  s21_copy(s21_reset(res),
           s21_get_sign(val) ? *s21_set_sign(&val, 0) : *s21_set_sign(&val, 1));
  return 0;
}
