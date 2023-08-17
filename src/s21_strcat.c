// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest.
#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  s21_size_t count_dest = s21_strlen(dest);
  s21_size_t i = 0;
  while (src[i] != '\0') {
    dest[count_dest] = src[i];
    count_dest++;
    i++;
  }
  // dest[count_dest] = '\0';
  return dest;
}
