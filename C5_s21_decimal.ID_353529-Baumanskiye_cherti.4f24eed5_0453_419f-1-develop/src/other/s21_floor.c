#include "./../s21_decimal.h"

int s21_floor(s21_decimal val, s21_decimal* res) {
  if (!s21_truncate(val, s21_reset(res)) && s21_get_sign(val) &&
      !s21_is_equal(*res, val))
    s21_sub(*res, ((s21_decimal){{1, 0, 0, 0}}), res);
  return 0;
}
