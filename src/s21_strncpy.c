// Копирует до n символов из строки, на которую указывает src, в dest.
#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *result = dest;
  s21_size_t i = 0;
  while (i < n) {
    dest[i] = src[i];
    i++;
  }
  return result;
}