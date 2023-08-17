// Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
// указывает аргумент str.
#include "s21_string.h"

void *s21_memset(void *str, int c, size_t n) {
  s21_size_t i = 0;
  for (i = 0; i < n; i++) {
    ((unsigned char *)str)[i] = c;
  }
  return (unsigned char *)str;
}