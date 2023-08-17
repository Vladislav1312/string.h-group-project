// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;
  if (c == '\0')
    res = (char *)str + s21_strlen(str);
  else {
    for (; *str != '\0'; str++) {
      if (*str == c) {
        res = (char *)str;
        break;
      }
    }
  }
  return res;
}
