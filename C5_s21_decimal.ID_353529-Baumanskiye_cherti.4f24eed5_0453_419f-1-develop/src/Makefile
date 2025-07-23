CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LDFLAGS = -lm -lcheck -lsubunit

SRC_DIRS = ./support ./arithmetics ./comparison ./convertors ./other
TEST_DIR = ./test

header = s21_decimal.h $(wildcard ./header/*.h)
SOURCES_ALL = $(wildcard ./support/*.c) \
              $(wildcard ./arithmetics/*.c) \
              $(wildcard ./convertors/*.c) \
              $(wildcard ./comparison/*.c) \
              $(wildcard ./other/*.c)

OBJ_LIBRARY = $(patsubst %.c, %.o, $(SOURCES_ALL))

.PHONY: all clean rebuild check test gcov_report personal clean_coverage

all: s21_decimal.a test gcov_report

s21_decimal.a: $(OBJ_LIBRARY)
	ar rcs s21_decimal.a $(OBJ_LIBRARY)
	ranlib s21_decimal.a
	@echo "✅ Library built successfully!"

%.o: %.c $(header)
	$(CC) $(CFLAGS) -c $< -o $@

test: s21_decimal.a
	$(CC) $(CFLAGS) $(TEST_DIR)/test.c s21_decimal.a -o test.out $(LDFLAGS)
	./test.out

gcov_report: clean_coverage
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(TEST_DIR)/test.c $(SOURCES_ALL) -o report.out $(LDFLAGS)
	./report.out
	@echo "📊 Generating coverage report..."
	lcov --capture --directory . --output-file coverage.info --exclude '*/test/*'
	genhtml coverage.info --output-directory report --title "s21_decimal Coverage"
	@rm -f coverage.info report.out
	@echo "✅ Report generated at ./report/index.html"
	@find . -name "*.gcda" -delete
	@find . -name "*.gcno" -delete
	@find . -name "*.gcov" -delete
	@rm -f *.o *.a *.info *.out
	@find . -name "*.o" -delete

clean:
	@find . -name "*.gcda" -delete
	@find . -name "*.gcno" -delete
	@find . -name "*.gcov" -delete
	@rm -rf report
	@rm -f *.o *.a *.info *.out
	@find . -name "*.o" -delete

rebuild: clean all