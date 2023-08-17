// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
// байтах строки, на которую указывает аргумент str.
#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  int flag = 0;
  s21_size_t i = 0;
  void *result = S21_NULL;
  if (str) {
    for (i = 0; i < n; i++) {
      if (*((unsigned char *)str + i) == c) {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0) {
    result = S21_NULL;
  } else {
    result = (void *)str + i;
  }
  return result;
}