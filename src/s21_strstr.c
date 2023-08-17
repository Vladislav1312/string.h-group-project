// Находит первое вхождение всей строки needle (не включая завершающий нулевой
// символ), которая появляется в строке haystack.
#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = S21_NULL;
  s21_size_t len_needle = s21_strlen(needle);
  if (!len_needle)
    res = (char *)haystack;
  else {
    for (; *haystack != '\0'; haystack++) {
      if (*haystack == *needle &&
          s21_strncmp(haystack, needle, len_needle) == 0) {
        res = (char *)haystack;
        break;
      }
    }
  }
  return res;
}
