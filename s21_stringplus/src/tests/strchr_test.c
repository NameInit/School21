#include "string_suite.h"

START_TEST(strchr1) {
  char str_src[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strchr(str_src, ch), s21_strchr(str_src, ch));
}
END_TEST

START_TEST(strchr2) {
  char str_src[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(str_src, ch), s21_strchr(str_src, ch));
}
END_TEST

START_TEST(strchr3) {
  char str_src[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strchr(str_src, ch), s21_strchr(str_src, ch));
}
END_TEST

START_TEST(strchr4) {
  char str_src[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strchr(str_src, ch), s21_strchr(str_src, ch));
}
END_TEST

START_TEST(strchr5) {
  char str_src[] = "mouse!";
  int ch = 'u';
  ck_assert_pstr_eq(strchr(str_src, ch), s21_strchr(str_src, ch));
}
END_TEST

START_TEST(strchr6) {
  char str_src[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strchr(str_src, ch), s21_strchr(str_src, ch));
}
END_TEST

START_TEST(strchr7) {
  char str_src[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strchr(str_src, ch), s21_strchr(str_src, ch));
}
END_TEST

START_TEST(strchr8) {
  char str_src[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strchr(str_src, ch), s21_strchr(str_src, ch));
}
END_TEST

Suite *strchr_test(void) {
  Suite *str_src = suite_create("\033[45m S21_STRCHR \033[0m");
  TCase *tc = tcase_create("strchr_tc");

  suite_add_tcase(str_src, tc);
  tcase_add_test(tc, strchr1);
  tcase_add_test(tc, strchr2);
  tcase_add_test(tc, strchr3);
  tcase_add_test(tc, strchr4);
  tcase_add_test(tc, strchr5);
  tcase_add_test(tc, strchr6);
  tcase_add_test(tc, strchr7);
  tcase_add_test(tc, strchr8);

  suite_add_tcase(str_src, tc);
  return str_src;
}