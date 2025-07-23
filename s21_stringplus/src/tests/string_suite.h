#ifndef STRING_SUITE_H
#define STRING_SUITE_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_string.h"

Suite *memchr_test(void);
Suite *memcmp_test(void);
Suite *memcpy_test(void);
Suite *memset_test(void);
Suite *strncat_test(void);
Suite *strchr_test(void);
Suite *strncmp_test(void);
Suite *strncpy_test(void);
Suite *strcspn_test(void);
Suite *strerror_test(void);
Suite *strlen_test(void);
Suite *strpbrk_test(void);
Suite *strrchr_test(void);
Suite *strstr_test(void);
Suite *strtok_test(void);

Suite *test_to_upper(void);
Suite *test_to_lower(void);
Suite *test_insert(void);
Suite *test_trim(void);

Suite *test_sprintf(void);

#endif