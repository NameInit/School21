#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int format_ptr = 0, counter = 0;
  while (format[format_ptr]) {
    if (format[format_ptr] != '%') {
      *str = format[format_ptr];
      str += 1;
      format_ptr++, counter++;
    } else {
      format_ptr++;
      Flags flag = parse(format, &format_ptr, &args);

      if (s21_strchr("idoxuX", flag.specf)) {
        if (flag.add_specf == 'h') {
          counter += s21_print_short(&str, flag, (short int)va_arg(args, int));
        } else if (flag.add_specf == 'l') {
          counter += s21_print_long(&str, flag, va_arg(args, long));
        } else {
          counter += s21_print_int(&str, flag, va_arg(args, int));
        }

      } else if (s21_strchr("eEfgG", flag.specf)) {
        if (flag.add_specf == 'L') {
          counter +=
              s21_print_long_double(&str, flag, va_arg(args, long double));
        } else {
          counter += s21_print_double(&str, flag, va_arg(args, double));
        }

      } else if (flag.specf == 'c' || flag.specf == '%') {
        char to_print[2] = {(flag.specf == '%') ? '%' : (char)va_arg(args, int),
                            '\0'};
        flag.precision = -1;
        counter += s21_print_str(&str, flag, to_print);
      } else if (flag.specf == 's') {
        counter += s21_print_str(&str, flag, va_arg(args, char *));
      } else if (flag.specf == 'p') {
        unsigned long ptr = va_arg(args, unsigned long);
        flag.show_hidden = 1;
        flag.specf = 'x';
        counter += s21_print_long(&str, flag, ptr);
      } else if (flag.specf == 'n') {
        *va_arg(args, int *) = counter;
      }
    }
  }
  *str = '\0';
  va_end(args);
  return counter;
}

Flags parse(const char *format, int *format_ptr, va_list *args) {
  Flags result = {0, 0, 0, 0, 0, -1, -1, '/', '/'};

  while (s21_strchr("-+ #0", format[*format_ptr]) && format[*format_ptr]) {
    if (format[*format_ptr] == '-') result.alignment = 1;
    if (format[*format_ptr] == '+') result.show_plus = 1;
    if (format[*format_ptr] == ' ') result.blank = 1;
    if (format[*format_ptr] == '#') result.show_hidden = 1;
    if (format[*format_ptr] == '0') result.fill_w_zeros = 1;
    *format_ptr += 1;
  }

  if (format[*format_ptr] == '*') {
    result.width = va_arg(*args, int);
    *format_ptr += 1;
  }
  while (format[*format_ptr] >= 48 && format[*format_ptr] < 58 &&
         format[*format_ptr]) {
    if (result.width < 0) result.width = 0;
    result.width = result.width * 10 + (format[*format_ptr] - 48);
    *format_ptr += 1;
  }

  if (format[*format_ptr] == '.') {
    result.precision = 0;
    *format_ptr += 1;
    if (format[*format_ptr] == '*') {
      result.precision = va_arg(*args, int);
      *format_ptr += 1;
    }
    while (format[*format_ptr] >= 48 && format[*format_ptr] < 58 &&
           format[*format_ptr]) {
      result.precision = result.precision * 10 + (format[*format_ptr] - 48);
      *format_ptr += 1;
    }
  }

  if (s21_strchr("hlL", format[*format_ptr]) && format[*format_ptr] &&
      format[*format_ptr]) {
    result.add_specf = format[*format_ptr];
    *format_ptr += 1;
  }
  assert(s21_strchr("cdieEfgGosuxXpn%", format[*format_ptr]) &&
         format[*format_ptr] && format[*format_ptr]);
  result.specf = format[*format_ptr];
  *format_ptr += 1;

  return result;
}

