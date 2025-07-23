#include "string_suite.h"

START_TEST(test_trim_1) {
  char str_src[30] = "-?hello, world!";
  char str_strim[] = "!?-";
  char str_res[] = "hello, world";
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_2) {
  char str_src[30] = "MAF MAF";
  char str_strim[] = "MAF MAF";
  char *str_res = "";
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_3) {
  char *str_src = S21_NULL;
  char str_strim[] = "";
  char *str_res = S21_NULL;
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_4) {
  char str_src[30] = "!!!abcdefghij!?!";
  char str_strim[] = "!?";
  char str_res[] = "abcdefghij";
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_5) {
  char str_src[30] = "abc";
  char str_strim[] = "";
  char *str_res = "abc";
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_6) {
  char str_src[30] = "hello, world!";
  char str_strim[] = "?!";
  char *str_res = "hello, world";
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_7) {
  char *str_src = S21_NULL;
  char *str_strim = S21_NULL;
  char *str_res = S21_NULL;
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_8) {
  char str_src[30] = "";
  char str_strim[] = "";
  char str_res[] = "";
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_9) {
  char str_src[] = " wtf ";
  char *str_strim = "";
  char *str_res = " wtf ";
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

Suite *test_trim(void) {
  Suite *s = suite_create("\033[45m S21_TRIM \033[0m");
  TCase *tc = tcase_create("trim_tc");

  tcase_add_test(tc, test_trim_1);
  tcase_add_test(tc, test_trim_2);
  tcase_add_test(tc, test_trim_3);
  tcase_add_test(tc, test_trim_4);
  tcase_add_test(tc, test_trim_5);
  tcase_add_test(tc, test_trim_6);
  tcase_add_test(tc, test_trim_7);
  tcase_add_test(tc, test_trim_8);
  tcase_add_test(tc, test_trim_9);

  suite_add_tcase(s, tc);
  return s;
}