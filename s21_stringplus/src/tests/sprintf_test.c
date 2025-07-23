#include "string_suite.h"

START_TEST(test_sprintf_d_1) {
  char dest1[50];
  char dest2[50];
  char format_buffer[50];
  for (int i = 0; i < 50; i++) {
    dest1[i] = '\0';
    dest2[i] = '\0';
  }
  strcpy(format_buffer, "just a %d string");
  s21_sprintf(dest1, format_buffer, 555);
  sprintf(dest2, format_buffer, 555);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_sprintf_d_2) {
  char dest1[50];
  char dest2[50];
  char format_buffer[50];
  for (int i = 0; i < 50; i++) {
    dest1[i] = '\0';
    dest2[i] = '\0';
  }
  strcpy(format_buffer, "just a %.*d string");
  s21_sprintf(dest1, format_buffer, 5, 1);
  sprintf(dest2, format_buffer, 5, 1);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_sprintf_d_3) {
  char dest1[50];
  char dest2[50];
  char format_buffer[50];
  for (int i = 0; i < 50; i++) {
    dest1[i] = '\0';
    dest2[i] = '\0';
  }
  strcpy(format_buffer, "just a %*d string");
  s21_sprintf(dest1, format_buffer, 5, -5);
  sprintf(dest2, format_buffer, 5, -5);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_sprintf_d_4) {
  char dest1[50];
  char dest2[50];
  char format_buffer[50];
  for (int i = 0; i < 50; i++) {
    dest1[i] = '\0';
    dest2[i] = '\0';
  }
  strcpy(format_buffer, "just a %d %d string");
  s21_sprintf(dest1, format_buffer, -5, 10);
  sprintf(dest2, format_buffer, -5, 10);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_sprintf_p) {
  int res1, res2;
  char dest1[512];
  char dest2[512];
  for (int i = 0; i < 512; i++) {
    dest1[i] = '\0';
    dest2[i] = '\0';
  }
  res1 = s21_sprintf(dest1, "%p", &res1);
  res2 = sprintf(dest2, "%p", &res1);
  ck_assert_msg(strncmp(dest1, dest2, 10) == 0, "s21: %s, cor: %s", dest1,
                dest2);
  ck_assert_msg(res1 == res2, "s21: %d, cor: %d", res1, res2);
}
END_TEST

