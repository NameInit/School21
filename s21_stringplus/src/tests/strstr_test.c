#include "string_suite.h"

START_TEST(strstr1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, P!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr3) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr4) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] = "world";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr6) {
  char s1[] = "Hello, world!";
  char s2[] = "";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr7) {
  char s1[] = "Hello, G!";
  char s2[] = "Hello, P!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr8) {
  char s1[] = "123454";
  char s2[] = "0";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr9) {
  char s1[] = "\01";
  char s2[] = "\0";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr10) {
  char s1[] = "69917020";
  char s2[] = "32859160 8v3489-74 tvc4y8719c n4[nqymu uv 4vm9cw";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr11) {
  char s1[] = "1   345 345 345 345 345";
  char s2[] = "345";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr12) {
  char s1[] = "ubuntu";
  char s2[] = "ubuntu ";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

Suite *strstr_test(void) {
  Suite *s = suite_create("\033[45m S21_STRSTR \033[0m");
  TCase *tc = tcase_create("strstr_tc");

  tcase_add_test(tc, strstr1);
  tcase_add_test(tc, strstr2);
  tcase_add_test(tc, strstr3);
  tcase_add_test(tc, strstr4);
  tcase_add_test(tc, strstr5);
  tcase_add_test(tc, strstr6);
  tcase_add_test(tc, strstr7);
  tcase_add_test(tc, strstr8);
  tcase_add_test(tc, strstr9);
  tcase_add_test(tc, strstr10);
  tcase_add_test(tc, strstr11);
  tcase_add_test(tc, strstr12);

  suite_add_tcase(s, tc);
  return s;
}