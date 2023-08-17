// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  int flag = 0;
  s21_size_t i = 0;
  s21_size_t j = 0;
  char *rez = S21_NULL;
  for (i = 0; str1[i] != '\0' && flag == 0; i++) {
    for (j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        flag = 1;
        rez = (char *)str1 + i;
      }
    }
  }
  return rez;
}