#include "string_suite.h"

START_TEST(memcmp1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 0;
  int n1 = memcmp(s1, s2, n);
  int n2 = s21_memcmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 1;
  int n1 = memcmp(s1, s2, n);
  int n2 = s21_memcmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 14;
  int n1 = memcmp(s1, s2, n);
  int n2 = s21_memcmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 99;
  int n1 = memcmp(s1, s2, n);
  int n2 = s21_memcmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp5) {
  char s1[] = "123456789";
  char s2[] = "123456789";
  s21_size_t n = 0;
  int n1 = memcmp(s1, s2, n);
  int n2 = s21_memcmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp6) {
  char s1[] = "123456789";
  char s2[] = "123456789";
  s21_size_t n = 1;
  int n1 = memcmp(s1, s2, n);
  int n2 = s21_memcmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp7) {
  char s1[] = "123456789";
  char s2[] = "123456789";
  s21_size_t n = 9;
  int n1 = memcmp(s1, s2, n);
  int n2 = s21_memcmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp8) {
  char s1[] = "123456789";
  char s2[] = "123456789";
  s21_size_t n = 10;
  int n1 = memcmp(s1, s2, n);
  int n2 = s21_memcmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp9) {
  char s1[] = "123456789";
  char s2[] = "1234K6789";
  s21_size_t n = -1;
  int n1 = memcmp(s1, s2, n);
  int n2 = s21_memcmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp10) {
  char s1[] = "Сравнивает первые n байтов str1 и str2.";
  char s2[] = "\0";
  s21_size_t n = 20;
  int n1 = memcmp(s1, s2, n);
  int n2 = s21_memcmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp11) {
  char s1[] = "Сравнивает первые n байтов str1\0 и str2.";
  char s2[] = "Сравнивает первые n байтов str1\0 и str2.";
  s21_size_t n = 32;
  int n1 = memcmp(s1, s2, n);
  int n2 = s21_memcmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp12) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 0;
  int n1 = memcmp(s1, s2, n);
  int n2 = s21_memcmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

Suite *memcmp_test(void) {
  Suite *s = suite_create("\033[45m S21_MEMCMP \033[0m");
  TCase *tc = tcase_create("memcmp_tc");

  tcase_add_test(tc, memcmp1);
  tcase_add_test(tc, memcmp2);
  tcase_add_test(tc, memcmp3);
  tcase_add_test(tc, memcmp4);
  tcase_add_test(tc, memcmp5);
  tcase_add_test(tc, memcmp6);
  tcase_add_test(tc, memcmp7);
  tcase_add_test(tc, memcmp8);
  tcase_add_test(tc, memcmp9);
  tcase_add_test(tc, memcmp10);
  tcase_add_test(tc, memcmp11);
  tcase_add_test(tc, memcmp12);

  suite_add_tcase(s, tc);
  return s;
}