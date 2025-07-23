CFLAGS = -c -Wall -Werror -Wextra -std=c11
LDFLAGS = -Wall -Werror -Wextra -std=c11
SOURCE = $(wildcard s21_*.c)
OBJECTS = $(patsubst %.c,%.o, ${SOURCE})
TESTS_SOURCE = tests/*.c
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	OPEN_CMD = xdg-open
  	ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE -Wno-stringop-overread
endif
ifeq ($(UNAME_S),Darwin)
	OPEN_CMD = open
	ADD_LIB =
endif

all: s21_string.a gcov_report

s21_string.a: ${SOURCE}
	gcc $(CFLAGS) $(ADD_LIB) $(SOURCE)
	ar rcs $@ $(OBJECTS)
	ranlib s21_string.a
	-rm -rf *.o

test: s21_string.a
	gcc $(LDFLAGS) -o test $(TESTS_SOURCE) s21_string.a $(ADD_LIB) -lcheck
	./test

gcov_report:${SOURCE}
	gcc --coverage ${SOURCE} ${TESTS_SOURCE} -o test $(ADD_LIB) -lcheck
	./test
	lcov -t "test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open report/index.html
	rm -rf *.gcno *gcda *.gco
	

valg:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test


clean:
	-rm -rf *.o *.gcda *.gcno *.gcov *result coverage.info s21_test.info s21_string.a test report

.PHONY: clean all s21_string.a test gcov_report