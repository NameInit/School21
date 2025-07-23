#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t needle_tmp) {
  s21_size_t curr = needle_tmp;
  const unsigned char *new_str = (const unsigned char *)str;
  if (str != S21_NULL) {
    s21_size_t i = 0;
    while (i < needle_tmp && curr == needle_tmp) {
      if (new_str[i] == (unsigned char)c) {
        curr = i;
      }
      i++;
    }
  }
  return curr == needle_tmp ? S21_NULL : (void *)(new_str + curr);
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t needle_tmp) {
  int res = 0;
  const unsigned char *new_str1 = (const unsigned char *)str1;
  const unsigned char *new_str2 = (const unsigned char *)str2;

  for (s21_size_t i = 0; i < needle_tmp && res == 0; i++) {
    res = (int)(new_str1[i] - new_str2[i]);
  }

  return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t needle_tmp) {
  unsigned char *new_str1 = (unsigned char *)dest;
  const unsigned char *new_str2 = (const unsigned char *)src;

  for (s21_size_t i = 0; i < needle_tmp; i++) {
    new_str1[i] = new_str2[i];
  }

  return new_str1;
}

void *s21_memset(void *str, int c, s21_size_t needle_tmp) {
  unsigned char *new_str = (unsigned char *)str;
  unsigned char c2 = (unsigned char)c;

  for (s21_size_t i = 0; i < needle_tmp; i++) {
    new_str[i] = c2;
  }

  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t needle_tmp) {
  unsigned char *new_str1 = (unsigned char *)dest;

  while (*new_str1 != '\0') {
    new_str1++;
  }

  while (*src != '\0' && needle_tmp != 0) {
    *new_str1++ = *src++;
    needle_tmp--;
  }

  *new_str1 = '\0';

  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *res;
  int flag = 0;
  while (*str && !flag) {
    if (*str == (char)c) {
      res = (char *)str;
      flag = 1;
    }
    str++;
  }
  if (!flag) res = ((c == '\0') ? (char *)str : S21_NULL);
  return res;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t needle_tmp) {
  int res = 0;
  int flag = 1;

  for (s21_size_t i = 0; flag && i < needle_tmp; i++) {
    if (str1[i] != str2[i]) {
      res = str1[i] - str2[i];
      flag = 0;
    }
  }

  return res;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t needle_tmp) {
  s21_size_t i;

  for (i = 0; i < needle_tmp && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }

  for (; i < needle_tmp; i++) {
    dest[i] = '\0';
  }

  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;

  while (str1[i] != '\0' && !s21_strchr(str2, str1[i])) i++;

  return i;
}

