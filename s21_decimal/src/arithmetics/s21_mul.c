#include "./../s21_decimal.h"

int s21_mul(s21_decimal val1, s21_decimal val2, s21_decimal *res) {
  res->bits[0] = res->bits[1] = res->bits[2] = res->bits[3] = 0;
  int temp_res = 0;
  int sign_result = 5;
  if (s21_get_sign(val1) != s21_get_sign(val2)) {
    sign_result = 1;
  } else {
    sign_result = 0;
  }
  s21_set_sign(&val1, 0);
  s21_set_sign(&val2, 0);
  int bit1 = s21_get_last_bit(val1);

  for (int i = 0; i <= bit1; i++) {
    s21_decimal tmp_res = {{0, 0, 0, 0}};
    int value_bit_1 = s21_get_bit(val1, i);

    if (value_bit_1) {
      tmp_res = val2;
      s21_left_shift(&tmp_res, i);
      temp_res = s21_adding_bits(*res, tmp_res, res);
    }
  }
  if (temp_res) {
    while (s21_get_scale(val1) > 0 || s21_get_scale(val2) > 0) {
      s21_decimal *value_1_1, *value_2_1;
      if (s21_get_last_bit(val1) > s21_get_last_bit(val2) &&
          s21_get_scale(val1) > 0) {
        value_1_1 = &val1;
        value_2_1 = &val2;
      } else if (s21_get_last_bit(val2) > s21_get_last_bit(val1) &&
                 s21_get_scale(val2) > 0) {
        value_1_1 = &val2;
        value_2_1 = &val1;
      } else {
        break;
      }
      int scale2 = s21_get_scale(*value_1_1);
      s21_decr_scale(value_1_1, 1);
      s21_set_scale(value_1_1, --scale2);
      return s21_mul(*value_1_1, *value_2_1, res);
    }
  }

  int scale = s21_get_scale(val1) + s21_get_scale(val2);
  s21_set_scale(res, scale);
  s21_set_sign(res, sign_result);
  if (temp_res && sign_result) temp_res = 2;
  return temp_res;
}
