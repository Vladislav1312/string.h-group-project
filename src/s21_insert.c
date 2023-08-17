

#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *result = S21_NULL;
  if (str != S21_NULL && src != S21_NULL) {
    int len_str = s21_strlen(str);
    int len_src = s21_strlen(src);
    int len_result = s21_strlen(str) + s21_strlen(src);
    if ((int)start_index >= 0 && len_src >= (int)start_index) {
      result = (char *)calloc((len_str + len_src + 1), sizeof(char));
      if (result != S21_NULL) {
        int j = 0;
        int k = 0;
        for (int i = 0; i < len_result; i++) {
          if ((size_t)i == start_index) {
            while (j != len_str) {
              result[i] = str[j];
              i++;
              j++;
            }
          }
          result[i] = src[k];
          k++;
        }
      }
    }
  }
  return (void *)result;
}
