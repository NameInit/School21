#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(memchr1) {
  const char str[] = "This is a test string";
  char c = 's';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 10),
                   memchr((const void *)str, (int)c, 10));
}
END_TEST

START_TEST(memchr2) {
  const char str[] = "0123456789";
  char c = '5';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 6),
                   memchr((const void *)str, (int)c, 6));
}
END_TEST

START_TEST(memchr3) {
  const char str[] = "Hello, world!";
  char c = 'z';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, strlen(str)),
                   memchr((const void *)str, (int)c, strlen(str)));
}
END_TEST

START_TEST(memchr4) {
  const char str[] = "This is a test string";
  char c = 's';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 1),
                   memchr((const void *)str, (int)c, 1));
}
END_TEST

START_TEST(memchr5) {
  const char str[] = "\0";
  char c = 's';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 2),
                   memchr((const void *)str, (int)c, 2));
}
END_TEST

START_TEST(memchr6) {
  const char str[] = "\0\0\0";
  char c = '\0';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 2),
                   memchr((const void *)str, (int)c, 2));
}
END_TEST

START_TEST(memchr7) {
  const char str[] = "school 21";
  char c = ' ';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 8),
                   memchr((const void *)str, (int)c, 8));
}
END_TEST

START_TEST(memchr8) {
  const char str[30] = "\0school 21";
  char c = '1';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 20),
                   memchr((const void *)str, (int)c, 20));
}
END_TEST

START_TEST(memchr9) {
  const char str[] = "Hello, world!";
  char c = 'H';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 0),
                   memchr((const void *)str, (int)c, 0));
}
END_TEST

START_TEST(memchr10) {
  const char str[] = "AAAAAAAAAAAAAAAAAA!";
  char c = 'A';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 5),
                   memchr((const void *)str, (int)c, 5));
}
END_TEST

Suite *memchr_test(void) {
  Suite *s = suite_create("\033[45m S21_MEMCHR \033[0m");
  TCase *tc = tcase_create("memchr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, memchr1);
  tcase_add_test(tc, memchr2);
  tcase_add_test(tc, memchr3);
  tcase_add_test(tc, memchr4);
  tcase_add_test(tc, memchr5);
  tcase_add_test(tc, memchr6);
  tcase_add_test(tc, memchr7);
  tcase_add_test(tc, memchr8);
  tcase_add_test(tc, memchr9);
  tcase_add_test(tc, memchr10);

  suite_add_tcase(s, tc);
  return s;
}
