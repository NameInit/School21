#include "string_suite.h"

START_TEST(strtok1) {
  char s1[] = "Hello,-! world!";
  char s2[] = "Hello,-! world!";
  char s3[] = "!-";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok2) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = ",";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok6) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "a";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok7) {
  char s1[] = "school 21";
  char s2[] = "school 42";
  char s3[] = " ";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok8) {
  char s1[] = "\nAhehehehehehehB";
  char s2[] = "\nAhehehehehehehB";
  char s3[] = "A";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok9) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok10) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok11) {
  char s1[] = "trn trn - trn trn";
  char s2[] = "trn - trn trn - trn";
  char s3[] = "trn - trn";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok12) {
  char s1[] = "Hello,       world! And other people";
  char s2[] = "Hello,       world! And other people";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = "e";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

START_TEST(strtok13) {
  char s1[] = "Hello,      worllllllllllld! And lother people      ";
  char s2[] = "Hello,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " l";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

START_TEST(strtok14) {
  char s1[] = "ASDFGHA";
  char s2[] = "ASDFGHA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

Suite *strtok_test(void) {
  Suite *s = suite_create("\033[45m S21_STRTOK \033[0m");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, strtok1);
  tcase_add_test(tc, strtok2);
  tcase_add_test(tc, strtok3);
  tcase_add_test(tc, strtok4);
  tcase_add_test(tc, strtok5);
  tcase_add_test(tc, strtok6);
  tcase_add_test(tc, strtok7);
  tcase_add_test(tc, strtok8);
  tcase_add_test(tc, strtok9);
  tcase_add_test(tc, strtok10);
  tcase_add_test(tc, strtok11);
  tcase_add_test(tc, strtok12);
  tcase_add_test(tc, strtok13);
  tcase_add_test(tc, strtok14);

  suite_add_tcase(s, tc);
  return s;
}