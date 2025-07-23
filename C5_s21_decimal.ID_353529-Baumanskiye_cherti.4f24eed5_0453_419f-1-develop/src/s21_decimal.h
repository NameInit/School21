#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdio.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

#define S21_MAX_UINT 4294967295

#include "./header/s21_arithmetics.h"
#include "./header/s21_comparison.h"
#include "./header/s21_convertors.h"
#include "./header/s21_other.h"
#include "./header/s21_support.h"

#endif