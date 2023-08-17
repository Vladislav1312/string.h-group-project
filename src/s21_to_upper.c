#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *result = S21_NULL;
  if (str != S21_NULL) {
    int i = s21_strlen(str);
    result = (char *)calloc((i + 1), sizeof(char));
    if (result != S21_NULL) {
      for (int j = 0; j <= i; j++) {
        if (str[j] >= 97 && str[j] <= 122) {
          result[j] = str[j] - 32;
        } else
          result[j] = str[j];
      }
      result[i] = '\0';
    }
  }
  return result;
}