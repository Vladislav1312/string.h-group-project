// Сравнивает строку, на которую указывает str1, со строкой, на которую
// указывает str2.
#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  int result = 0;
  if (s21_strlen(str1) > s21_strlen(str2)) {
    result = 1;
  } else if (s21_strlen(str1) < s21_strlen(str2)) {
    result = -1;
  } else {
    for (int i = 0; str1[i] != '\0'; i++) {
      if (str1[i] == str2[i]) {
        continue;
      }
      if (str1[i] < str2[i]) {
        result = -1;
      }
      if (str1[i] > str2[i]) {
        result = 1;
      }
    }
  }
  return result;
}