char *s21_strerror(int errnum) {
  char *err_str = "";
#ifdef __linux__
  static char *linux_errors[] = {
      "Success",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "No such device or address",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource temporarily unavailable",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Device or resource busy",
      "File exists",
      "Invalid cross-device link",
      "No such device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Numerical result out of range",
      "Resource deadlock avoided",
      "File name too long",
      "No locks available",
      "Function not implemented",
      "Directory not empty",
      "Too many levels of symbolic links",
      "Unknown error 41",
      "No message of desired type",
      "Identifier removed",
      "Channel number out of range",
      "Level 2 not synchronized",
      "Level 3 halted",
      "Level 3 reset",
      "Link number out of range",
      "Protocol driver not attached",
      "No CSI structure available",
      "Level 2 halted",
      "Invalid exchange",
      "Invalid request descriptor",
      "Exchange full",
      "No anode",
      "Invalid request code",
      "Invalid slot",
      "Unknown error 58",
      "Bad font file format",
      "Device not a stream",
      "No data available",
      "Timer expired",
      "Out of streams resources",
      "Machine is not on the network",
      "Package not installed",
      "Object is remote",
      "Link has been severed",
      "Advertise error",
      "Srmount error",
      "Communication error on send",
      "Protocol error",
      "Multihop attempted",
      "RFS specific error",
      "Bad message",
      "Value too large for defined data type",
      "Name not unique on network",
      "File descriptor in bad state",
      "Remote address changed",
      "Can not access a needed shared library",
      "Accessing a corrupted shared library",
      ".lib section in a.out corrupted",
      "Attempting to link in too many shared libraries",
      "Cannot exec a shared library directly",
      "Invalid or incomplete multibyte or wide character",
      "Interrupted system call should be restarted",
      "Streams pipe error",
      "Too many users",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol",
      "Address already in use",
      "Cannot assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Transport endpoint is already connected",
      "Transport endpoint is not connected",
      "Cannot send after transport endpoint shutdown",
      "Too many references: cannot splice",
      "Connection timed out",
      "Connection refused",
      "Host is down",
      "No route to host",
      "Operation already in progress",
      "Operation now in progress",
      "Stale file handle",
      "Structure needs cleaning",
      "Not a XENIX named type file",
      "No XENIX semaphores available",
      "Is a named type file",
      "Remote I/O error",
      "Disk quota exceeded",
      "No medium found",
      "Wrong medium type",
      "Operation canceled",
      "Required key not available",
      "Key has expired",
      "Key has been revoked",
      "Key was rejected by service",
      "Owner died",
      "State not recoverable",
      "Operation not possible due to RF-kill",
      "Memory page has hardware error",
      "Unknown error"};
#elif __APPLE__
  static char *mac_errors[] = {
      "Error 0",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted function call",
      "Input/output error",
      "No such device or address",
      "Arg list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource deadlock avoided",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Not a block device",
      "Resource busy",
      "File exists",
      "Improper link",
      "Operation not supported by device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "Device out of space",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Numerical result out of range",
      "Resource temporarily unavailable",
      "Operation now in progress",
      "Operation already in progress",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Not supported",
      "Protocol family not supported",
      "Address family not supported by protocol family",
      "Address already in use",
      "Cannot assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Socket is already connected",
      "Socket is not connected",
      "Cannot send after socket shutdown",
      "Operation timed out",
      "Connection refused",
      "Too many levels of symbolic links",
      "File name too long",
      "Host is down",
      "No route to host",
      "Directory not empty",
      "Too many processes",
      "Too many users",
      "Disc quota exceeded",
      "Stale NFS file handle",
      "Bad RPC struct",
      "RPC version wrong",
      "RPC prog. not avail.",
      "Program version wrong",
      "Bad procedure for program",
      "No locks available",
      "Function not implemented",
      "Inappropriate file type or format",
      "Authentication error",
      "Need authenticator",
      "Device power is off",
      "Device error",
      "Value too large to be stored in data type",
      "Bad executable (or shared library)",
      "Bad CPU type in executable",
      "Shared library version mismatch",
      "Malformed Mach-o file",
      "Operation canceled",
      "Identifier removed",
      "No message of desired type",
      "Illegal byte sequence",
      "No attribute found",
      "Bad message",
      "Reserved",
      "No message available",
      "Reserved",
      "No STREAM resources",
      "Not a STREAM",
      "Protocol error",
      "STREAM ioctl() timeout",
      "Operation	not supported on socket",
      "Unknown error"};
#endif

  if (errnum >= 0) {
#ifdef __linux__
    if (errnum < (int)(sizeof(linux_errors) / sizeof(linux_errors[0])) - 1) {
      err_str = linux_errors[errnum];
    }
#elif __APPLE__
    if (errnum < (int)(sizeof(mac_errors) / sizeof(mac_errors[0])) - 1) {
      err_str = mac_errors[errnum];
    }
#endif
  } else {
#ifdef __linux__
    err_str = linux_errors[sizeof(linux_errors) / sizeof(linux_errors[0]) - 1];
#elif __APPLE__
    err_str = mac_errors[sizeof(mac_errors) / sizeof(mac_errors[0]) - 1];
#endif
  }
  return err_str;
}

s21_size_t s21_strlen(const char *str) {
  const char *begin_ptr = str;
  while (*begin_ptr != '\0') {
    ++begin_ptr;
  }

  return begin_ptr - str;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  int flag = 0;
  char *res = S21_NULL;

  for (; !flag && *str1 != '\0'; str1++) {
    for (s21_size_t i = 0; !flag && str2[i] != '\0'; i++) {
      if (*str1 == str2[i]) {
        res = (char *)str1;
        flag = 1;
      }
    }
  }

  return res;
}

