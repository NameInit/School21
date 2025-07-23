CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LDFLAGS = -lcheck -lsubunit -lm -lpthread

SRC_DIRS = func
TEST_DIR = test

SOURCES = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJECTS = $(SOURCES:.c=.o)
GCOV_OBJECTS = $(SOURCES:.c=.gcda) $(SOURCES:.c=.gcno) $(SOURCES:.c=.gcov)

HEADER = s21_matrix.h

.PHONY: all clean test s21_matrix.a gcov_report rebuild

all: s21_matrix.a test gcov_report

s21_matrix.a: $(OBJECTS)
	ar rcs $@ $^
	ranlib $@
	@echo "Library built successfully!"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

test: s21_matrix.a
	$(CC) $(CFLAGS) $(TEST_DIR)/test.c s21_matrix.a -o test.out $(LDFLAGS)
	./test.out

gcov_report: clean_gcov
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(TEST_DIR)/test.c $(SOURCES) -o report.out $(LDFLAGS)
	-./report.out
	@echo "Generating coverage report..."
	lcov --capture --directory . --output-file coverage.info --exclude '*/test/*'
	genhtml coverage.info --output-directory report
	@echo "Report generated at report/index.html"

clean_gcov:
	@rm -f *.gcda *.gcno *.gcov coverage.info report.out
	@find . -name '*.gcda' -delete
	@find . -name '*.gcno' -delete
	@find . -name '*.gcov' -delete

clean: clean_gcov
	@rm -rf report
	@rm -f *.o *.a *.info *.out
	@find . -name '*.o' -delete

rebuild: clean all