#define OUT_INT(name, type)                                                   \
  int s21_print_##type(char **dest, Flags flag, type num) {                   \
    char prefix[NUMERIC_BUFFER] = "\0";                                       \
    unsigned type unum = 0;                                                   \
    if (s21_strchr("xXuo", flag.specf)) {                                     \
      unum = (unsigned type)num;                                              \
    } else {                                                                  \
      unum = (num < 0) ? -num : num;                                          \
    }                                                                         \
    s21_make_prefix(prefix, flag, (int)(num < 0));                            \
    int base = 10;                                                            \
    if (flag.specf == 'o') {                                                  \
      base = 8;                                                               \
    } else if ((flag.specf == 'x' || flag.specf == 'X')) {                    \
      base = 16;                                                              \
    }                                                                         \
    char buffer[NUMERIC_BUFFER];                                              \
    int ptr = NUMERIC_BUFFER - 1;                                             \
    buffer[ptr] = '\0';                                                       \
                                                                              \
    while (unum > 0) {                                                        \
      ptr--;                                                                  \
      buffer[ptr] = unum % base;                                              \
      unum = unum / base;                                                     \
      if (buffer[ptr] >= 10) {                                                \
        buffer[ptr] = buffer[ptr] + 55 + (int)((flag.specf == 'x') ? 32 : 0); \
      } else {                                                                \
        buffer[ptr] = buffer[ptr] + 48;                                       \
      }                                                                       \
    }                                                                         \
                                                                              \
    if (flag.precision == -1) {                                               \
      flag.precision = 1;                                                     \
    } else {                                                                  \
      flag.fill_w_zeros = 0;                                                  \
    }                                                                         \
    if (NUMERIC_BUFFER - 1 == ptr && s21_strchr("xXo", flag.specf))           \
      s21_strncpy(prefix, "\0", NUMERIC_BUFFER);                              \
    while (NUMERIC_BUFFER - 1 - ptr < flag.precision) {                       \
      ptr--;                                                                  \
      buffer[ptr] = '0';                                                      \
      if (flag.specf == 'o') s21_strncpy(prefix, "\0", NUMERIC_BUFFER);       \
    }                                                                         \
                                                                              \
    return s21_output_num(dest, flag, &buffer[ptr], prefix);                  \
  }

OUT_INT(int, int);
OUT_INT(long, long);
OUT_INT(short, short);

void s21_make_prefix(char *prefix, Flags flag, int minus) {
  if (flag.show_hidden && (flag.specf == 'x' || flag.specf == 'X')) {
    s21_strncpy(prefix, (flag.specf == 'x') ? "0x" : "0X", 8);
  } else if (flag.show_hidden && flag.specf == 'o') {
    s21_strncpy(prefix, "0", 8);
  } else if (s21_strchr("ideEgGf", flag.specf) && !minus) {
    if (flag.show_plus) {
      s21_strncpy(prefix, "+", 8);
    } else if (flag.blank) {
      s21_strncpy(prefix, " ", 8);
    }
  } else if (s21_strchr("ideEgGf", flag.specf) && minus) {
    s21_strncpy(prefix, "-", 8);
  }
}

int s21_output_num(char **dest, Flags flag, char *buffer, char *prefix) {
  int blanks_before = 0;
  int blanks_after = 0;
  int num_of_ch = (int)(s21_strlen(prefix) + s21_strlen(buffer));
  int zeros = 0;
  if (flag.width > -1) {
    if (flag.alignment) {
      blanks_after = flag.width - num_of_ch - zeros;
    } else if (flag.fill_w_zeros) {
      zeros = MAX(flag.width - num_of_ch, zeros);
    } else {
      blanks_before = flag.width - num_of_ch - zeros;
    }
  }

  int counter = 0;
  for (; blanks_before > 0; blanks_before--, *dest += 1, counter++)
    **dest = ' ';
  for (int i = 0; prefix[i]; i++, *dest += 1, counter++) **dest = prefix[i];
  for (; zeros > 0; zeros--, *dest += 1, counter++) **dest = '0';
  for (int i = 0; buffer[i]; i++, *dest += 1, counter++) **dest = buffer[i];
  for (; blanks_after > 0; blanks_after--, *dest += 1, counter++) **dest = ' ';
  return counter;
}

