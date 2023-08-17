// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов.
#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
  s21_size_t count_dest = s21_strlen(dest);
  s21_size_t i = 0;
  while (i < n) {
    dest[count_dest] = src[i];
    count_dest++;
    i++;
  }
  return dest;
}