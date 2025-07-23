#include <math.h>
#include <string.h>

#include "./../s21_decimal.h"

int s21_from_float_to_decimal(float in, s21_decimal *out) {
  int res = 1, exp = s21_float_exp(&in);
  if (out && in != 0 && !isinf(in)) {
    out->bits[0] = 0;
    out->bits[1] = 0;
    out->bits[2] = 0;
    out->bits[3] = 0;
    int sign = 0;
    if (in < 0) {
      in *= -1;
      sign = 1;
    }
    double tmp = (double)in;
    int scale = 0;
    while (scale < 28 && (int)tmp / (int)pow(2, 21) == 0) {
      tmp *= 10;
      scale++;
    }

    if (scale <= 28 && (exp > -94 && exp < 96)) {
      for (; fmod(tmp, 10) == 0 && scale > 0; scale--, tmp /= 10) {
      }

      float float_value = (float)tmp;

      int int_representation;
      memcpy(&int_representation, &float_value, sizeof(float));

      exp = s21_float_exp(&float_value);
      s21_set_bit(out, exp, 1);

      for (int i = exp - 1, j = 22; j >= 0; i--, j--) {
        if (int_representation & (1 << j)) {
          s21_set_bit(out, i, 1);
        }
      }

      s21_set_sign(out, sign);
      s21_set_scale(out, scale);
      res = 0;
    }
  }
  return res;
}