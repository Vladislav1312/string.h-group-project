// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов, не входящих в str2.
#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  for (; str1[count] != '\0'; count++) {
    if (s21_strchr(str2, str1[count])) {
      break;
    }
  }
  return count;
}