#ifndef SRC_S21_AUXILIARY_H_
#define SRC_S21_AUXILIARY_H_

int s21_get_bit(s21_decimal val, int bit);
int s21_get_last_bit(s21_decimal val);
s21_decimal *s21_set_bit(s21_decimal *val, int bit, int a);
int s21_adding_bits(s21_decimal value_1, s21_decimal value_2, s21_decimal *res);

int s21_get_scale(s21_decimal val);
s21_decimal *s21_set_scale(s21_decimal *d, int scale);
s21_decimal *s21_incr_scale(s21_decimal *val, int shift);
s21_decimal *s21_decr_scale(s21_decimal *val, int shift);
void s21_set_eq_scale(s21_decimal *value_1, s21_decimal *value_2);

int s21_get_sign(s21_decimal val);
s21_decimal *s21_set_sign(s21_decimal *val, int bit);

s21_decimal *s21_convert(s21_decimal *val);
int s21_is_null(s21_decimal val);
int s21_float_exp(float *val);
s21_decimal *s21_left_shift(s21_decimal *val, int shift);

#endif
