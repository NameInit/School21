#include "string_suite.h"

START_TEST(test_insert_1) {
  char str_src[30] = "hello, world!";
  char str_ins[] = "hELLO, WORLD!";
  char str_res[] = "hello, hELLO, WORLD!world!";
  s21_size_t num = 7;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_2) {
  char str_src[30] = "";
  char str_ins[] = "";
  char *str_res = S21_NULL;
  s21_size_t num = 7;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_3) {
  char *str_src = S21_NULL;
  char str_ins[] = "";
  char *str_res = S21_NULL;
  s21_size_t num = 0;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_4) {
  char str_src[30] = "abcdefghij";
  char str_ins[] = "\'I WAS HERE\'";
  char str_res[] = "abc\'I WAS HERE\'defghij";
  s21_size_t num = 3;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_5) {
  char str_src[30] = "abc";
  char str_ins[] = "333";
  char *str_res = S21_NULL;
  s21_size_t num = 10;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_6) {
  char str_src[30] = "hello, world!";
  char str_ins[] = "hELLO, WORLD!";
  char *str_res = S21_NULL;
  s21_size_t num = -1;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_7) {
  char *str_src = S21_NULL;
  char *str_ins = S21_NULL;
  char *str_res = S21_NULL;
  s21_size_t num = 0;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_8) {
  char str_src[30] = "";
  char str_ins[] = "";
  char str_res[] = "";
  s21_size_t num = 0;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_9) {
  char str_src[] = "wow";
  char *str_ins = S21_NULL;
  char *str_res = S21_NULL;
  s21_size_t num = 0;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_10) {
  char str_src[] = "";
  char *str_ins = S21_NULL;
  char *str_res = S21_NULL;
  s21_size_t num = 0;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

Suite *test_insert(void) {
  Suite *s = suite_create("\033[45m S21_INSERT \033[0m");
  TCase *tc = tcase_create("insert_tc");
  tcase_add_test(tc, test_insert_1);
  tcase_add_test(tc, test_insert_2);
  tcase_add_test(tc, test_insert_3);
  tcase_add_test(tc, test_insert_4);
  tcase_add_test(tc, test_insert_5);
  tcase_add_test(tc, test_insert_6);
  tcase_add_test(tc, test_insert_7);
  tcase_add_test(tc, test_insert_8);
  tcase_add_test(tc, test_insert_9);
  tcase_add_test(tc, test_insert_10);
  suite_add_tcase(s, tc);
  return s;
}