#include "./../s21_decimal.h"

int s21_round(s21_decimal val, s21_decimal* res) {
  if (!s21_truncate(val, res) && !s21_is_equal(val, *res)) {
    if (s21_get_sign(val))
      s21_sub(val, ((s21_decimal){{5, 0, 0, 65536}}), &val);
    else
      s21_add(val, ((s21_decimal){{5, 0, 0, 65536}}), &val);
    s21_truncate(val, res);
  }
  return 0;
}