START_TEST(test_sprintf_n) {
  int res1, res2;
  char dest1[1024];
  char dest2[1024];
  int n1 = 0, n2 = 0;
  res1 = s21_sprintf(dest1, "abc %n", &n1);
  res2 = sprintf(dest2, "abc %n", &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_sprintf_autogen) {
  int res1, res2;
  char dest1[1024];
  char dest2[1024];
  char format_buffer[512];
  char exec_buffer[512];

  for (int i = 0; i < 512; i++) {
    dest1[i] = '\0';
    dest2[i] = '\0';
  }

  char flags[5] = {'+', '-', ' ', '0', '#'};
  int flags_ptr = 0;
  char width[4][5] = {"0", "1", "5", "15"};
  int width_ptr = -1;
  char precision[4][5] = {"0", "1", "5", "15"};
  int precision_ptr = -1;

#define CASES 5

  int test_ints[CASES] = {0, -0, 1, 55, -55};
  int test_pos_ints[CASES] = {1, 1, 55, 555, 1234};
  double test_floats[CASES] = {123.1234, -123.1234, 1, 0, 3412123425};
  long double test_long_double[CASES] = {123.1234, -123.1234, 1, 0, 3412123425};
  char test_chars[CASES] = {'K', 'a', 'P', 'O', 'b'};
  char test_strings[CASES][64] = {
      "", "asd", "askjdadf", "ajdsnfjkafjkasdkfkadbfkabkhdfkhasbdfakdsfkad",
      "p"};
  int case_ptr = 0;
  int counter = 0;

  while (1) {
    counter++;
    format_buffer[0] = '%';
    int format_ptr = 1;
    for (int i = 0; i < 5; i++) {
      if ((flags_ptr >> i) & 1) {
        format_buffer[format_ptr] = flags[i];
        format_ptr++;
      }
    }

    format_buffer[format_ptr] = '\0';

    if (width_ptr != -1) {
      strcat(format_buffer, width[width_ptr]);
    }

    if (precision_ptr != -1) {
      strcat(format_buffer, ".");
      strcat(format_buffer, precision[precision_ptr]);
    }

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "ld");
    res1 = s21_sprintf(dest1, exec_buffer, test_ints[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_ints[case_ptr]);
    ck_assert_msg(strcmp(dest1, dest2) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_int_eq(res1, res2);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "hd");
    res1 = s21_sprintf(dest1, exec_buffer, test_ints[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_ints[case_ptr]);
    ck_assert_msg(strcmp(dest1, dest2) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_int_eq(res1, res2);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "d");
    res1 = s21_sprintf(dest1, exec_buffer, test_ints[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_ints[case_ptr]);
    ck_assert_msg(strcmp(dest1, dest2) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_int_eq(res1, res2);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "i");
    res1 = s21_sprintf(dest1, exec_buffer, test_ints[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_ints[case_ptr]);
    ck_assert_msg(strcmp(dest1, dest2) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_int_eq(res1, res2);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "x");
    res1 = s21_sprintf(dest1, exec_buffer, test_pos_ints[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_pos_ints[case_ptr]);
    ck_assert_msg(strcmp(dest1, dest2) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_int_eq(res1, res2);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "X");
    res1 = s21_sprintf(dest1, exec_buffer, test_pos_ints[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_pos_ints[case_ptr]);
    ck_assert_msg(strcmp(dest1, dest2) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_int_eq(res1, res2);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "u");
    res1 = s21_sprintf(dest1, exec_buffer, test_pos_ints[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_pos_ints[case_ptr]);
    ck_assert_msg(strcmp(dest1, dest2) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_int_eq(res1, res2);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "o");
    res1 = s21_sprintf(dest1, exec_buffer, test_pos_ints[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_pos_ints[case_ptr]);
    ck_assert_msg(strcmp(dest1, dest2) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_int_eq(res1, res2);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "s");
    res1 = s21_sprintf(dest1, exec_buffer, test_strings[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_strings[case_ptr]);
    ck_assert_msg(strcmp(dest1, dest2) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_int_eq(res1, res2);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "c");
    res1 = s21_sprintf(dest1, exec_buffer, test_chars[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_chars[case_ptr]);
    ck_assert_msg(strcmp(dest1, dest2) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_msg(res1 == res2,
                  "format: %s, s21: %d, cor: %d, passed tests: %d, value: %c",
                  exec_buffer, res1, res2, counter, test_chars[case_ptr]);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "lc");
    res1 = s21_sprintf(dest1, exec_buffer, test_chars[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_chars[case_ptr]);
    ck_assert_msg(strcmp(dest1, dest2) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_msg(res1 == res2,
                  "format: %s, value: %c, s21: %d, cor: %d, passed tests: %d",
                  exec_buffer, test_chars[case_ptr], res1, res2, counter);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "f");
    res1 = s21_sprintf(dest1, exec_buffer, test_floats[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_floats[case_ptr]);
    ck_assert_msg(strncmp(dest1, dest2, 3 + 7) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_int_eq(res1, res2);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "Lf");
    res1 = s21_sprintf(dest1, exec_buffer, test_long_double[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_long_double[case_ptr]);
    ck_assert_msg(strncmp(dest1, dest2, 3 + 7) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_int_eq(res1, res2);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "g");
    res1 = s21_sprintf(dest1, exec_buffer, test_floats[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_floats[case_ptr]);
    ck_assert_msg(strncmp(dest1, dest2, 3 + 7) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);

    ck_assert_int_eq(res1, res2);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "G");
    res1 = s21_sprintf(dest1, exec_buffer, test_floats[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_floats[case_ptr]);
    ck_assert_msg(strncmp(dest1, dest2, 8) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_int_eq(res1, res2);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "e");
    res1 = s21_sprintf(dest1, exec_buffer, test_floats[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_floats[case_ptr]);
    ck_assert_msg(strncmp(dest1, dest2, 8) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_int_eq(res1, res2);

    strcpy(exec_buffer, format_buffer);
    strcat(exec_buffer, "E");
    res1 = s21_sprintf(dest1, exec_buffer, test_floats[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_floats[case_ptr]);

    ck_assert_msg(strncmp(dest1, dest2, 8) == 0,

                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);

    ck_assert_int_eq(res1, res2);

    strcpy(exec_buffer, format_buffer);

    strcat(exec_buffer, "f %% ");

    res1 = s21_sprintf(dest1, exec_buffer, test_floats[case_ptr]);
    res2 = sprintf(dest2, exec_buffer, test_floats[case_ptr]);
    ck_assert_msg(strncmp(dest1, dest2, 10) == 0,
                  "format: %s, s21: %s, cor: %s, passed: %d", exec_buffer,
                  dest1, dest2, counter);
    ck_assert_msg(res1 == res2, "format: %s, s21: %d, cor: %d, passed: %d",
                  exec_buffer, res1, res2, counter);

    if (flags_ptr < 31) {
      flags_ptr++;
    } else if (width_ptr < 3) {
      flags_ptr = 0;
      width_ptr++;
    } else if (precision_ptr < 3) {
      flags_ptr = 0;
      width_ptr = -1;
      precision_ptr++;
    } else if (case_ptr < CASES - 1) {
      flags_ptr = 0;
      width_ptr = -1;
      precision_ptr = -1;
      case_ptr++;
    } else {
      break;
    }
  }
}

END_TEST

Suite *test_sprintf(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF \033[0m");
  TCase *tc = tcase_create("sprintf_tc");
  tcase_add_test(tc, test_sprintf_d_1);
  tcase_add_test(tc, test_sprintf_d_2);
  tcase_add_test(tc, test_sprintf_d_3);
  tcase_add_test(tc, test_sprintf_d_4);
  tcase_add_test(tc, test_sprintf_p);
  tcase_add_test(tc, test_sprintf_n);
  tcase_add_test(tc, test_sprintf_autogen);
  suite_add_tcase(s, tc);
  return s;
}