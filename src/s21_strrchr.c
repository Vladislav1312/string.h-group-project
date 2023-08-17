// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = S21_NULL;
  int counter = 0;
  if (*str == '\0' && c == '\0')
    res = (char *)str;
  else {
    for (; *str != '\0'; str++, counter++)
      ;
    for (; *str != c && counter != 0; str--, counter--)
      ;
    res = counter != 0 ? (char *)str : S21_NULL;
  }
  return res;
}
