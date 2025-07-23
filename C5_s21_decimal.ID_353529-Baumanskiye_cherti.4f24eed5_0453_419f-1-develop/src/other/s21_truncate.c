#include "./../s21_decimal.h"

int s21_truncate(s21_decimal val, s21_decimal *res) {
  s21_copy(s21_reset(res), s21_get_scale(val)
                               ? *s21_decr_scale(&val, s21_get_scale(val))
                               : val);
  return 0;
}
