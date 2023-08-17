#include "s21_string.h"

void s21_uitoa(unsigned long n, char *str) {
  char *temp = str;
  if (n == 0) {
    *temp = '0';
    temp++;
  }
  while (n != 0) {
    *temp = "0123456789abcdef"[n % 10];
    n /= 10;
    temp++;
  }
}