char *s21_strrchr(const char *str, int c) {
  char *res = S21_NULL;
  int flag = 0;
  s21_size_t len = s21_strlen(str);
  str += len;

  for (int i = (int)len; !flag && i >= 0; i--) {
    if (*str == c) {
      res = (char *)str;
      flag = 1;
    }
    str--;
  }

  return res;
}
char *s21_strstr(const char *haystack, const char *needle) {
  char *res = S21_NULL;
  if (!*needle)
    res = (char *)haystack;
  else {
    const char *haystack_tmp, *needle_tmp;
    for (; *haystack; haystack++) {
      haystack_tmp = haystack;
      needle_tmp = needle;
      while (*haystack_tmp && *needle_tmp && *haystack_tmp == *needle_tmp) {
        haystack_tmp++;
        needle_tmp++;
      }
      if (!*needle_tmp) {
        res = (char *)haystack;
        break;
      }
    }
  }
  return res;
}

char *s21_strtok(char *str, const char *delim) {
  char *res;
  if (delim == S21_NULL)
    res = S21_NULL;
  else {
    static char *next_token = S21_NULL;
    char *token = S21_NULL;

    if (str) next_token = str;

    if (next_token) {
      while (*next_token && s21_strchr(delim, *next_token)) next_token++;

      if (*next_token != '\0') {
        token = next_token;

        while (*next_token && !s21_strchr(delim, *next_token)) next_token++;

        if (*next_token)
          *next_token++ = '\0';
        else
          next_token = S21_NULL;
      }
    }
    res = token;
  }

  return res;
}

void *s21_to_upper(const char *str) {
  char *res;
  if (str == S21_NULL)
    res = S21_NULL;
  else {
    s21_size_t len = s21_strlen(str);
    res = (char *)malloc((len + 1) * sizeof(char));

    if (res != S21_NULL) {
      for (s21_size_t i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
          res[i] = str[i] - 32;
        else
          res[i] = str[i];
      }
      res[len] = '\0';
    }
  }

  return res;
}

void *s21_to_lower(const char *str) {
  char *res;
  if (str == S21_NULL)
    res = S21_NULL;
  else {
    s21_size_t len = s21_strlen(str);
    res = (char *)malloc((len + 1) * sizeof(char));

    if (res != S21_NULL) {
      for (s21_size_t i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
          res[i] = str[i] + 32;
        else
          res[i] = str[i];
      }
      res[len] = '\0';
    }
  }

  return res;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_str_i) {
  char *str_res = S21_NULL;

  if (src != S21_NULL && str != S21_NULL) {
    int strlen_src = s21_strlen(src);
    int strlen_str = s21_strlen(str);
    int diff_strlen = strlen_src + strlen_str - start_str_i;

    if (diff_strlen >= 0 && diff_strlen <= (strlen_src + strlen_str)) {
      str_res = malloc(sizeof(char) * (strlen_src + strlen_str + 1));

      if (src[0] == '\0' && str[0] == '\0') {
        str_res[0] = '\0';
      } else {
        s21_size_t curr_index = 0;
        s21_size_t index_src = 0;
        s21_size_t index_str = 0;

        while (curr_index < start_str_i) {
          str_res[curr_index] = src[index_src];
          index_src++;
          curr_index++;
        }

        for (s21_size_t i = start_str_i; str[index_str] != '\0'; i++) {
          str_res[i] = str[index_str];
          index_str++;
          curr_index++;
        }

        while (src[index_src] != '\0') {
          str_res[curr_index] = src[index_src];
          index_src++;
          curr_index++;
        }
        str_res[curr_index] = '\0';
      }
    } else
      str_res = S21_NULL;

  } else {
    str_res = S21_NULL;
  }
  return str_res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res;
  if (src == S21_NULL)
    res = S21_NULL;
  else {
    const char *start = src;
    while (*start != '\0' && s21_strchr(trim_chars, *start) != S21_NULL)
      start++;

    const char *end = start + s21_strlen(start) - 1;
    while (end >= start && s21_strchr(trim_chars, *end) != S21_NULL) end--;

    s21_size_t len = (s21_size_t)(end - start) + 1;
    res = (char *)malloc((len + 1) * sizeof(char));
    if (res != S21_NULL) {
      s21_strncpy(res, start, len);
      res[len] = '\0';
    }
  }

  return res;
}
