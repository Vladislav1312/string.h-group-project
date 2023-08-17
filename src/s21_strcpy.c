// Копирует строку, на которую указывает src, в dest.
#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *result = dest;
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  return result;
}