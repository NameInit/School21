#ifndef SRC_S21_OTHER_H_
#define SRC_S21_OTHER_H_

int s21_floor(s21_decimal val, s21_decimal* res);
int s21_negate(s21_decimal val, s21_decimal* res);
int s21_truncate(s21_decimal val, s21_decimal* res);
int s21_round(s21_decimal val, s21_decimal* res);
s21_decimal* s21_copy(s21_decimal* out, s21_decimal in);
s21_decimal* s21_reset(s21_decimal* val);

#endif
