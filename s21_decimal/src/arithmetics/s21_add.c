#include "./../s21_decimal.h"

int s21_add(s21_decimal val1, s21_decimal val2, s21_decimal* res) {
  int status = 0, valueSign_1 = s21_get_sign(val1),
      valueSign_2 = s21_get_sign(val2);
  for (int x = 0; x < 4; x += 1) res->bits[x] = 0;
  if (valueSign_1 == valueSign_2) {
    s21_set_eq_scale(&val1, &val2);
    if (s21_adding_bits(val1, val2, res)) {
      if ((!s21_get_scale(val1) || !s21_get_scale(val2)) && !valueSign_1) {
        status = 1;
      } else if ((!s21_get_scale(val1) || !s21_get_scale(val2)) &&
                 valueSign_1) {
        status = 2;
      } else if (s21_get_scale(val1) > 0 && s21_get_scale(val2) > 0) {
        s21_set_scale(s21_decr_scale(&val1, 1), s21_get_scale(val1) - 1);
        s21_set_scale(s21_decr_scale(&val2, 1), s21_get_scale(val2) - 1);
        status = s21_add(val1, val2, res);
      }
    } else {
      s21_set_scale(s21_set_sign(res, valueSign_1), s21_get_scale(val1));
    }
  } else if (valueSign_1 && !valueSign_2) {
    status = s21_sub(val2, *s21_set_sign(&val1, 0), res);
  } else if (!valueSign_1 && valueSign_2) {
    status = s21_sub(val1, *s21_set_sign(&val2, 0), res);
  }
  return status;
}
