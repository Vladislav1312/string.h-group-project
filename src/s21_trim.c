#include "s21_string.h"
void *s21_trim(const char *src, const char *trim_chars) {
  char *result = S21_NULL;
  if (src != S21_NULL) {
    int left = 0;
    int right = (int)s21_strlen(src) - 1;
    size_t result_size = (int)s21_strlen(src);

    if (trim_chars == S21_NULL || s21_strlen(trim_chars) == 0) {
      trim_chars = " ";
    }

    for (; left < (int)s21_strlen(src); left++) {
      if (!s21_strchr(trim_chars, src[left])) {
        break;
      }
      result_size--;
    }

    for (; right >= left; right--) {
      if (!s21_strchr(trim_chars, src[right])) {
        break;
      }
      result_size--;
    }

    int i = 0;
    result = (char *)calloc((result_size + 1), sizeof(char));
    if (result != S21_NULL) {
      for (int z = left; z <= right; z++) {
        result[i] = src[z];
        i++;
      }
      result[i] = '\0';
    }
  }
  return result;
}
