#include "string_suite.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {

      memchr_test(),
      memcmp_test(),
      memcpy_test(),
      memset_test(),
      strncat_test(),
      strchr_test(),
      strncmp_test(),
      strncpy_test(),
      strcspn_test(),
      strerror_test(),
      strlen_test(),
      strpbrk_test(),
      strrchr_test(),
      strstr_test(),
      strtok_test(),

      test_sprintf(),

      test_to_upper(),
      test_to_lower(),
      test_insert(),
      test_trim(),
      NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}