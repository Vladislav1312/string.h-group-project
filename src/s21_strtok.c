// Разбивает строку str на ряд токенов, разделенных delim.
#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  // new_string - новая строка, которая каждый раз сдвигается за счет указателя
  // share - часть строки, которая стоит перед разделителем

  static char *new_string = S21_NULL;
  if (str != S21_NULL) {
    new_string = str;
  }
  if (new_string == S21_NULL) {
    return S21_NULL;
  }
  char *share = new_string;
  while (*new_string != '\0') {
    if (s21_strchr(delim, *new_string) != S21_NULL) {
      *new_string = '\0';
      new_string++;
      if (*share != '\0') {
        return share;
      } else {
        share = new_string;
      }
    } else {
      new_string++;
    }
  }
  if (*share != '\0') {
    return share;
  } else {
    return S21_NULL;
  }
}