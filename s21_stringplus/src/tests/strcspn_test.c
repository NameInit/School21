#include "string_suite.h"

START_TEST(strcspn_1) {
  char s1[] =
      "Hello, world! Hello, world! Hello, world! Hello, world! Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_2) {
  char s1[] =
      "Hello, world! Hello, world! Hello, world! Hello, world! Hello, world!";
  char s2[] =
      "Hello, world! Hello, world! Hello, world! Hello, world! Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_3) {
  char s1[] = "v";
  char s2[] = "vrum vrum vruuuuuum";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_4) {
  char s1[] = "";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_5) {
  char s1[] = "Hello, world!";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_6) {
  char s1[] = "9";
  char s2[] = "99";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_7) {
  char s1[] = "1234567890";
  char s2[] = "1234567890";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_8) {
  char s1[] = "1234567890";
  char s2[] = "1234567890";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_9) {
  char s1[] = "1234";
  char s2[] = "1234567890";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_10) {
  char s1[] = "1234567890";
  char s2[] = "12345";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_11) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_12) {
  char s1[] = "1234567890";
  char s2[] = "1234567890hehehheehehhe";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

Suite *strcspn_test(void) {
  Suite *s = suite_create("\033[45m S21_STRCSPN \033[0m");
  TCase *tc = tcase_create("strcspn_tc");

  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_4);
  tcase_add_test(tc, strcspn_5);
  tcase_add_test(tc, strcspn_6);
  tcase_add_test(tc, strcspn_7);
  tcase_add_test(tc, strcspn_8);
  tcase_add_test(tc, strcspn_9);
  tcase_add_test(tc, strcspn_10);
  tcase_add_test(tc, strcspn_11);
  tcase_add_test(tc, strcspn_12);

  suite_add_tcase(s, tc);
  return s;
}