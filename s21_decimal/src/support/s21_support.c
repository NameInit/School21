#include "./../s21_decimal.h"

int s21_get_bit(s21_decimal val, int bit) {
  return !!(val.bits[bit / 32] & (1u << (bit % 32)));
}

int s21_get_last_bit(s21_decimal val) {
  int last_bit = 95;
  for (; (last_bit >= 0) && (!s21_get_bit(val, last_bit));) last_bit -= 1;
  return last_bit;
}

s21_decimal *s21_set_bit(s21_decimal *val, int ind, int bit) {
  if (ind / 32 < 4 && bit)
    val->bits[ind / 32] |= (1u << (ind % 32));
  else if (ind / 32 < 4 && !bit)
    val->bits[ind / 32] &= ~(1u << (ind % 32));
  return val;
}

int s21_adding_bits(s21_decimal val1, s21_decimal val2, s21_decimal *res) {
  int fres = 0, exp = 0;
  for (int i = 0; i < 96; i += 1) {
    int bitValue_1 = s21_get_bit(val1, i), bitValue_2 = s21_get_bit(val2, i);
    if (!bitValue_1 && !bitValue_2)
      exp ? s21_set_bit(res, i, (exp = 0) + 1) : s21_set_bit(res, i, 0);
    else if (bitValue_1 != bitValue_2)
      exp ? s21_set_bit(res, i, (exp = 1) - 1) : s21_set_bit(res, i, 1);
    else
      exp ? s21_set_bit(res, i, (exp = 1)) : s21_set_bit(res, i, (exp = 1) - 1);
    if (i == 95 && exp == 1 && !s21_get_bit(val1, 97) && !s21_get_bit(val2, 97))
      fres = 1;
  }
  return fres;
}

int s21_get_scale(s21_decimal val) {
  int res = (char)(val.bits[3] >> 16);
  return res;
}

s21_decimal *s21_set_scale(s21_decimal *val, int scale) {
  if (scale >= 0 && scale <= 28) {
    int sign = s21_get_sign(*val);
    val->bits[3] &= ~(0xFF << 16);
    val->bits[3] |= scale << 16;
    sign ? s21_set_sign(val, 1) : val;
  }
  return val;
}

s21_decimal *s21_incr_scale(s21_decimal *val, int shift) {
  if (s21_get_scale(*val) + shift < 29) {
    s21_set_scale(val, s21_get_scale(*val) + shift);
    s21_decimal auxValue_1 = *val, auxValue_2 = *val;
    if (s21_adding_bits(*s21_left_shift(&auxValue_1, 1),
                        *s21_left_shift(&auxValue_2, 3), val))
      s21_set_bit(val, 96, 1);
  }
  return val;
}

s21_decimal *s21_decr_scale(s21_decimal *val, int shift) {
  for (int y = 0; y < shift; y += 1) {
    unsigned long long overflow = val->bits[2];
    for (int x = 2; x >= 0; x -= 1) {
      val->bits[x] = overflow / 10;
      overflow =
          (overflow % 10) * (S21_MAX_UINT + 1) + val->bits[x ? x - 1 : x];
    }
  }
  s21_set_scale(val, (s21_get_scale(*val) - shift));
  return val;
}

void s21_set_eq_scale(s21_decimal *val1, s21_decimal *val2) {
  if (s21_get_scale(*val1) != s21_get_scale(*val2)) {
    if (s21_get_scale(*val1) < s21_get_scale(*val2)) {
      s21_set_eq_scale(val2, val1);
    } else {
      int scaleLow = s21_get_scale(*val2), scaleHigh = s21_get_scale(*val1);
      for (; (scaleHigh - scaleLow) && !s21_get_bit(*val2, 96); scaleLow += 1)
        s21_incr_scale(val2, 1);
      for (; scaleHigh - scaleLow; scaleHigh -= 1) {
        s21_decr_scale(val1, scaleHigh - scaleLow);
        s21_set_scale(val1, scaleLow);
      }
    }
  }
}

int s21_get_sign(s21_decimal val) {
  int res = !!(val.bits[3] & (1u << 31));
  return res;
}

s21_decimal *s21_set_sign(s21_decimal *val, int bit) {
  val->bits[3] =
      (bit) ? (val->bits[3] | (1u << 31)) : (val->bits[3] & ~(1u << 31));
  return val;
}

s21_decimal *s21_convert(s21_decimal *val) {
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal add = {{1, 0, 0, 0}};
  for (int x = 0; x < 3; x += 1) val->bits[x] = ~val->bits[x];
  s21_adding_bits(*val, add, &res);
  for (int x = 0; x < 3; x += 1) val->bits[x] = res.bits[x];
  s21_set_bit(val, 97, 1);
  return val;
}

int s21_is_null(s21_decimal val) {
  return !val.bits[0] && !val.bits[1] && !val.bits[2];
}

int s21_float_exp(float *val) {
  return ((*((int *)val) & ~(1u << 31)) >> 23) - 127;
}

s21_decimal *s21_left_shift(s21_decimal *val, int shift) {
  if (!(s21_get_last_bit(*val) + shift > 95)) {
    for (int y = 0; y < shift; y += 1) {
      int bitTransfer_1 = s21_get_bit(*val, 31);
      int bitTransfer_2 = s21_get_bit(*val, 63);
      for (int x = 0; x < 3; x += 1) val->bits[x] <<= 1;
      if (bitTransfer_1) s21_set_bit(val, 32, 1);
      if (bitTransfer_2) s21_set_bit(val, 64, 1);
    }
  }
  return val;
}
