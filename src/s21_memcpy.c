// Копирует n символов из src в dest.
#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n) {
  s21_size_t i = 0;
  if (dest != S21_NULL && src != S21_NULL) {
    for (i = 0; i < n; i++) {
      ((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
    }
  }

  return dest;
}