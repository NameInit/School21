#include "./../s21_decimal.h"

s21_decimal* s21_reset(s21_decimal* val) {
  for (int x = 0; x < 4; x += 1) val->bits[x] = 0;
  return val;
}
