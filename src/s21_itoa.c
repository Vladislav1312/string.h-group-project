// Реализация от Кернигана и Ритчи: конвертируем int в str
#include "s21_string.h"

void s21_itoa(long int n, char *str) {
  int count = 0;
  while (n / 10 != 0) {
    str[count++] = (n % 10) + '0';  // записываем в обратном порядке
    n /= 10;
  }
  str[count++] = n + '0';
  str[count] = '\0';
}