#define OUT_FLT(name, type)                                                    \
  int count_offset_##name(type a) {                                            \
    a = ABS(a);                                                                \
    int result = 0;                                                            \
    if (a < 1 && a != 0) {                                                     \
      while (a * pow(10, result) < 1) result++;                                \
    } else if (a >= 10) {                                                      \
      while (a >= pow(10, 1 - result)) result--;                               \
    }                                                                          \
    return -result;                                                            \
  }                                                                            \
                                                                               \
  int s21_print_##name(char **dest, Flags flag, type num) {                    \
    if (flag.precision == -1) flag.precision = 6;                              \
    char prefix[NUMERIC_BUFFER] = "\0";                                        \
    s21_make_prefix(prefix, flag, (int)(num < 0));                             \
                                                                               \
    int use_offset = 0;                                                        \
    int offset = count_offset_##name(num);                                     \
    if (s21_strchr("eE", flag.specf) ||                                        \
        (s21_strchr("gG", flag.specf) &&                                       \
         (offset >= flag.precision || offset < -4) && offset != 0)) {          \
      use_offset = 1;                                                          \
      num *= pow(10, -offset);                                                 \
    }                                                                          \
                                                                               \
    long double u_wh = ((num < 0) ? -num : num);                               \
    int float_num = flag.precision;                                            \
    if (s21_strchr("gG", flag.specf)) {                                        \
      float_num -= (!use_offset) ? MAX(offset + 1, 1) : 1;                     \
    }                                                                          \
    float_num = MAX(0, float_num);                                             \
    u_wh = round(u_wh * pow(10, float_num)) * pow(10, -float_num);             \
    unsigned long u_int = floor(u_wh);                                         \
    long double u_float = u_wh - u_int;                                        \
                                                                               \
    char int_buffer[NUMERIC_BUFFER];                                           \
    char *int_ptr = int_buffer;                                                \
    s21_print_long(&int_ptr, (Flags){0, 0, 0, 0, 0, -1, -1, 'l', 'u'}, u_int); \
    *int_ptr = '\0';                                                           \
                                                                               \
    char float_buffer[NUMERIC_BUFFER];                                         \
    char *float_ptr = float_buffer;                                            \
    if (float_num > 0) {                                                       \
      s21_print_long(&float_ptr,                                               \
                     (Flags){0, 0, 0, 0, 0, -1, float_num, 'l', 'u'},          \
                     round(u_float *pow(10, float_num)));                      \
    }                                                                          \
    *float_ptr = '\0';                                                         \
    if (s21_strchr("gG", flag.specf) && !flag.show_hidden) {                   \
      while (float_ptr - 1 >= float_buffer && *(float_ptr - 1) == '0') {       \
        float_ptr--;                                                           \
        *float_ptr = '\0';                                                     \
      }                                                                        \
    }                                                                          \
                                                                               \
    char final_buffer[NUMERIC_BUFFER];                                         \
    s21_strncpy(final_buffer, int_buffer, NUMERIC_BUFFER);                     \
    if (s21_strlen(float_buffer) || flag.show_hidden)                          \
      s21_strncat(final_buffer, ".", 1);                                       \
    s21_strncat(final_buffer, float_buffer, NUMERIC_BUFFER);                   \
    if (use_offset) {                                                          \
      char exp_buffer[NUMERIC_BUFFER];                                         \
      char *exp_ptr = exp_buffer;                                              \
      *exp_ptr = (flag.specf > 'a') ? 'e' : 'E';                               \
      exp_ptr += 1;                                                            \
      s21_print_int(&exp_ptr, (Flags){0, 1, 0, 0, 0, -1, 2, '/', 'd'},         \
                    offset);                                                   \
      *exp_ptr = '\0';                                                         \
      s21_strncat(final_buffer, exp_buffer, NUMERIC_BUFFER);                   \
    }                                                                          \
    return s21_output_num(dest, flag, final_buffer, prefix);                   \
  }

OUT_FLT(double, double)
OUT_FLT(long_double, long double)

int s21_print_str(char **dest, Flags flag, char *str) {
  if (str == S21_NULL) {
    str = "(null)";
  }
  int blanks_bef = 0;
  int zeros = 0;
  int num_of_ch = (int)s21_strlen(str);
#if !defined(__APPLE__) && !defined(__MACH__)
  flag.fill_w_zeros = 0;
#endif
  if (flag.precision != -1) {
    num_of_ch = MIN(num_of_ch, flag.precision);
  }
  int blanks_after = 0;
  if (flag.width > -1) {
    if (flag.alignment) {
      blanks_after = flag.width - num_of_ch - zeros;
    } else if (flag.fill_w_zeros) {
      zeros = MAX(flag.width - num_of_ch, zeros);
    } else {
      blanks_bef = flag.width - num_of_ch - zeros;
    }
  }

  int counter = 0;
  for (; blanks_bef > 0; blanks_bef--, *dest += 1, counter++) **dest = ' ';
  for (; zeros > 0; zeros--, *dest += 1, counter++) **dest = '0';
  for (; num_of_ch > 0; num_of_ch--, *dest += 1, str += 1, counter++)
    **dest = *str;
  for (; blanks_after > 0; blanks_after--, *dest += 1, counter++) **dest = ' ';
  return counter;
}