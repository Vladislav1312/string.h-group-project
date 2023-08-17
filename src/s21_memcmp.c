// Сравнивает первые n байтов str1 и str2.
// 0 – если сравниваемые части массивов идентичны.
// Положительное число – байт str1 > байта str2
// Отрицательное число – байт str1 < байта str2

#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  int res = 0;
  const unsigned char *ptr1 = (const unsigned char *)str1,
                      *ptr2 = (const unsigned char *)str2;
  while (n != 0) {
    if (*ptr1 > *ptr2 || *ptr1 < *ptr2) {
      res = *ptr1 - *ptr2;
      break;
    }
    n--;
    ptr1++;
    ptr2++;
  }

  // if (res < 0)
  //   res = -1;
  // else if (res > 0)
  //   res = 1;

  return res;
}
