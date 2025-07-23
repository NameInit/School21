#ifndef S21_STRING_H
#define S21_STRING_H

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_NULL ((void *)0)
typedef unsigned long s21_size_t;

#define NUMERIC_BUFFER 256
#define MIN(a, b) (((a) >= (b)) ? (b) : (a))
#define MAX(a, b) (((a) <= (b)) ? (b) : (a))
#define ABS(a) MAX(a, -a)
#define IS_NUM(a) (a >= '0' && a <= '9')

typedef struct Flags {
  int alignment;
  int show_plus;
  int blank;
  int show_hidden;
  int fill_w_zeros;
  int width;
  int precision;
  char add_specf;
  char specf;

} Flags;

Flags parse(const char *format, int *format_ptr, va_list *args);

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

int s21_sprintf(char *str, const char *format, ...);

int s21_print_short(char **dest, Flags prot, short num);
int s21_print_long(char **dest, Flags prot, long num);
int s21_print_int(char **dest, Flags prot, int num);
int s21_print_ptr(char **dest, unsigned long num);
void s21_make_prefix(char *prefix, Flags prot, int minus);
int s21_output_num(char **dest, Flags prot, char *buffer, char *prefix);
int s21_print_double(char **dest, Flags prot, double num);
int s21_print_long_double(char **dest, Flags prot, long double num);
int s21_print_str(char **dest, Flags prot, char *str);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif
