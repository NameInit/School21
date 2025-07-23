#include "./../s21_decimal.h"

int s21_sub(s21_decimal val1, s21_decimal val2, s21_decimal* temp_res) {
  int status = 0, valueSign_1 = s21_get_sign(val1),
      valueSign_2 = s21_get_sign(val2);
  for (int x = 0; x < 4; x += 1) temp_res->bits[x] = 0;

  if (valueSign_1 != valueSign_2) {
    status =
        s21_add(*s21_set_sign(&val1, 0), *s21_set_sign(&val2, 0), temp_res);
    status = status ? (valueSign_1 ? 2 : 1) : status;
    s21_set_sign(temp_res, valueSign_1);
  } else {
    s21_set_eq_scale(&val1, &val2);
    if (!s21_is_equal(val1, val2)) {
      s21_set_sign(&val1, 0);
      s21_set_sign(&val2, 0);
      if (s21_is_less(val1, val2)) {
        status = s21_add(*s21_convert(&val1), val2, temp_res);
        s21_set_sign(temp_res, !valueSign_2);
      } else {
        status = s21_add(*s21_convert(&val2), val1, temp_res);
        s21_set_sign(temp_res, valueSign_1);
      }
    }
  }
  return status;
}
