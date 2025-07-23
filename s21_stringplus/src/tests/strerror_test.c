#include "string_suite.h"

START_TEST(strerror_1) {
  for (int i = 0; i < 40; i++) {
    char *s21_error = s21_strerror(i);
    char *std_error = strerror(i);
    ck_assert_str_eq(s21_error, std_error);
  }
}
END_TEST

START_TEST(strerror_2) {
  int zero_error = 0;
  char *s21_error = s21_strerror(zero_error);
  char *std_error = strerror(zero_error);
  ck_assert_str_eq(s21_error, std_error);
}
END_TEST

Suite *strerror_test(void) {
  Suite *s = suite_create("\033[45m S21_STRERROR \033[0m");
  TCase *tc = tcase_create("strerror_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);

  suite_add_tcase(s, tc);
  return s;
}