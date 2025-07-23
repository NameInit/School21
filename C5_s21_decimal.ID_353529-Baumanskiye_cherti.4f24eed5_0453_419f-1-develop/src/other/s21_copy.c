#include "./../s21_decimal.h"

s21_decimal* s21_copy(s21_decimal* out, s21_decimal in) {
  for (int x = 0; x < 4; x += 1) out->bits[x] = in.bits[x];
  return out;
}
