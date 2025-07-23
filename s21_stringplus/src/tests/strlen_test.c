#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strlen1) {
  char str[] = "strlen";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen2) {
  char str[] = "f";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen3) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen4) {
  char str[] = "This is a test string";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen5) {
  char str[] = "\0";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen6) {
  char str[] = "\0\0\0";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen7) {
  char str[] = "09875-fdaas";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen8) {
  char str[] = "\0school 21";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen9) {
  char str[] = "GW-09\0";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen10) {
  char str[] = "?()[{}]";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *strlen_test(void) {
  Suite *s = suite_create("\033[45m S21_STRLEN \033[0m");
  TCase *tc = tcase_create("strlen_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strlen1);
  tcase_add_test(tc, strlen2);
  tcase_add_test(tc, strlen3);
  tcase_add_test(tc, strlen4);
  tcase_add_test(tc, strlen5);
  tcase_add_test(tc, strlen6);
  tcase_add_test(tc, strlen7);
  tcase_add_test(tc, strlen8);
  tcase_add_test(tc, strlen9);
  tcase_add_test(tc, strlen10);

  suite_add_tcase(s, tc);
  return s;
}
