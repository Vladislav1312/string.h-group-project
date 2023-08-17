#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

#define MAX 512

#define SCHAR_MAX __SCHAR_MAX__
#define SHRT_MAX __SHRT_MAX__
#define INT_MAX __INT_MAX__
#define LONG_MAX __LONG_MAX__

#define SCHAR_MIN (-__SCHAR_MAX__ - 1)
#define SHRT_MIN (-__SHRT_MAX__ - 1)
#define INT_MIN (-__INT_MAX__ - 1)
#define LONG_MIN (-__LONG_MAX__ - 1L)

#define UCHAR_MAX (__SCHAR_MAX__ * 2 + 1)
#define USHRT_MAX (__SHRT_MAX__ * 2 + 1)
#define UINT_MAX (__INT_MAX__ * 2U + 1U)
#define ULONG_MAX (__LONG_MAX__ * 2UL + 1UL)

char buff[MAX] = "";
char buff2[MAX] = "";

/* -----------------content--------------------

1.67.strlen
2.78.strcmp
3.104.strncmp
4.134.strcpy
5.151.strncpy
6.168.strcat
7.184.strncat
8.201.strchr
9.215.strrchr
10.229.strstr
11.246.memchr
12.266.memcpy
13.287.memset
14.303.memcmp
15.322.strtok
16.340.strpbrk
17.358.strcspn
18.374.upper
19.403.lower
20.432.insert
21.544.trim
22.647.strerror
23.649.sprintf_precent
24.708.sprintf_spec_c
25.1265.sprintf_without_spec
16.1273.sprintf_spec_d
27.2246.sprintf_spec_u
28.2830.sprintf_spec_f
29.4341.sprintf_spec_i
30.4995.sprintf_spec_s





*/

//___________________STRLEN________________________________________________

START_TEST(test_strlen) {
  ck_assert_uint_eq(s21_strlen("Всем доброе утро"), strlen("Всем доброе утро"));
  ck_assert_uint_eq(s21_strlen("Ok! Mamba"), strlen("Ok! Mamba"));
  ck_assert_uint_eq(s21_strlen("1"), strlen("1"));
  ck_assert_uint_eq(s21_strlen(""), strlen(""));
  ck_assert_uint_eq(s21_strlen(" "), strlen(" "));
}
END_TEST

//___________________STRCMP________________________________________________

START_TEST(test_strcmp) {
  ck_assert_int_eq(s21_strcmp("Hi! It's School 21.", "Hi! It's School 21."),
                   strcmp("Hi! It's School 21.", "Hi! It's School 21."));
  ck_assert_int_eq(s21_strcmp("Mimimamomo", "Mimimamomo"),
                   strcmp("Mimimamomo", "Mimimamomo"));
  ck_assert_int_eq(s21_strcmp("Go or Kick", "Go OR Kick"),
                   strcmp("Go or Kick", "Go OR Kick"));
  ck_assert_int_eq(s21_strcmp("LOL", "lol"), strcmp("LOL", "lol"));
  ck_assert_int_eq(s21_strcmp("", ""), strcmp("", ""));
  ck_assert_int_eq(s21_strcmp(" ", " "), strcmp(" ", " "));
  ck_assert_int_eq(s21_strcmp("KIIIIICK HIM", "KICK HIM"),
                   strcmp("KIIIIICK HIM", "KICK HIM"));
  ck_assert_int_eq(s21_strcmp("KICK HIM", "KIIIIICK HIM"),
                   strcmp("KICK HIM", "KIIIIICK HIM"));
  ck_assert_int_eq(s21_strcmp("Trulala", " "), strcmp("Trulala", " "));
  ck_assert_int_eq(s21_strcmp("Trulala\0", "Trulala\0"),
                   strcmp("Trulala\0", "Trulala\0"));
  ck_assert_int_eq(s21_strcmp("Trulala\n\0", "Trulala\n\0"),
                   strcmp("Trulala\n\0", "Trulala\n\0"));
  ck_assert_int_eq(s21_strcmp("1\0", "Trulala\0"), strcmp("1\0", "Trulala\0"));
  ck_assert_int_eq(s21_strcmp("\n\0", "\0"), strcmp("\n\0", "\0"));
}
END_TEST

//___________________STRNCMP________________________________________________

START_TEST(test_strncmp) {
  ck_assert_int_eq(s21_strncmp("Hi! It's School 21.", "Hi! It's School 21.", 5),
                   strncmp("Hi! It's School 21.", "Hi! It's School 21.", 5));
  ck_assert_int_eq(s21_strncmp("Mimimamomo", "Mimimamomo", 8),
                   strncmp("Mimimamomo", "Mimimamomo", 8));
  ck_assert_int_eq(s21_strncmp("Go or Kick", "Go OR Kick", 3),
                   strncmp("Go or Kick", "Go OR Kick", 3));
  ck_assert_int_eq(s21_strncmp("LOL", "lol", 10), strncmp("LOL", "lol", 10));
  ck_assert_int_eq(s21_strncmp("", "", 5), strncmp("", "", 5));
  ck_assert_int_eq(s21_strncmp(" ", " ", 0), strncmp(" ", " ", 0));
  ck_assert_int_eq(s21_strncmp("KIIIIICK HIM", "KICK HIM", 20),
                   strncmp("KIIIIICK HIM", "KICK HIM", 20));
  ck_assert_int_eq(s21_strncmp("KICK HIM", "KIIIIICK HIM", 4),
                   strncmp("KICK HIM", "KIIIIICK HIM", 4));
  ck_assert_int_eq(s21_strncmp("KICK HIM", "\0", 4),
                   strncmp("KICK HIM", "\0", 4));
  ck_assert_int_eq(s21_strncmp("Trulala", " ", 1),
                   s21_strncmp("Trulala", " ", 1));
  ck_assert_int_eq(s21_strncmp("Trulala\0", "Trulala\0", 8),
                   s21_strncmp("Trulala\0", "Trulala\0", 8));
  ck_assert_int_eq(s21_strncmp("Trulala\n\0", "Trulala\n\0", 9),
                   s21_strncmp("Trulala\n\0", "Trulala\n\0", 9));
  ck_assert_int_eq(s21_strncmp("1\0", "Trulala\0", 13),
                   s21_strncmp("1\0", "Trulala\0", 13));
  ck_assert_int_eq(s21_strncmp("\n\0", "\0", 2), s21_strncmp("\n\0", "\0", 2));
}
END_TEST

//___________________STRCPY_________________________________________________

START_TEST(test_strcpy) {
  char test1[50] = "Hello. My name is School";
  char test2[50] = "Pika boom check";
  char test3[50] = "Liza is not woman";
  char test4[50] = " ";
  char test5[50] = "Better moon      ";
  ck_assert_str_eq(s21_strcpy(test1, " it's Proverka"),
                   strcpy(test1, " it's Proverka"));
  ck_assert_str_eq(s21_strcpy(test2, "."), strcpy(test2, "."));
  ck_assert_str_eq(s21_strcpy(test3, ""), strcpy(test3, ""));
  ck_assert_str_eq(s21_strcpy(test4, " "), strcpy(test4, " "));
  ck_assert_str_eq(s21_strcpy(test5, "Car"), strcpy(test5, "Car"));
}
END_TEST

//___________________STRNCPY________________________________________________

START_TEST(test_strncpy) {
  char test1[50] = "ProverkaFerma";
  char test2[50] = "We - best team";
  char test3[50] = "";
  char test4[50] = " ";
  char test5[50] = "Black Mamba      ";
  ck_assert_str_eq(s21_strncpy(test1, " GGGICCI", 4),
                   strncpy(test1, "GGGICCI", 4));
  ck_assert_str_eq(s21_strncpy(test2, ".", 2), strncpy(test2, ".", 2));
  ck_assert_str_eq(s21_strncpy(test3, "", 0), strncpy(test3, "", 0));
  ck_assert_str_eq(s21_strncpy(test4, " ", 5), strncpy(test4, " ", 5));
  ck_assert_str_eq(s21_strncpy(test5, "Fake", 2), strncpy(test5, "Fake", 2));
}
END_TEST

//___________________STRCAP________________________________________________

START_TEST(test_strcat) {
  char test1[50] = "00000000000000000000000";
  char test2[50] = "We - best team";
  char test3[50] = "";
  char test4[50] = " ";
  char test5[50] = "Black Mamba      ";
  ck_assert_str_eq(s21_strcat(test1, " GGGICCI"), strcat(test1, "GGGICCI"));
  ck_assert_str_eq(s21_strcat(test2, "."), strcat(test2, "."));
  ck_assert_str_eq(s21_strcat(test3, ""), strcat(test3, ""));
  ck_assert_str_eq(s21_strcat(test4, " "), strcat(test4, " "));
  ck_assert_str_eq(s21_strcat(test5, "Fake"), strcat(test5, "Fake"));
}
END_TEST

//___________________STRNCAT________________________________________________

START_TEST(test_strncat) {
  char test1[50] = "ProverkaFerma";
  char test2[50] = "We - best team";
  char test3[50] = "";
  char test4[50] = " ";
  char test5[50] = "Black Mamba      ";
  ck_assert_str_eq(s21_strncat(test1, " GGGICCI", 4),
                   strncat(test1, "GGGICCI", 4));
  ck_assert_str_eq(s21_strncat(test2, ".", 2), strncat(test2, ".", 2));
  ck_assert_str_eq(s21_strncat(test3, "", 0), strncat(test3, "", 0));
  ck_assert_str_eq(s21_strncat(test4, " ", 5), strncat(test4, " ", 5));
  ck_assert_str_eq(s21_strncat(test5, "Fake", 2), strncat(test5, "Fake", 2));
}
END_TEST

//___________________STRCHR________________________________________________

START_TEST(test_strchr) {
  ck_assert_ptr_eq(s21_strchr("String1", 0), strchr("String1", 0));
  ck_assert_ptr_eq(s21_strchr("", 4), strchr("", 4));
  ck_assert_ptr_eq(s21_strchr("", '\0'), strchr("", '\0'));
  ck_assert_ptr_eq(s21_strchr("Aboba", 98), strchr("Aboba", 98));
  ck_assert_ptr_eq(s21_strchr("Abobuya", 'u'), strchr("Abobuya", 'u'));
  ck_assert_ptr_eq(s21_strchr("Ab o b", 32), strchr("Ab o b", 32));
  ck_assert_ptr_eq(s21_strchr("abob", '\n'), strchr("abob", '\n'));
  ck_assert_ptr_eq(s21_strchr("Aboba", 'q'), strchr("Aboba", 'q'));
}
END_TEST

//___________________STRRCHR________________________________________________

START_TEST(test_strrchr) {
  ck_assert_ptr_eq(s21_strrchr("String1", 0), strrchr("String1", 0));
  ck_assert_ptr_eq(s21_strrchr("", 4), strrchr("", 4));
  ck_assert_ptr_eq(s21_strrchr("", '\0'), strrchr("", '\0'));
  ck_assert_ptr_eq(s21_strrchr("Aaboba", 97), strrchr("Aaboba", 97));
  ck_assert_ptr_eq(s21_strrchr("Abuobuya", 'u'), strrchr("Abuobuya", 'u'));
  ck_assert_ptr_eq(s21_strrchr("Ab o b", 32), strrchr("Ab o b", 32));
  ck_assert_ptr_eq(s21_strrchr("abob", '\n'), strrchr("abob", '\n'));
  ck_assert_ptr_eq(s21_strrchr("Aboba", 'q'), strrchr("Aboba", 'q'));
}
END_TEST

//___________________STRSTR________________________________________________

START_TEST(test_strstr) {
  ck_assert_ptr_eq(s21_strstr("Line one is fine", "line"),
                   strstr("Line one is fine", "line"));
  ck_assert_ptr_eq(s21_strstr("The second one", "."),
                   strstr("The second one", "."));
  ck_assert_ptr_eq(s21_strstr("test3", ""), strstr("test3", ""));
  ck_assert_ptr_eq(s21_strstr("", "cool fake string"),
                   strstr("", "cool fake string"));
  ck_assert_ptr_eq(s21_strstr("normal string", "ol"),
                   strstr("normal string", "ol"));
  ck_assert_ptr_eq(s21_strstr("folder1/folder2/page", "/"),
                   strstr("folder1/folder2/page", "/"));
}
END_TEST

//___________________MEMCHR________________________________________________

START_TEST(test_memchr) {
  ck_assert_ptr_eq(s21_memchr("Abrakadabra", 'A', 5),
                   memchr("Abrakadabra", 'A', 5));
  ck_assert_ptr_eq(s21_memchr("Bugulma", 'l', 5), memchr("Bugulma", 'l', 5));
  ck_assert_ptr_eq(s21_memchr("Lupapuppa", 'b', 5),
                   memchr("Lupapuppa", 'b', 5));
  ck_assert_ptr_eq(s21_memchr("Lupapuppa", ' ', 5),
                   memchr("Lupapuppa", ' ', 5));
  ck_assert_ptr_eq(s21_memchr("GangBang", '\n', 50),
                   memchr("GangBang", '\n', 50));
  ck_assert_ptr_eq(s21_memchr(" ", ' ', 50), memchr(" ", ' ', 50));
  ck_assert_ptr_eq(s21_memchr("123456789", '5', 50),
                   memchr("123456789", '5', 50));
  ck_assert_ptr_eq(s21_memchr(".", '1', 100), memchr(".", '1', 100));
  ck_assert_ptr_eq(s21_memchr("", '5', 0), memchr("", '5', 0));
}
END_TEST

//___________________MEMCPY________________________________________________

START_TEST(test_memcpy) {
  char *src = "Hello";
  char *src2 = "Te\0st";
  char *src3 =
      "00000000000000000000000000000000000000000000000000000000000000000000000";
  char *src4 = "Solnyshko v rykah\n";
  // char *src5 = " ";
  char dest[15];
  char dest2[15];
  char dest3[1000];
  char dest4[10] = "";
  ck_assert_str_eq(s21_memcpy(dest, src, 5), memcpy(dest2, src, 5));
  ck_assert_str_eq(s21_memcpy(dest, src2, 5), memcpy(dest2, src2, 5));
  ck_assert_str_eq(s21_memcpy(dest, src3, 5), memcpy(dest2, src3, 5));
  ck_assert_str_eq(s21_memcpy(dest3, src4, 5), memcpy(dest3, src4, 5));
  // ck_assert_str_eq(s21_memcpy(dest4, src5, 5), memcpy(dest4, src5, 5));
}
END_TEST

//___________________MEMSET________________________________________________

START_TEST(test_memset) {
  char src[10] = "1234567890";
  char src2[10] = "Hello";
  char src3[10] = "000000000";
  char src4[1000] = "\n";
  char src5[1000] = " ";
  ck_assert_mem_eq(s21_memset(src, '1', 5), memset(src, '1', 5), 5);
  ck_assert_mem_eq(s21_memset(src2, '1', 5), memset(src2, '1', 5), 5);
  ck_assert_mem_eq(s21_memset(src3, '\n', 5), memset(src3, '\n', 5), 5);
  ck_assert_mem_eq(s21_memset(src4, ' ', 5), memset(src4, ' ', 5), 5);
  ck_assert_mem_eq(s21_memset(src5, 'a', 5), memset(src5, 'a', 5), 5);
}
END_TEST

//___________________MEMCMP________________________________________________

START_TEST(test_memcmp) {
  ck_assert_int_eq(s21_memcmp("String1", "String1 for comparing", 0),
                   memcmp("String1", "String1 for comparing", 0));
  ck_assert_int_eq(s21_memcmp("String1", "", 4), memcmp("String1", "", 4));
  ck_assert_int_eq(s21_memcmp("", "String1", 4), memcmp("", "String1", 4));
  ck_assert_int_eq(s21_memcmp("LOL", "lol", 10), memcmp("LOL", "lol", 10));
  ck_assert_int_eq(s21_memcmp("", "", 5), memcmp("", "", 5));
  ck_assert_int_eq(s21_memcmp(" ", " ", 4), memcmp(" ", " ", 4));
  ck_assert_int_eq(s21_memcmp("String1", "Strin", 2),
                   memcmp("String1", "Strin", 2));
  ck_assert_int_eq(s21_memcmp("String1", "StrinJOOOOOOOOO", 16),
                   memcmp("String1", "StrinJOOOOOOOOO", 16));
}
END_TEST

//___________________STRTOK________________________________________________

START_TEST(test_strtok) {
  char test1[50] = "Proverka/Ferma";
  char test2[50] = "We - &best team";
  char test3[50] = "";
  char test4[50] = " ";
  char test5[50] = "Black Mamba  . lov.el.y   ";
  ck_assert_pstr_eq(s21_strtok(test1, "/"), strtok(test1, "/"));
  ck_assert_pstr_eq(s21_strtok(test2, "&t"), strtok(test2, "&t"));
  ck_assert_pstr_eq(s21_strtok(test3, ""), strtok(test3, ""));
  ck_assert_pstr_eq(s21_strtok(S21_NULL, ""), strtok(S21_NULL, ""));
  ck_assert_pstr_eq(s21_strtok(test4, " "), strtok(test4, " "));
  ck_assert_pstr_eq(s21_strtok(test5, "."), strtok(test5, "."));
  ck_assert_pstr_eq(s21_strtok(test5, "."), strtok(test5, "."));
}
END_TEST

//___________________STRBRK________________________________________________

START_TEST(test_strpbrk) {
  char *str1 = "London is a capital of GB";
  char *str2 = "Kiev is the mother of Russia cities";
  char *str3 = " ";
  char *str4 = "123455\n";
  char *str5 = "Mazafaka";
  char *str6 = "\0";
  ck_assert_str_eq(s21_strpbrk(str1, "capital"), strpbrk(str1, "capital"));
  ck_assert_str_eq(s21_strpbrk(str2, "abcdefg"), strpbrk(str2, "abcdefg"));
  ck_assert_ptr_eq(s21_strpbrk(str3, "a"), strpbrk(str3, "a"));
  ck_assert_ptr_eq(s21_strpbrk(str4, "v"), strpbrk(str4, "v"));
  ck_assert_ptr_eq(s21_strpbrk(str5, "4"), strpbrk(str5, "4"));
  ck_assert_ptr_eq(s21_strpbrk(str6, "biba\0"), strpbrk(str6, "biba\0"));
}
END_TEST

//___________________________________STRCSPN____________________________________

START_TEST(test_strcspn) {
  ck_assert_uint_eq(s21_strcspn("0123456789", "7"), strcspn("0123456789", "7"));
  ck_assert_uint_eq(s21_strcspn("0123456789", "1"), strcspn("0123456789", "1"));
  ck_assert_uint_eq(s21_strcspn("Kombat batyanya", "1"),
                    strcspn("Kombat batyanya", "1"));
  ck_assert_uint_eq(s21_strcspn("\0", "1"), strcspn("\0", "1"));
  ck_assert_uint_eq(s21_strcspn("\n", "qwerty\n1"), strcspn("\n", "qwerty\n1"));
  ck_assert_uint_eq(s21_strcspn("Britney Spiiiiirz\0", "\0"),
                    strcspn("Britney Spiiiiirz\0", "\0"));
  ck_assert_uint_eq(s21_strcspn("Natalia Oreiro", "1"),
                    strcspn("Natalia Oreiro", "1"));
}
END_TEST

//___________________________________UPPER____________________________________

START_TEST(test_to_upper) {
  char test1[100] = "Pikachu. Gendalf. Kerigan.";
  char test2[10] = "brAt2\n";
  char test3[10] = " ";
  char test4[10] = "12345";
  char test5[10] = "\t\n";

  char *str1 = s21_to_upper(test1);
  char *str2 = s21_to_upper(test2);
  char *str3 = s21_to_upper(test3);
  char *str4 = s21_to_upper(test4);
  char *str5 = s21_to_upper(test5);

  ck_assert_str_eq(str1, "PIKACHU. GENDALF. KERIGAN.");
  ck_assert_str_eq(str2, "BRAT2\n");
  ck_assert_str_eq(str3, " ");
  ck_assert_str_eq(str4, "12345");
  ck_assert_str_eq(str5, "\t\n");

  free(str1);
  free(str2);
  free(str3);
  free(str4);
  free(str5);
}
END_TEST

//___________________________________LOWER____________________________________

START_TEST(test_to_lower) {
  char test1[100] = "PIKACHU. GENDALF. KERIGAN.";
  char test2[10] = "BRAT2\n";
  char test3[10] = " ";
  char test4[10] = "12345";
  char test5[10] = "\t\n";

  char *str1 = s21_to_lower(test1);
  char *str2 = s21_to_lower(test2);
  char *str3 = s21_to_lower(test3);
  char *str4 = s21_to_lower(test4);
  char *str5 = s21_to_lower(test5);

  ck_assert_str_eq(str1, "pikachu. gendalf. kerigan.");
  ck_assert_str_eq(str2, "brat2\n");
  ck_assert_str_eq(str3, " ");
  ck_assert_str_eq(str4, "12345");
  ck_assert_str_eq(str5, "\t\n");

  free(str1);
  free(str2);
  free(str3);
  free(str4);
  free(str5);
}
END_TEST

//___________________________________INSERT____________________________________

START_TEST(test_insert_1) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char s4[] = "hello, hELLO, WORLD!world!";
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = S21_NULL;
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_3) {
  char *s1 = S21_NULL;
  char s3[] = "";
  char *s4 = S21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_4) {
  char s1[30] = "abcdefghij";
  char s3[] = "\'I WAS HERE\'";
  char s4[] = "abc\'I WAS HERE\'defghij";
  s21_size_t num = 3;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = S21_NULL;
  s21_size_t num = 10;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_6) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s4 = S21_NULL;
  s21_size_t num = -1;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_7) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_9) {
  char s1[] = "wtf";
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_10) {
  char s1[] = "";
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s2, s4);
  if (s2) free(s2);
}
END_TEST

//___________________________________TRIM_____________________________________

START_TEST(test_trim_1) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_3) {
  char *s1 = S21_NULL;
  char s3[] = "";
  char *s4 = S21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_4) {
  char s1[30] = "!!!abcdefghij!?!";
  char s3[] = "!?";
  char s4[] = "abcdefghij";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = "abc";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_6) {
  char s1[30] = "hello, world!";
  char s3[] = "?!";
  char *s4 = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_7) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_9) {
  char s1[] = " wtf ";
  char *s3 = S21_NULL;
  char *s4 = "wtf";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_10) {
  char s1[] = " wtf ";
  char *s3 = "";
  char *s4 = "wtf";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

//___________________________________STRERROR_____________________________________

START_TEST(test_strerror) {
  ck_assert_str_eq(s21_strerror(0), strerror(0));
  ck_assert_str_eq(s21_strerror(-11), strerror(-11));
  ck_assert_str_eq(s21_strerror(101), strerror(101));
  ck_assert_str_eq(s21_strerror(106), strerror(106));
  ck_assert_str_eq(s21_strerror(87), strerror(87));
}
END_TEST

//___________________________________SPRINTF_____________________________________

//_______________PRECENT____________________

START_TEST(sprintf_precent) {
  char buff[MAX];
  char buff2[MAX];
  sprintf(buff, "%%");
  s21_sprintf(buff2, "%%");
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_1_percent) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%%Test %d Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_percent) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %d Tes%%%%t %d";
  int val = 012;
  int val2 = 017;
  ck_assert_int_eq(sprintf(str1, str3, val, val2),
                   s21_sprintf(str2, str3, val, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_percent) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Te%%st %d Test %d";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

//__________________%C____________________

START_TEST(sprintf_spec_c) {
  sprintf(buff, "Life is %c long lesson in humility. -James M. Barrie", 'a');
  s21_sprintf(buff2, "Life is %c long lesson in humility. -James M. Barrie",
              'a');
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_char_with_width_and_minus) {
  sprintf(buff, "%-6c", 'X');
  s21_sprintf(buff2, "%-6c", 'X');
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_char_with_width) {
  sprintf(buff, "%6c", 'X');
  s21_sprintf(buff2, "%6c", 'X');
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_test_324) {
  char test_str_1249[50] = "";
  char test_str_1249_1249[50] = "";
  s21_sprintf(test_str_1249, "%-c", 'a');
  sprintf(test_str_1249_1249, "%-c", 'a');
  ck_assert_str_eq(test_str_1249, test_str_1249_1249);
}
END_TEST

START_TEST(sprintf_test_325) {
  char test_str_1250[50] = "";
  char test_str_1250_1250[50] = "";
  s21_sprintf(test_str_1250, "%-c", ' ');
  sprintf(test_str_1250_1250, "%-c", ' ');
  ck_assert_str_eq(test_str_1250, test_str_1250_1250);
}
END_TEST

START_TEST(sprintf_test_326) {
  char test_str_1251[50] = "";
  char test_str_1251_1251[50] = "";
  s21_sprintf(test_str_1251, "%-c", ' ');
  sprintf(test_str_1251_1251, "%-c", ' ');
  ck_assert_str_eq(test_str_1251, test_str_1251_1251);
}
END_TEST

START_TEST(sprintf_test_327) {
  char test_str_1252[50] = "";
  char test_str_1252_1252[50] = "";
  s21_sprintf(test_str_1252, "%-c", '1');
  sprintf(test_str_1252_1252, "%-c", '1');
  ck_assert_str_eq(test_str_1252, test_str_1252_1252);
}
END_TEST

START_TEST(sprintf_test_328) {
  char test_str_1253[50] = "";
  char test_str_1253_1253[50] = "";
  s21_sprintf(test_str_1253, "%c", 'a');
  sprintf(test_str_1253_1253, "%c", 'a');
  ck_assert_str_eq(test_str_1253, test_str_1253_1253);
}
END_TEST

START_TEST(sprintf_test_329) {
  char test_str_1254[50] = "";
  char test_str_1254_1254[50] = "";
  s21_sprintf(test_str_1254, "%c", ' ');
  sprintf(test_str_1254_1254, "%c", ' ');
  ck_assert_str_eq(test_str_1254, test_str_1254_1254);
}
END_TEST

START_TEST(sprintf_test_330) {
  char test_str_1255[50] = "";
  char test_str_1255_1255[50] = "";
  s21_sprintf(test_str_1255, "%c", ' ');
  sprintf(test_str_1255_1255, "%c", ' ');
  ck_assert_str_eq(test_str_1255, test_str_1255_1255);
}
END_TEST

START_TEST(sprintf_test_331) {
  char test_str_1256[50] = "";
  char test_str_1256_1256[50] = "";
  s21_sprintf(test_str_1256, "%c", '1');
  sprintf(test_str_1256_1256, "%c", '1');
  ck_assert_str_eq(test_str_1256, test_str_1256_1256);
}
END_TEST

START_TEST(sprintf_test_332) {
  char test_str_1257[50] = "";
  char test_str_1257_1257[50] = "";
  s21_sprintf(test_str_1257, "%c", 'a');
  sprintf(test_str_1257_1257, "%c", 'a');
  ck_assert_str_eq(test_str_1257, test_str_1257_1257);
}
END_TEST

START_TEST(sprintf_test_333) {
  char test_str_1258[50] = "";
  char test_str_1258_1258[50] = "";
  s21_sprintf(test_str_1258, "%c", ' ');
  sprintf(test_str_1258_1258, "%c", ' ');
  ck_assert_str_eq(test_str_1258, test_str_1258_1258);
}
END_TEST

START_TEST(sprintf_test_334) {
  char test_str_1259[50] = "";
  char test_str_1259_1259[50] = "";
  s21_sprintf(test_str_1259, "%c", ' ');
  sprintf(test_str_1259_1259, "%c", ' ');
  ck_assert_str_eq(test_str_1259, test_str_1259_1259);
}
END_TEST

START_TEST(sprintf_test_335) {
  char test_str_1260[50] = "";
  char test_str_1260_1260[50] = "";
  s21_sprintf(test_str_1260, "%c", '1');
  sprintf(test_str_1260_1260, "%c", '1');
  ck_assert_str_eq(test_str_1260, test_str_1260_1260);
}
END_TEST

START_TEST(sprintf_test_336) {
  char test_str_1261[50] = "";
  char test_str_1261_1261[50] = "";
  s21_sprintf(test_str_1261, "%c", 'a');
  sprintf(test_str_1261_1261, "%c", 'a');
  ck_assert_str_eq(test_str_1261, test_str_1261_1261);
}
END_TEST

START_TEST(sprintf_test_337) {
  char test_str_1262[50] = "";
  char test_str_1262_1262[50] = "";
  s21_sprintf(test_str_1262, "%c", ' ');
  sprintf(test_str_1262_1262, "%c", ' ');
  ck_assert_str_eq(test_str_1262, test_str_1262_1262);
}
END_TEST

START_TEST(sprintf_test_338) {
  char test_str_1263[50] = "";
  char test_str_1263_1263[50] = "";
  s21_sprintf(test_str_1263, "%c", ' ');
  sprintf(test_str_1263_1263, "%c", ' ');
  ck_assert_str_eq(test_str_1263, test_str_1263_1263);
}
END_TEST

START_TEST(sprintf_test_339) {
  char test_str_1264[50] = "";
  char test_str_1264_1264[50] = "";
  s21_sprintf(test_str_1264, "%c", '1');
  sprintf(test_str_1264_1264, "%c", '1');
  ck_assert_str_eq(test_str_1264, test_str_1264_1264);
}
END_TEST

START_TEST(sprintf_test_340) {
  char test_str_1265[50] = "";
  char test_str_1265_1265[50] = "";
  s21_sprintf(test_str_1265, "%c", 'a');
  sprintf(test_str_1265_1265, "%c", 'a');
  ck_assert_str_eq(test_str_1265, test_str_1265_1265);
}
END_TEST

START_TEST(sprintf_test_341) {
  char test_str_1266[50] = "";
  char test_str_1266_1266[50] = "";
  s21_sprintf(test_str_1266, "%c", ' ');
  sprintf(test_str_1266_1266, "%c", ' ');
  ck_assert_str_eq(test_str_1266, test_str_1266_1266);
}
END_TEST

START_TEST(sprintf_test_342) {
  char test_str_1267[50] = "";
  char test_str_1267_1267[50] = "";
  s21_sprintf(test_str_1267, "%c", ' ');
  sprintf(test_str_1267_1267, "%c", ' ');
  ck_assert_str_eq(test_str_1267, test_str_1267_1267);
}
END_TEST

START_TEST(sprintf_test_343) {
  char test_str_1268[50] = "";
  char test_str_1268_1268[50] = "";
  s21_sprintf(test_str_1268, "%c", '1');
  sprintf(test_str_1268_1268, "%c", '1');
  ck_assert_str_eq(test_str_1268, test_str_1268_1268);
}
END_TEST

START_TEST(sprintf_test_344) {
  char test_str_1269[50] = "";
  char test_str_1269_1269[50] = "";
  s21_sprintf(test_str_1269, "%c", 'a');
  sprintf(test_str_1269_1269, "%c", 'a');
  ck_assert_str_eq(test_str_1269, test_str_1269_1269);
}
END_TEST

START_TEST(sprintf_test_345) {
  char test_str_1270[50] = "";
  char test_str_1270_1270[50] = "";
  s21_sprintf(test_str_1270, "%c", ' ');
  sprintf(test_str_1270_1270, "%c", ' ');
  ck_assert_str_eq(test_str_1270, test_str_1270_1270);
}
END_TEST

START_TEST(sprintf_test_346) {
  char test_str_1271[50] = "";
  char test_str_1271_1271[50] = "";
  s21_sprintf(test_str_1271, "%c", ' ');
  sprintf(test_str_1271_1271, "%c", ' ');
  ck_assert_str_eq(test_str_1271, test_str_1271_1271);
}
END_TEST

START_TEST(sprintf_test_347) {
  char test_str_1272[50] = "";
  char test_str_1272_1272[50] = "";
  s21_sprintf(test_str_1272, "%c", '1');
  sprintf(test_str_1272_1272, "%c", '1');
  ck_assert_str_eq(test_str_1272, test_str_1272_1272);
}
END_TEST

START_TEST(sprintf_test_348) {
  char test_str_1273[50] = "";
  char test_str_1273_1273[50] = "";
  s21_sprintf(test_str_1273, "%c", 'a');
  sprintf(test_str_1273_1273, "%c", 'a');
  ck_assert_str_eq(test_str_1273, test_str_1273_1273);
}
END_TEST

START_TEST(sprintf_test_349) {
  char test_str_1274[50] = "";
  char test_str_1274_1274[50] = "";
  s21_sprintf(test_str_1274, "%c", ' ');
  sprintf(test_str_1274_1274, "%c", ' ');
  ck_assert_str_eq(test_str_1274, test_str_1274_1274);
}
END_TEST

START_TEST(sprintf_test_350) {
  char test_str_1275[50] = "";
  char test_str_1275_1275[50] = "";
  s21_sprintf(test_str_1275, "%c", ' ');
  sprintf(test_str_1275_1275, "%c", ' ');
  ck_assert_str_eq(test_str_1275, test_str_1275_1275);
}
END_TEST

START_TEST(sprintf_test_351) {
  char test_str_1276[50] = "";
  char test_str_1276_1276[50] = "";
  s21_sprintf(test_str_1276, "%c", '1');
  sprintf(test_str_1276_1276, "%c", '1');
  ck_assert_str_eq(test_str_1276, test_str_1276_1276);
}
END_TEST

START_TEST(sprintf_test_352) {
  char test_str_1277[50] = "";
  char test_str_1277_1277[50] = "";
  s21_sprintf(test_str_1277, "%c", 'a');
  sprintf(test_str_1277_1277, "%c", 'a');
  ck_assert_str_eq(test_str_1277, test_str_1277_1277);
}
END_TEST

START_TEST(sprintf_test_353) {
  char test_str_1278[50] = "";
  char test_str_1278_1278[50] = "";
  s21_sprintf(test_str_1278, "%c", ' ');
  sprintf(test_str_1278_1278, "%c", ' ');
  ck_assert_str_eq(test_str_1278, test_str_1278_1278);
}
END_TEST

START_TEST(sprintf_test_354) {
  char test_str_1279[50] = "";
  char test_str_1279_1279[50] = "";
  s21_sprintf(test_str_1279, "%c", ' ');
  sprintf(test_str_1279_1279, "%c", ' ');
  ck_assert_str_eq(test_str_1279, test_str_1279_1279);
}
END_TEST

START_TEST(sprintf_test_355) {
  char test_str_1280[50] = "";
  char test_str_1280_1280[50] = "";
  s21_sprintf(test_str_1280, "%c", '1');
  sprintf(test_str_1280_1280, "%c", '1');
  ck_assert_str_eq(test_str_1280, test_str_1280_1280);
}
END_TEST

START_TEST(sprintf_test_356) {
  char test_str_1281[50] = "";
  char test_str_1281_1281[50] = "";
  s21_sprintf(test_str_1281, "%c", 'a');
  sprintf(test_str_1281_1281, "%c", 'a');
  ck_assert_str_eq(test_str_1281, test_str_1281_1281);
}
END_TEST

START_TEST(sprintf_test_357) {
  char test_str_1282[50] = "";
  char test_str_1282_1282[50] = "";
  s21_sprintf(test_str_1282, "%c", ' ');
  sprintf(test_str_1282_1282, "%c", ' ');
  ck_assert_str_eq(test_str_1282, test_str_1282_1282);
}
END_TEST

START_TEST(sprintf_test_358) {
  char test_str_1283[50] = "";
  char test_str_1283_1283[50] = "";
  s21_sprintf(test_str_1283, "%c", ' ');
  sprintf(test_str_1283_1283, "%c", ' ');
  ck_assert_str_eq(test_str_1283, test_str_1283_1283);
}
END_TEST

START_TEST(sprintf_test_359) {
  char test_str_1284[50] = "";
  char test_str_1284_1284[50] = "";
  s21_sprintf(test_str_1284, "%c", '1');
  sprintf(test_str_1284_1284, "%c", '1');
  ck_assert_str_eq(test_str_1284, test_str_1284_1284);
}
END_TEST

START_TEST(sprintf_test_360) {
  char test_str_1285[50] = "";
  char test_str_1285_1285[50] = "";
  s21_sprintf(test_str_1285, "%-10c", 'a');
  sprintf(test_str_1285_1285, "%-10c", 'a');
  ck_assert_str_eq(test_str_1285, test_str_1285_1285);
}
END_TEST

START_TEST(sprintf_test_361) {
  char test_str_1286[50] = "";
  char test_str_1286_1286[50] = "";
  s21_sprintf(test_str_1286, "%-10c", ' ');
  sprintf(test_str_1286_1286, "%-10c", ' ');
  ck_assert_str_eq(test_str_1286, test_str_1286_1286);
}
END_TEST

START_TEST(sprintf_test_362) {
  char test_str_1287[50] = "";
  char test_str_1287_1287[50] = "";
  s21_sprintf(test_str_1287, "%-10c", ' ');
  sprintf(test_str_1287_1287, "%-10c", ' ');
  ck_assert_str_eq(test_str_1287, test_str_1287_1287);
}
END_TEST

START_TEST(sprintf_test_363) {
  char test_str_1288[50] = "";
  char test_str_1288_1288[50] = "";
  s21_sprintf(test_str_1288, "%-10c", '1');
  sprintf(test_str_1288_1288, "%-10c", '1');
  ck_assert_str_eq(test_str_1288, test_str_1288_1288);
}
END_TEST

START_TEST(sprintf_1_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 9;
  int b = 10;
  int c = 17;
  int d = 66;
  int e = 124;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = -6;
  int b = -10;
  int c = -17;
  int d = -66;
  int e = -124;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  char a = 0;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%-010c Test %- 10c Test %-lc";
  int a = 74;
  unsigned long int b = 74;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b),
                   s21_sprintf(str2, str3, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%6.4c Test %-6.4c Test %4.10lc Test %-4.10lc Test %-0lc";
  int a = 10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%6.4c Test %-6.4c Test %4.10lc Test %-4.10lc Test %-0lc";
  int a = -10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  ck_assert_int_eq(sprintf(str1, str3, '\n', '\0', '\0', '\0', 'c'),
                   s21_sprintf(str2, str3, '\n', '\0', '\0', '\0', 'c'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  ck_assert_int_eq(sprintf(str1, str3, 'b', '4', '#', '@', '\0'),
                   s21_sprintf(str2, str3, 'b', '4', '#', '@', '\0'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  ck_assert_int_eq(sprintf(str1, str3, 'Y', 'G', 123, '\0', 'J'),
                   s21_sprintf(str2, str3, 'Y', 'G', 123, '\0', 'J'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c Test %-.7c Test %- 050c Test %- 54c Test %-0188c";
  int a = 45;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %lc Test %hc";
  int a = 3;
  unsigned long int b = 103;
  unsigned short e = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, b, e),
                   s21_sprintf(str2, str3, a, b, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

//___________________WITHOUT_SPEC________________

// START_TEST(sprintf_char1) {
//   char str[MAX] = "Life is trying things to see if they work. -Ray Bradbury";
//   sprintf(buff, str, " ");
//   s21_sprintf(buff2, str, " ");
//   ck_assert_str_eq(buff, buff2);
// }
// END_TEST

//___________________%D________________

START_TEST(sprintf_spec_d1) {
  int probs = 99;
  sprintf(buff, "I've got %d problems", probs);
  s21_sprintf(buff2, "I've got %d problems", probs);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_d2) {
  int probs = -99;
  sprintf(buff, "I've got %d problems", probs);
  s21_sprintf(buff2, "I've got %d problems", probs);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_d_space2) {
  int probs = -99;
  sprintf(buff, "I've got % d problems", probs);
  s21_sprintf(buff2, "I've got % d problems", probs);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_d_space1) {
  int probs = 99;
  sprintf(buff, "I've got % d problems", probs);
  s21_sprintf(buff2, "I've got % d problems", probs);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_d_plus2) {
  int probs = -99;
  sprintf(buff, "I've got %+d problems", probs);
  s21_sprintf(buff2, "I've got %+d problems", probs);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_d_plus1) {
  int probs = 99;
  sprintf(buff, "I've got %+d problems", probs);
  s21_sprintf(buff2, "I've got %+d problems", probs);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_int_minus_zero) {
  int ans = -0;
  sprintf(buff, "%d", ans);
  s21_sprintf(buff2, "%d", ans);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_int_precision_bigger_with) {
  int ans = 54;
  sprintf(buff, "%1.23d", ans);
  s21_sprintf(buff2, "%1.23d", ans);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_h_for_int) {
  short ans = 54;
  sprintf(buff, "%hd", ans);
  s21_sprintf(buff2, "%hd", ans);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_test_1) {
  char test_str_1[50] = "";
  char test_str_1_1[50] = "";
  s21_sprintf(test_str_1, "%-d", 0);
  sprintf(test_str_1_1, "%-d", 0);
  ck_assert_str_eq(test_str_1, test_str_1_1);
}
END_TEST

START_TEST(sprintf_test_2) {
  char test_str_2[50] = "";
  char test_str_2_2[50] = "";
  s21_sprintf(test_str_2, "%-d", 1);
  sprintf(test_str_2_2, "%-d", 1);
  ck_assert_str_eq(test_str_2, test_str_2_2);
}
END_TEST

START_TEST(sprintf_test_3) {
  char test_str_3[50] = "";
  char test_str_3_3[50] = "";
  s21_sprintf(test_str_3, "%-d", 10);
  sprintf(test_str_3_3, "%-d", 10);
  ck_assert_str_eq(test_str_3, test_str_3_3);
}
END_TEST

START_TEST(sprintf_test_4) {
  char test_str_4[50] = "";
  char test_str_4_4[50] = "";
  s21_sprintf(test_str_4, "%-d", 123456);
  sprintf(test_str_4_4, "%-d", 123456);
  ck_assert_str_eq(test_str_4, test_str_4_4);
}
END_TEST

START_TEST(sprintf_test_5) {
  char test_str_5[50] = "";
  char test_str_5_5[50] = "";
  s21_sprintf(test_str_5, "%-d", -67890123);
  sprintf(test_str_5_5, "%-d", -67890123);
  ck_assert_str_eq(test_str_5, test_str_5_5);
}
END_TEST

START_TEST(sprintf_test_6) {
  char test_str_6[50] = "";
  char test_str_6_6[50] = "";
  s21_sprintf(test_str_6, "%-d", 4343);
  sprintf(test_str_6_6, "%-d", 4343);
  ck_assert_str_eq(test_str_6, test_str_6_6);
}
END_TEST

START_TEST(sprintf_test_7) {
  char test_str_7[50] = "";
  char test_str_7_7[50] = "";
  s21_sprintf(test_str_7, "%-d", -1);
  sprintf(test_str_7_7, "%-d", -1);
  ck_assert_str_eq(test_str_7, test_str_7_7);
}
END_TEST

START_TEST(sprintf_test_8) {
  char test_str_8[50] = "";
  char test_str_8_8[50] = "";
  s21_sprintf(test_str_8, "%-d", -10);
  sprintf(test_str_8_8, "%-d", -10);
  ck_assert_str_eq(test_str_8, test_str_8_8);
}
END_TEST

START_TEST(sprintf_test_9) {
  char test_str_9[50] = "";
  char test_str_9_9[50] = "";
  s21_sprintf(test_str_9, "%-d", 43);
  sprintf(test_str_9_9, "%-d", 43);
  ck_assert_str_eq(test_str_9, test_str_9_9);
}
END_TEST

START_TEST(sprintf_test_28) {
  char test_str_55[50] = "";
  char test_str_55_55[50] = "";
  s21_sprintf(test_str_55, "%+d", 0);
  sprintf(test_str_55_55, "%+d", 0);
  ck_assert_str_eq(test_str_55, test_str_55_55);
}
END_TEST

START_TEST(sprintf_test_29) {
  char test_str_56[50] = "";
  char test_str_56_56[50] = "";
  s21_sprintf(test_str_56, "%+d", 1);
  sprintf(test_str_56_56, "%+d", 1);
  ck_assert_str_eq(test_str_56, test_str_56_56);
}
END_TEST

START_TEST(sprintf_test_30) {
  char test_str_57[50] = "";
  char test_str_57_57[50] = "";
  s21_sprintf(test_str_57, "%+d", 10);
  sprintf(test_str_57_57, "%+d", 10);
  ck_assert_str_eq(test_str_57, test_str_57_57);
}
END_TEST

START_TEST(sprintf_test_31) {
  char test_str_58[50] = "";
  char test_str_58_58[50] = "";
  s21_sprintf(test_str_58, "%+d", 123456);
  sprintf(test_str_58_58, "%+d", 123456);
  ck_assert_str_eq(test_str_58, test_str_58_58);
}
END_TEST

START_TEST(sprintf_test_32) {
  char test_str_59[50] = "";
  char test_str_59_59[50] = "";
  s21_sprintf(test_str_59, "%+d", -67890123);
  sprintf(test_str_59_59, "%+d", -67890123);
  ck_assert_str_eq(test_str_59, test_str_59_59);
}
END_TEST

START_TEST(sprintf_test_33) {
  char test_str_60[50] = "";
  char test_str_60_60[50] = "";
  s21_sprintf(test_str_60, "%+d", 4343);
  sprintf(test_str_60_60, "%+d", 4343);
  ck_assert_str_eq(test_str_60, test_str_60_60);
}
END_TEST

START_TEST(sprintf_test_34) {
  char test_str_61[50] = "";
  char test_str_61_61[50] = "";
  s21_sprintf(test_str_61, "%+d", -1);
  sprintf(test_str_61_61, "%+d", -1);
  ck_assert_str_eq(test_str_61, test_str_61_61);
}
END_TEST

START_TEST(sprintf_test_35) {
  char test_str_62[50] = "";
  char test_str_62_62[50] = "";
  s21_sprintf(test_str_62, "%+d", -10);
  sprintf(test_str_62_62, "%+d", -10);
  ck_assert_str_eq(test_str_62, test_str_62_62);
}
END_TEST

START_TEST(sprintf_test_36) {
  char test_str_63[50] = "";
  char test_str_63_63[50] = "";
  s21_sprintf(test_str_63, "%+d", 43);
  sprintf(test_str_63_63, "%+d", 43);
  ck_assert_str_eq(test_str_63, test_str_63_63);
}
END_TEST

START_TEST(sprintf_test_56) {
  char test_str_110[50] = "";
  char test_str_110_110[50] = "";
  s21_sprintf(test_str_110, "% d", 1);
  sprintf(test_str_110_110, "% d", 1);
  ck_assert_str_eq(test_str_110, test_str_110_110);
}
END_TEST

START_TEST(sprintf_test_57) {
  char test_str_111[50] = "";
  char test_str_111_111[50] = "";
  s21_sprintf(test_str_111, "% d", 10);
  sprintf(test_str_111_111, "% d", 10);
  ck_assert_str_eq(test_str_111, test_str_111_111);
}
END_TEST

START_TEST(sprintf_test_58) {
  char test_str_112[50] = "";
  char test_str_112_112[50] = "";
  s21_sprintf(test_str_112, "% d", 123456);
  sprintf(test_str_112_112, "% d", 123456);
  ck_assert_str_eq(test_str_112, test_str_112_112);
}
END_TEST

START_TEST(sprintf_test_59) {
  char test_str_113[50] = "";
  char test_str_113_113[50] = "";
  s21_sprintf(test_str_113, "% d", -67890123);
  sprintf(test_str_113_113, "% d", -67890123);
  ck_assert_str_eq(test_str_113, test_str_113_113);
}
END_TEST

START_TEST(sprintf_test_60) {
  char test_str_114[50] = "";
  char test_str_114_114[50] = "";
  s21_sprintf(test_str_114, "% d", 4343);
  sprintf(test_str_114_114, "% d", 4343);
  ck_assert_str_eq(test_str_114, test_str_114_114);
}
END_TEST

START_TEST(sprintf_test_61) {
  char test_str_115[50] = "";
  char test_str_115_115[50] = "";
  s21_sprintf(test_str_115, "% d", -1);
  sprintf(test_str_115_115, "% d", -1);
  ck_assert_str_eq(test_str_115, test_str_115_115);
}
END_TEST

START_TEST(sprintf_test_62) {
  char test_str_116[50] = "";
  char test_str_116_116[50] = "";
  s21_sprintf(test_str_116, "% d", -10);
  sprintf(test_str_116_116, "% d", -10);
  ck_assert_str_eq(test_str_116, test_str_116_116);
}
END_TEST

START_TEST(sprintf_test_81) {
  char test_str_163[50] = "";
  char test_str_163_163[50] = "";
  s21_sprintf(test_str_163, "%d", 0);
  sprintf(test_str_163_163, "%d", 0);
  ck_assert_str_eq(test_str_163, test_str_163_163);
}
END_TEST

START_TEST(sprintf_test_82) {
  char test_str_164[50] = "";
  char test_str_164_164[50] = "";
  s21_sprintf(test_str_164, "%d", 1);
  sprintf(test_str_164_164, "%d", 1);
  ck_assert_str_eq(test_str_164, test_str_164_164);
}
END_TEST

START_TEST(sprintf_test_83) {
  char test_str_165[50] = "";
  char test_str_165_165[50] = "";
  s21_sprintf(test_str_165, "%d", 10);
  sprintf(test_str_165_165, "%d", 10);
  ck_assert_str_eq(test_str_165, test_str_165_165);
}
END_TEST

START_TEST(sprintf_test_84) {
  char test_str_166[50] = "";
  char test_str_166_166[50] = "";
  s21_sprintf(test_str_166, "%d", 123456);
  sprintf(test_str_166_166, "%d", 123456);
  ck_assert_str_eq(test_str_166, test_str_166_166);
}
END_TEST

START_TEST(sprintf_test_85) {
  char test_str_167[50] = "";
  char test_str_167_167[50] = "";
  s21_sprintf(test_str_167, "%d", -67890123);
  sprintf(test_str_167_167, "%d", -67890123);
  ck_assert_str_eq(test_str_167, test_str_167_167);
}
END_TEST

START_TEST(sprintf_test_86) {
  char test_str_168[50] = "";
  char test_str_168_168[50] = "";
  s21_sprintf(test_str_168, "%d", 4343);
  sprintf(test_str_168_168, "%d", 4343);
  ck_assert_str_eq(test_str_168, test_str_168_168);
}
END_TEST

START_TEST(sprintf_test_87) {
  char test_str_169[50] = "";
  char test_str_169_169[50] = "";
  s21_sprintf(test_str_169, "%d", -1);
  sprintf(test_str_169_169, "%d", -1);
  ck_assert_str_eq(test_str_169, test_str_169_169);
}
END_TEST

START_TEST(sprintf_test_88) {
  char test_str_170[50] = "";
  char test_str_170_170[50] = "";
  s21_sprintf(test_str_170, "%d", -10);
  sprintf(test_str_170_170, "%d", -10);
  ck_assert_str_eq(test_str_170, test_str_170_170);
}
END_TEST

START_TEST(sprintf_test_208) {
  char test_str_217[50] = "";
  char test_str_217_217[50] = "";
  s21_sprintf(test_str_217, "%0d", 0);
  sprintf(test_str_217_217, "%0d", 0);
  ck_assert_str_eq(test_str_217, test_str_217_217);
}
END_TEST

START_TEST(sprintf_test_209) {
  char test_str_218[50] = "";
  char test_str_218_218[50] = "";
  s21_sprintf(test_str_218, "%0d", 1);
  sprintf(test_str_218_218, "%0d", 1);
  ck_assert_str_eq(test_str_218, test_str_218_218);
}
END_TEST

START_TEST(sprintf_test_210) {
  char test_str_219[50] = "";
  char test_str_219_219[50] = "";
  s21_sprintf(test_str_219, "%0d", 10);
  sprintf(test_str_219_219, "%0d", 10);
  ck_assert_str_eq(test_str_219, test_str_219_219);
}
END_TEST

START_TEST(sprintf_test_211) {
  char test_str_220[50] = "";
  char test_str_220_220[50] = "";
  s21_sprintf(test_str_220, "%0d", 123456);
  sprintf(test_str_220_220, "%0d", 123456);
  ck_assert_str_eq(test_str_220, test_str_220_220);
}
END_TEST

START_TEST(sprintf_test_212) {
  char test_str_221[50] = "";
  char test_str_221_221[50] = "";
  s21_sprintf(test_str_221, "%0d", -67890123);
  sprintf(test_str_221_221, "%0d", -67890123);
  ck_assert_str_eq(test_str_221, test_str_221_221);
}
END_TEST

START_TEST(sprintf_test_213) {
  char test_str_222[50] = "";
  char test_str_222_222[50] = "";
  s21_sprintf(test_str_222, "%0d", 4343);
  sprintf(test_str_222_222, "%0d", 4343);
  ck_assert_str_eq(test_str_222, test_str_222_222);
}
END_TEST

START_TEST(sprintf_test_214) {
  char test_str_223[50] = "";
  char test_str_223_223[50] = "";
  s21_sprintf(test_str_223, "%0d", -1);
  sprintf(test_str_223_223, "%0d", -1);
  ck_assert_str_eq(test_str_223, test_str_223_223);
}
END_TEST

START_TEST(sprintf_test_215) {
  char test_str_224[50] = "";
  char test_str_224_224[50] = "";
  s21_sprintf(test_str_224, "%0d", -10);
  sprintf(test_str_224_224, "%0d", -10);
  ck_assert_str_eq(test_str_224, test_str_224_224);
}
END_TEST

START_TEST(sprintf_test_216) {
  char test_str_225[50] = "";
  char test_str_225_225[50] = "";
  s21_sprintf(test_str_225, "%0d", 43);
  sprintf(test_str_225_225, "%0d", 43);
  ck_assert_str_eq(test_str_225, test_str_225_225);
}
END_TEST

START_TEST(sprintf_test_247) {
  char test_str_1135[50] = "";
  char test_str_1135_1135[50] = "";
  s21_sprintf(test_str_1135, "%d", 0);
  sprintf(test_str_1135_1135, "%d", 0);
  ck_assert_str_eq(test_str_1135, test_str_1135_1135);
}
END_TEST

START_TEST(sprintf_test_248) {
  char test_str_1136[50] = "";
  char test_str_1136_1136[50] = "";
  s21_sprintf(test_str_1136, "%d", 1);
  sprintf(test_str_1136_1136, "%d", 1);
  ck_assert_str_eq(test_str_1136, test_str_1136_1136);
}
END_TEST

START_TEST(sprintf_test_249) {
  char test_str_1137[50] = "";
  char test_str_1137_1137[50] = "";
  s21_sprintf(test_str_1137, "%d", 10);
  sprintf(test_str_1137_1137, "%d", 10);
  ck_assert_str_eq(test_str_1137, test_str_1137_1137);
}
END_TEST

START_TEST(sprintf_test_250) {
  char test_str_1138[50] = "";
  char test_str_1138_1138[50] = "";
  s21_sprintf(test_str_1138, "%d", 123456);
  sprintf(test_str_1138_1138, "%d", 123456);
  ck_assert_str_eq(test_str_1138, test_str_1138_1138);
}
END_TEST

START_TEST(sprintf_test_251) {
  char test_str_1139[50] = "";
  char test_str_1139_1139[50] = "";
  s21_sprintf(test_str_1139, "%d", -678901);
  sprintf(test_str_1139_1139, "%d", -678901);
  ck_assert_str_eq(test_str_1139, test_str_1139_1139);
}
END_TEST

START_TEST(sprintf_test_252) {
  char test_str_1140[50] = "";
  char test_str_1140_1140[50] = "";
  s21_sprintf(test_str_1140, "%d", 4343);
  sprintf(test_str_1140_1140, "%d", 4343);
  ck_assert_str_eq(test_str_1140, test_str_1140_1140);
}
END_TEST

START_TEST(sprintf_test_253) {
  char test_str_1141[50] = "";
  char test_str_1141_1141[50] = "";
  s21_sprintf(test_str_1141, "%d", -1);
  sprintf(test_str_1141_1141, "%d", -1);
  ck_assert_str_eq(test_str_1141, test_str_1141_1141);
}
END_TEST

START_TEST(sprintf_test_254) {
  char test_str_1142[50] = "";
  char test_str_1142_1142[50] = "";
  s21_sprintf(test_str_1142, "%d", -10);
  sprintf(test_str_1142_1142, "%d", -10);
  ck_assert_str_eq(test_str_1142, test_str_1142_1142);
}
END_TEST

START_TEST(sprintf_test_255) {
  char test_str_1143[50] = "";
  char test_str_1143_1143[50] = "";
  s21_sprintf(test_str_1143, "%d", 43);
  sprintf(test_str_1143_1143, "%d", 43);
  ck_assert_str_eq(test_str_1143, test_str_1143_1143);
}
END_TEST

START_TEST(sprintf_test_265) {
  char test_str_1162[50] = "";
  char test_str_1162_1162[50] = "";
  s21_sprintf(test_str_1162, "%d", 0);
  sprintf(test_str_1162_1162, "%d", 0);
  ck_assert_str_eq(test_str_1162, test_str_1162_1162);
}
END_TEST

START_TEST(sprintf_test_266) {
  char test_str_1163[50] = "";
  char test_str_1163_1163[50] = "";
  s21_sprintf(test_str_1163, "%d", 1);
  sprintf(test_str_1163_1163, "%d", 1);
  ck_assert_str_eq(test_str_1163, test_str_1163_1163);
}
END_TEST

START_TEST(sprintf_test_267) {
  char test_str_1164[50] = "";
  char test_str_1164_1164[50] = "";
  s21_sprintf(test_str_1164, "%d", 10);
  sprintf(test_str_1164_1164, "%d", 10);
  ck_assert_str_eq(test_str_1164, test_str_1164_1164);
}
END_TEST

START_TEST(sprintf_test_268) {
  char test_str_1165[50] = "";
  char test_str_1165_1165[50] = "";
  s21_sprintf(test_str_1165, "%ld", 12111111111113456);
  sprintf(test_str_1165_1165, "%ld", 12111111111113456);
  ck_assert_str_eq(test_str_1165, test_str_1165_1165);
}
END_TEST

START_TEST(sprintf_test_269) {
  char test_str_1166[50] = "";
  char test_str_1166_1166[50] = "";
  s21_sprintf(test_str_1166, "%d", -678901);
  sprintf(test_str_1166_1166, "%d", -678901);
  ck_assert_str_eq(test_str_1166, test_str_1166_1166);
}
END_TEST

START_TEST(sprintf_test_270) {
  char test_str_1167[50] = "";
  char test_str_1167_1167[50] = "";
  s21_sprintf(test_str_1167, "%d", 4343);
  sprintf(test_str_1167_1167, "%d", 4343);
  ck_assert_str_eq(test_str_1167, test_str_1167_1167);
}
END_TEST

START_TEST(sprintf_test_271) {
  char test_str_1168[50] = "";
  char test_str_1168_1168[50] = "";
  s21_sprintf(test_str_1168, "%d", -1);
  sprintf(test_str_1168_1168, "%d", -1);
  ck_assert_str_eq(test_str_1168, test_str_1168_1168);
}
END_TEST

START_TEST(sprintf_test_272) {
  char test_str_1169[50] = "";
  char test_str_1169_1169[50] = "";
  s21_sprintf(test_str_1169, "%d", -10);
  sprintf(test_str_1169_1169, "%d", -10);
  ck_assert_str_eq(test_str_1169, test_str_1169_1169);
}
END_TEST

START_TEST(sprintf_test_273) {
  char test_str_1170[50] = "";
  char test_str_1170_1170[50] = "";
  s21_sprintf(test_str_1170, "%d", 43);
  sprintf(test_str_1170_1170, "%d", 43);
  ck_assert_str_eq(test_str_1170, test_str_1170_1170);
}
END_TEST

START_TEST(sprintf_test_63) {
  char test_str_117[50] = "";
  char test_str_117_117[50] = "";
  s21_sprintf(test_str_117, "% d", 43);
  sprintf(test_str_117_117, "% d", 43);
  ck_assert_str_eq(test_str_117, test_str_117_117);
}
END_TEST

START_TEST(sprintf_test_89) {
  char test_str_171[50] = "";
  char test_str_171_171[50] = "";
  s21_sprintf(test_str_171, "%d", 43);
  sprintf(test_str_171_171, "%d", 43);
  ck_assert_str_eq(test_str_171, test_str_171_171);
}
END_TEST

START_TEST(sprintf_1_signed_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %d Test";
  int val = -12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %d Test %d";
  int val = 012;
  int val2 = -017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_signed) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %d Test";
  int val = -12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %d Test %d";
  int val = 012;
  int val2 = -017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %d Test %d";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%ld Test %ld Test %hd GOD %hd";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  short int val3 = 22600;
  short val4 = -120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%3d Test %5d Test %10d";
  int val = -3015;
  int val2 = -11234;
  int val3 = -99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5d Test %.24d Test %3.d TEST %.d %.6d";
  int val = -3015;
  int val2 = -999;
  int val3 = -99;
  int val4 = -38;
  int val5 = -100;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5d Test %-.8d Test %-7d TEST %-.d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %0.d Test %0.0d TEST %0d GOD %.d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d Test %+3.d Test %+5.7d TEST %+10d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_10_signed) {
//   char str1[200];
//   char str2[200];
//   char *str3 = "%d Test %3.d Test %5.7d TEST %10d %+d %-d %+d %.d % .d";
//   int val = 0;
//   ck_assert_int_eq(
//       sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
//       s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
//                   val));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_11_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "% d Test % 3.d Test % 5.7d TEST % 10d GOD %.d";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d Test %+3.d Test %+5.7d TEST %+10d GOD %+.d";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %06d Test %05.7d TEST %0.7d Oof %0.d";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_signed) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%d";
  int val = 12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_signed) {
  char str1[1024] = "";
  char str2[1024] = "";
  int val = -75;
  sprintf(str1, "Hello %d %23d", val, val);  // нет нулей перед числом(бонус)
  s21_sprintf(str2, "Hello %d %23d", val, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_signed) {
  char str1[300];
  char str2[300];
  char *str3 = "%ld Test %ld Test %hd GOD %hd tt %d tt %d";
  long int val = LONG_MAX;
  long val2 = LONG_MIN;
  short int val3 = SHRT_MAX;
  short val4 = SHRT_MIN;
  int val5 = INT_MAX;
  int val6 = INT_MIN;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5, val6),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%- d Test %- 15d sdasda %- 15d sdsad %- d";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_width) {
  int num = 78;
  sprintf(buff, "%6d", num);
  s21_sprintf(buff2, "%6d", num);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_width_2) {
  int num = 123;
  sprintf(buff, "%3d", num);
  s21_sprintf(buff2, "%3d", num);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_width_neg) {
  char *str = "stroka";
  sprintf(buff, "%6s", str);
  s21_sprintf(buff2, "%6s", str);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_flag_minus) {
  int min = 5;
  sprintf(buff, "%-6d", min);
  s21_sprintf(buff2, "%-6d", min);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_flag_procent) {
  int space = 8;
  sprintf(buff, "%% %d", space);
  s21_sprintf(buff2, "%% %d", space);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_flag_space) {
  int space = 8;
  sprintf(buff, "%d", space);
  s21_sprintf(buff2, "%d", space);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_flag_zero) {
  int zero = 9;
  sprintf(buff, "%06d", zero);
  s21_sprintf(buff2, "%06d", zero);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_flag_plus) {
  int plus = 21;
  sprintf(buff, "%+d", plus);
  s21_sprintf(buff2, "%+d", plus);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_char) {
  sprintf(buff, "%c", 'X');
  s21_sprintf(buff2, "%c", 'X');
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_prec) {
  int ans = 42;
  sprintf(buff, "%.6d", ans);
  s21_sprintf(buff2, "%.6d", ans);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

//___________________%U________________

START_TEST(sprintf_spec_u) {
  unsigned int ans = 42;
  sprintf(buff, "%u", ans);
  s21_sprintf(buff2, "%u", ans);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_u_neg) {
  int ans = -42;
  ck_assert_int_eq(sprintf(buff, "%u", ans), s21_sprintf(buff2, "%u", ans));
}
END_TEST

START_TEST(sprintf_1_unsigned) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %u Test";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test %u Test %u";
  unsigned int val = 012;
  unsigned int val2 = 017;
  unsigned int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test %u Test %u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_4_unsigned) {
//   char str1[100];
//   char str2[100];
//   char *str3 = "%lu Test %lu Test %hu GOD %hu";
//   long unsigned int val = 3088675747373646;
//   long unsigned val2 = 33030030303;
//   unsigned short val3 = 22600;
//   unsigned short val4 = 120;
//   ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
//                    s21_sprintf(str2, str3, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_5_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%3u Test %5u Test %10u";
  unsigned int val = 3015;
  unsigned int val2 = 01234;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5u Test %.23u Test %3.u TEST %.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5u Test %-.8u Test %-7u TEST %-.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Test %0.u Test %0.0u TEST %0u GOD %.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  unsigned int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Test %+3.u Test %+5.7u TEST %+10u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "% u Test % 3.u Test % 5.7u TEST % 10u GOD %.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Test %+3.u Test %+5.7u TEST %+10u GOD %+.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Test %06u Test %05.7u TEST %0.7u Ouf %0.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lu";
  unsigned long int val = ULONG_MAX;
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%- u Test %- 15u sdasda %- 15u sdsad %- u";
  unsigned int val = -3231;
  unsigned int val2 = -3231;
  unsigned int val3 = 3231;
  unsigned int val4 = 3231;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_uint_precision_bigger_with) {
  int ans = 54;
  sprintf(buff, "%1.25u", ans);
  s21_sprintf(buff2, "%1.25u", ans);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_string_with_width_and_minus) {
  sprintf(buff, "%-s", "string");
  s21_sprintf(buff2, "%-s", "string");
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_string_with_width_space) {
  sprintf(buff, "%10s", "string");
  s21_sprintf(buff2, "%10s", "string");
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_test_80) {
  char test_str_144[50] = "";
  char test_str_144_144[50] = "";
  s21_sprintf(test_str_144, "%u", 43);
  sprintf(test_str_144_144, "%u", 43);
  ck_assert_str_eq(test_str_144, test_str_144_144);
}
END_TEST

START_TEST(sprintf_test_77) {
  char test_str_141[50] = "";
  char test_str_141_141[50] = "";
  s21_sprintf(test_str_141, "%u", 4343);
  sprintf(test_str_141_141, "%u", 4343);
  ck_assert_str_eq(test_str_141, test_str_141_141);
}
END_TEST

START_TEST(sprintf_test_73) {
  char test_str_136[50] = "";
  char test_str_136_136[50] = "";
  s21_sprintf(test_str_136, "%u", 0);
  sprintf(test_str_136_136, "%u", 0);
  ck_assert_str_eq(test_str_136, test_str_136_136);
}
END_TEST

START_TEST(sprintf_test_74) {
  char test_str_137[50] = "";
  char test_str_137_137[50] = "";
  s21_sprintf(test_str_137, "%u", 1);
  sprintf(test_str_137_137, "%u", 1);
  ck_assert_str_eq(test_str_137, test_str_137_137);
}
END_TEST

START_TEST(sprintf_test_75) {
  char test_str_138[50] = "";
  char test_str_138_138[50] = "";
  s21_sprintf(test_str_138, "%u", 10);
  sprintf(test_str_138_138, "%u", 10);
  ck_assert_str_eq(test_str_138, test_str_138_138);
}
END_TEST

START_TEST(sprintf_test_46) {
  char test_str_82[50] = "";
  char test_str_82_82[50] = "";
  s21_sprintf(test_str_82, "%u", 0);
  sprintf(test_str_82_82, "%u", 0);
  ck_assert_str_eq(test_str_82, test_str_82_82);
}
END_TEST

START_TEST(sprintf_test_47) {
  char test_str_83[50] = "";
  char test_str_83_83[50] = "";
  s21_sprintf(test_str_83, "%u", 1);
  sprintf(test_str_83_83, "%u", 1);
  ck_assert_str_eq(test_str_83, test_str_83_83);
}
END_TEST

START_TEST(sprintf_test_48) {
  char test_str_84[50] = "";
  char test_str_84_84[50] = "";
  s21_sprintf(test_str_84, "%u", 10);
  sprintf(test_str_84_84, "%u", 10);
  ck_assert_str_eq(test_str_84, test_str_84_84);
}
END_TEST

START_TEST(sprintf_test_49) {
  char test_str_85[50] = "";
  char test_str_85_85[50] = "";
  s21_sprintf(test_str_85, "%u", 123456);
  sprintf(test_str_85_85, "%u", 123456);
  ck_assert_str_eq(test_str_85, test_str_85_85);
}
END_TEST

START_TEST(sprintf_test_19) {
  char test_str_28[50] = "";
  char test_str_28_28[50] = "";
  s21_sprintf(test_str_28, "%-u", 0);
  sprintf(test_str_28_28, "%-u", 0);
  ck_assert_str_eq(test_str_28, test_str_28_28);
}
END_TEST

START_TEST(sprintf_test_20) {
  char test_str_29[50] = "";
  char test_str_29_29[50] = "";
  s21_sprintf(test_str_29, "%-u", 1);
  sprintf(test_str_29_29, "%-u", 1);
  ck_assert_str_eq(test_str_29, test_str_29_29);
}
END_TEST

START_TEST(sprintf_test_21) {
  char test_str_30[50] = "";
  char test_str_30_30[50] = "";
  s21_sprintf(test_str_30, "%-u", 10);
  sprintf(test_str_30_30, "%-u", 10);
  ck_assert_str_eq(test_str_30, test_str_30_30);
}
END_TEST

START_TEST(sprintf_test_22) {
  char test_str_31[50] = "";
  char test_str_31_31[50] = "";
  s21_sprintf(test_str_31, "%-u", 123456);
  sprintf(test_str_31_31, "%-u", 123456);
  ck_assert_str_eq(test_str_31, test_str_31_31);
}
END_TEST

START_TEST(sprintf_test_23) {
  char test_str_32[50] = "";
  char test_str_32_32[50] = "";
  ck_assert_int_eq(s21_sprintf(test_str_32, "%-u", -67890123),
                   sprintf(test_str_32_32, "%-u", -67890123));
}
END_TEST

START_TEST(sprintf_test_24) {
  char test_str_33[50] = "";
  char test_str_33_33[50] = "";
  s21_sprintf(test_str_33, "%-u", 4343);
  sprintf(test_str_33_33, "%-u", 4343);
  ck_assert_str_eq(test_str_33, test_str_33_33);
}
END_TEST

START_TEST(sprintf_test_25) {
  char test_str_34[50] = "";
  char test_str_34_34[50] = "";
  ck_assert_int_eq(s21_sprintf(test_str_34, "%-u", -1),
                   sprintf(test_str_34_34, "%-u", -1));
}
END_TEST

START_TEST(sprintf_test_26) {
  char test_str_35[50] = "";
  char test_str_35_35[50] = "";
  ck_assert_int_eq(s21_sprintf(test_str_35, "%-u", -10),
                   sprintf(test_str_35_35, "%-u", -10));
}
END_TEST

START_TEST(sprintf_test_27) {
  char test_str_36[50] = "";
  char test_str_36_36[50] = "";
  s21_sprintf(test_str_36, "%-u", 43);
  sprintf(test_str_36_36, "%-u", 43);
  ck_assert_str_eq(test_str_36, test_str_36_36);
}
END_TEST

START_TEST(sprintf_test_50) {
  char test_str_86[50] = "";
  char test_str_86_86[50] = "";
  ck_assert_int_eq(s21_sprintf(test_str_86, "%u", -67890123),
                   sprintf(test_str_86_86, "%u", -67890123));
}
END_TEST

START_TEST(sprintf_test_51) {
  char test_str_87[50] = "";
  char test_str_87_87[50] = "";
  ck_assert_int_eq(s21_sprintf(test_str_87, "%u", 4343),
                   sprintf(test_str_87_87, "%u", 4343));
}
END_TEST

START_TEST(sprintf_test_52) {
  char test_str_88[50] = "";
  char test_str_88_88[50] = "";
  ck_assert_int_eq(s21_sprintf(test_str_88, "%u", -1),
                   sprintf(test_str_88_88, "%u", -1));
}
END_TEST

START_TEST(sprintf_test_53) {
  char test_str_89[50] = "";
  char test_str_89_89[50] = "";
  ck_assert_int_eq(s21_sprintf(test_str_89, "%u", -10),
                   sprintf(test_str_89_89, "%u", -10));
}
END_TEST

START_TEST(sprintf_test_54) {
  char test_str_90[50] = "";
  char test_str_90_90[50] = "";
  ck_assert_int_eq(s21_sprintf(test_str_90, "%u", 43),
                   sprintf(test_str_90_90, "%u", 43));
}
END_TEST

START_TEST(sprintf_test_76) {
  char test_str_140[50] = "";
  char test_str_140_140[50] = "";
  ck_assert_int_eq(s21_sprintf(test_str_140, "%u", -67890123),
                   sprintf(test_str_140_140, "%u", -67890123));
}
END_TEST

START_TEST(sprintf_test_78) {
  char test_str_142[50] = "";
  char test_str_142_142[50] = "";
  ck_assert_int_eq(s21_sprintf(test_str_142, "%u", -1),
                   sprintf(test_str_142_142, "%u", -1));
}
END_TEST

START_TEST(sprintf_test_79) {
  char test_str_143[50] = "";
  char test_str_143_143[50] = "";
  ck_assert_int_eq(s21_sprintf(test_str_143, "%u", -10),
                   sprintf(test_str_143_143, "%u", -10));
}
END_TEST

START_TEST(sprintf_test_99) {
  char test_str_190[50] = "";
  char test_str_190_190[50] = "";
  s21_sprintf(test_str_190, "%u", 0);
  sprintf(test_str_190_190, "%u", 0);
  ck_assert_str_eq(test_str_190, test_str_190_190);
}
END_TEST

START_TEST(sprintf_test_100) {
  char test_str_191[50] = "";
  char test_str_191_191[50] = "";
  s21_sprintf(test_str_191, "%u", 1);
  sprintf(test_str_191_191, "%u", 1);
  ck_assert_str_eq(test_str_191, test_str_191_191);
}
END_TEST

START_TEST(sprintf_test_101) {
  char test_str_192[50] = "";
  char test_str_192_192[50] = "";
  s21_sprintf(test_str_192, "%u", 10);
  sprintf(test_str_192_192, "%u", 10);
  ck_assert_str_eq(test_str_192, test_str_192_192);
}
END_TEST

START_TEST(sprintf_test_102) {
  char test_str_193[50] = "";
  char test_str_193_193[50] = "";
  s21_sprintf(test_str_193, "%u", 123456);
  sprintf(test_str_193_193, "%u", 123456);
  ck_assert_str_eq(test_str_193, test_str_193_193);
}
END_TEST

START_TEST(sprintf_test_103) {
  char test_str_194[50] = "";
  char test_str_194_194[50] = "";
  ck_assert_int_eq(s21_sprintf(test_str_194, "%u", -67890123),
                   sprintf(test_str_194_194, "%u", -67890123));
}
END_TEST

START_TEST(sprintf_test_104) {
  char test_str_195[50] = "";
  char test_str_195_195[50] = "";
  s21_sprintf(test_str_195, "%u", 4343);
  sprintf(test_str_195_195, "%u", 4343);
  ck_assert_str_eq(test_str_195, test_str_195_195);
}
END_TEST

START_TEST(sprintf_test_105) {
  char test_str_196[50] = "";
  char test_str_196_196[50] = "";
  ck_assert_int_eq(s21_sprintf(test_str_196, "%u", -1),
                   sprintf(test_str_196_196, "%u", -1));
}
END_TEST

START_TEST(sprintf_test_106) {
  char test_str_197[50] = "";
  char test_str_197_197[50] = "";
  ck_assert_int_eq(s21_sprintf(test_str_197, "%u", -10),
                   sprintf(test_str_197_197, "%u", -10));
}
END_TEST

START_TEST(sprintf_test_107) {
  char test_str_198[50] = "";
  char test_str_198_198[50] = "";
  s21_sprintf(test_str_198, "%u", 43);
  sprintf(test_str_198_198, "%u", 43);
  ck_assert_str_eq(test_str_198, test_str_198_198);
}
END_TEST

START_TEST(sprintf_test_226) {
  char test_str_244[50] = "";
  char test_str_244_244[50] = "";
  s21_sprintf(test_str_244, "%0u", 0);
  sprintf(test_str_244_244, "%0u", 0);
  ck_assert_str_eq(test_str_244, test_str_244_244);
}
END_TEST

START_TEST(sprintf_test_227) {
  char test_str_245[50] = "";
  char test_str_245_245[50] = "";
  s21_sprintf(test_str_245, "%0u", 1);
  sprintf(test_str_245_245, "%0u", 1);
  ck_assert_str_eq(test_str_245, test_str_245_245);
}
END_TEST

START_TEST(sprintf_test_228) {
  char test_str_246[50] = "";
  char test_str_246_246[50] = "";
  s21_sprintf(test_str_246, "%0u", 10);
  sprintf(test_str_246_246, "%0u", 10);
  ck_assert_str_eq(test_str_246, test_str_246_246);
}
END_TEST

START_TEST(sprintf_test_229) {
  char test_str_247[50] = "";
  char test_str_247_247[50] = "";
  s21_sprintf(test_str_247, "%0u", 123456);
  sprintf(test_str_247_247, "%0u", 123456);
  ck_assert_str_eq(test_str_247, test_str_247_247);
}
END_TEST

START_TEST(sprintf_test_230) {
  char test_str_248[50] = "";
  char test_str_248_248[50] = "";
  ck_assert_int_eq(s21_sprintf(test_str_248, "%0u", -67890123),
                   sprintf(test_str_248_248, "%0u", -67890123));
}
END_TEST

START_TEST(sprintf_test_231) {
  char test_str_249[50] = "";
  char test_str_249_249[50] = "";
  s21_sprintf(test_str_249, "%0u", 4343);
  sprintf(test_str_249_249, "%0u", 4343);
  ck_assert_str_eq(test_str_249, test_str_249_249);
}
END_TEST

START_TEST(sprintf_test_232) {
  char test_str_250[50] = "";
  char test_str_250_250[50] = "";
  s21_sprintf(test_str_250, "%0u", -1);
  sprintf(test_str_250_250, "%0u", -1);
  ck_assert_str_eq(test_str_250, test_str_250_250);
}
END_TEST

START_TEST(sprintf_test_233) {
  char test_str_251[50] = "";
  char test_str_251_251[50] = "";
  s21_sprintf(test_str_251, "%0u", -10);
  sprintf(test_str_251_251, "%0u", -10);
  ck_assert_str_eq(test_str_251, test_str_251_251);
}
END_TEST

//___________________%F________________

START_TEST(sprintf_flag_float_with_rounding) {
  float space = 6.96568981;
  sprintf(buff, "%f", space);
  s21_sprintf(buff2, "%f", space);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_flag_float) {
  float space = 6.9;
  sprintf(buff, "%f", space);
  s21_sprintf(buff2, "%f", space);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_double_with_width_space) {
  float ans = 5.4;
  sprintf(buff, "%10f", ans);
  s21_sprintf(buff2, "%10f", ans);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_double_with_minus) {
  float ans = 5.4;
  sprintf(buff, "%-10f", ans);
  s21_sprintf(buff2, "%-10f", ans);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_spec_double_with_width_zero) {
  float ans = 5.4;
  sprintf(buff, "%010f", ans);
  s21_sprintf(buff2, "%010f", ans);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(sprintf_1_f) {
  char str1[200];
  char str2[200];
  char *str3 = "%f TEST %.f TEST %4f TEST %4.f TEST %5.10f!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_4_f) {
//   char str1[400];
//   char str2[400];
//   char *str3 = "%20.10f\n%20.15f\n%-20.5f!";
//   double num = -76.756589;
//   ck_assert_int_eq(sprintf(str1, str3, num, num, num),
//                    s21_sprintf(str2, str3, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_8_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.1f\ntest: %16.2f\ntest: %18.3f!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7f!\ntest: %10.15f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 16f!\ntest: %+ 44f!\ntest: % +35f!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_364) {
  char test_str_1289[50] = "";
  char test_str_1289_1289[50] = "";
  s21_sprintf(test_str_1289, "%-f", 0.0);
  sprintf(test_str_1289_1289, "%-f", 0.0);
  ck_assert_str_eq(test_str_1289, test_str_1289_1289);
}
END_TEST

START_TEST(sprintf_test_365) {
  char test_str_1290[50] = "";
  char test_str_1290_1290[50] = "";
  s21_sprintf(test_str_1290, "%-f", 123456789.0);
  sprintf(test_str_1290_1290, "%-f", 123456789.0);
  ck_assert_str_eq(test_str_1290, test_str_1290_1290);
}
END_TEST

START_TEST(sprintf_test_366) {
  char test_str_1291[50] = "";
  char test_str_1291_1291[50] = "";
  s21_sprintf(test_str_1291, "%-f", 0.123456789);
  sprintf(test_str_1291_1291, "%-f", 0.123456789);
  ck_assert_str_eq(test_str_1291, test_str_1291_1291);
}
END_TEST

START_TEST(sprintf_test_367) {
  char test_str_1292[50] = "";
  char test_str_1292_1292[50] = "";
  s21_sprintf(test_str_1292, "%-f", -123456789.0);
  sprintf(test_str_1292_1292, "%-f", -123456789.0);
  ck_assert_str_eq(test_str_1292, test_str_1292_1292);
}
END_TEST

START_TEST(sprintf_test_368) {
  char test_str_1293[50] = "";
  char test_str_1293_1293[50] = "";
  s21_sprintf(test_str_1293, "%-f", -0.123456789);
  sprintf(test_str_1293_1293, "%-f", -0.123456789);
  ck_assert_str_eq(test_str_1293, test_str_1293_1293);
}
END_TEST

START_TEST(sprintf_test_369) {
  char test_str_1294[50] = "";
  char test_str_1294_1294[50] = "";
  s21_sprintf(test_str_1294, "%-f", 123456789.12345679);
  sprintf(test_str_1294_1294, "%-f", 123456789.12345679);
  ck_assert_str_eq(test_str_1294, test_str_1294_1294);
}
END_TEST

START_TEST(sprintf_test_140) {
  char test_str_1295[50] = "";
  char test_str_1295_1295[50] = "";
  s21_sprintf(test_str_1295, "%-f", -123456789.12345678);
  sprintf(test_str_1295_1295, "%-f", -123456789.12345678);
  ck_assert_str_eq(test_str_1295, test_str_1295_1295);
}
END_TEST

START_TEST(sprintf_test_370) {
  char test_str_1296[50] = "";
  char test_str_1296_1296[50] = "";
  s21_sprintf(test_str_1296, "%-f", 1.23e-09);
  sprintf(test_str_1296_1296, "%-f", 1.23e-09);
  ck_assert_str_eq(test_str_1296, test_str_1296_1296);
}
END_TEST

START_TEST(sprintf_test_371) {
  char test_str_1297[50] = "";
  char test_str_1297_1297[50] = "";
  s21_sprintf(test_str_1297, "%-f", 1.23e-09);
  sprintf(test_str_1297_1297, "%-f", 1.23e-09);
  ck_assert_str_eq(test_str_1297, test_str_1297_1297);
}
END_TEST

START_TEST(sprintf_test_372) {
  char test_str_1298[50] = "";
  char test_str_1298_1298[50] = "";
  s21_sprintf(test_str_1298, "%+f", 0.0);
  sprintf(test_str_1298_1298, "%+f", 0.0);
  ck_assert_str_eq(test_str_1298, test_str_1298_1298);
}
END_TEST

START_TEST(sprintf_test_373) {
  char test_str_1299[50] = "";
  char test_str_1299_1299[50] = "";
  s21_sprintf(test_str_1299, "%+f", 123456789.0);
  sprintf(test_str_1299_1299, "%+f", 123456789.0);
  ck_assert_str_eq(test_str_1299, test_str_1299_1299);
}
END_TEST

START_TEST(sprintf_test_374) {
  char test_str_1300[50] = "";
  char test_str_1300_1300[50] = "";
  s21_sprintf(test_str_1300, "%+f", 0.123456789);
  sprintf(test_str_1300_1300, "%+f", 0.123456789);
  ck_assert_str_eq(test_str_1300, test_str_1300_1300);
}
END_TEST

START_TEST(sprintf_test_375) {
  char test_str_1301[50] = "";
  char test_str_1301_1301[50] = "";
  s21_sprintf(test_str_1301, "%+f", -123456789.0);
  sprintf(test_str_1301_1301, "%+f", -123456789.0);
  ck_assert_str_eq(test_str_1301, test_str_1301_1301);
}
END_TEST

START_TEST(sprintf_test_376) {
  char test_str_1302[50] = "";
  char test_str_1302_1302[50] = "";
  s21_sprintf(test_str_1302, "%+f", -0.123456789);
  sprintf(test_str_1302_1302, "%+f", -0.123456789);
  ck_assert_str_eq(test_str_1302, test_str_1302_1302);
}
END_TEST

START_TEST(sprintf_test_377) {
  char test_str_1303[50] = "";
  char test_str_1303_1303[50] = "";
  s21_sprintf(test_str_1303, "%+f", 123456789.12345679);
  sprintf(test_str_1303_1303, "%+f", 123456789.12345679);
  ck_assert_str_eq(test_str_1303, test_str_1303_1303);
}
END_TEST

START_TEST(sprintf_test_378) {
  char test_str_1304[50] = "";
  char test_str_1304_1304[50] = "";
  s21_sprintf(test_str_1304, "%+f", -123456789.12345678);
  sprintf(test_str_1304_1304, "%+f", -123456789.12345678);
  ck_assert_str_eq(test_str_1304, test_str_1304_1304);
}
END_TEST

START_TEST(sprintf_test_379) {
  char test_str_1305[50] = "";
  char test_str_1305_1305[50] = "";
  s21_sprintf(test_str_1305, "%+f", 1.23e-09);
  sprintf(test_str_1305_1305, "%+f", 1.23e-09);
  ck_assert_str_eq(test_str_1305, test_str_1305_1305);
}
END_TEST

START_TEST(sprintf_test_380) {
  char test_str_1306[50] = "";
  char test_str_1306_1306[50] = "";
  s21_sprintf(test_str_1306, "%+f", 1.23e-09);
  sprintf(test_str_1306_1306, "%+f", 1.23e-09);
  ck_assert_str_eq(test_str_1306, test_str_1306_1306);
}
END_TEST

START_TEST(sprintf_test_381) {
  char test_str_1307[50] = "";
  char test_str_1307_1307[50] = "";
  s21_sprintf(test_str_1307, "% f", 0.0);
  sprintf(test_str_1307_1307, "% f", 0.0);
  ck_assert_str_eq(test_str_1307, test_str_1307_1307);
}
END_TEST

START_TEST(sprintf_test_382) {
  char test_str_1308[50] = "";
  char test_str_1308_1308[50] = "";
  s21_sprintf(test_str_1308, "% f", 123456789.0);
  sprintf(test_str_1308_1308, "% f", 123456789.0);
  ck_assert_str_eq(test_str_1308, test_str_1308_1308);
}
END_TEST

START_TEST(sprintf_test_383) {
  char test_str_1309[50] = "";
  char test_str_1309_1309[50] = "";
  s21_sprintf(test_str_1309, "% f", 0.123456789);
  sprintf(test_str_1309_1309, "% f", 0.123456789);
  ck_assert_str_eq(test_str_1309, test_str_1309_1309);
}
END_TEST

START_TEST(sprintf_test_384) {
  char test_str_1310[50] = "";
  char test_str_1310_1310[50] = "";
  s21_sprintf(test_str_1310, "% f", -123456789.0);
  sprintf(test_str_1310_1310, "% f", -123456789.0);
  ck_assert_str_eq(test_str_1310, test_str_1310_1310);
}
END_TEST

START_TEST(sprintf_test_385) {
  char test_str_1311[50] = "";
  char test_str_1311_1311[50] = "";
  s21_sprintf(test_str_1311, "% f", -0.123456789);
  sprintf(test_str_1311_1311, "% f", -0.123456789);
  ck_assert_str_eq(test_str_1311, test_str_1311_1311);
}
END_TEST

START_TEST(sprintf_test_386) {
  char test_str_1312[50] = "";
  char test_str_1312_1312[50] = "";
  s21_sprintf(test_str_1312, "% f", 123456789.12345679);
  sprintf(test_str_1312_1312, "% f", 123456789.12345679);
  ck_assert_str_eq(test_str_1312, test_str_1312_1312);
}
END_TEST

START_TEST(sprintf_test_387) {
  char test_str_1313[50] = "";
  char test_str_1313_1313[50] = "";
  s21_sprintf(test_str_1313, "% f", -123456789.12345678);
  sprintf(test_str_1313_1313, "% f", -123456789.12345678);
  ck_assert_str_eq(test_str_1313, test_str_1313_1313);
}
END_TEST

START_TEST(sprintf_test_388) {
  char test_str_1314[50] = "";
  char test_str_1314_1314[50] = "";
  s21_sprintf(test_str_1314, "% f", 1.23e-09);
  sprintf(test_str_1314_1314, "% f", 1.23e-09);
  ck_assert_str_eq(test_str_1314, test_str_1314_1314);
}
END_TEST

START_TEST(sprintf_test_389) {
  char test_str_1315[50] = "";
  char test_str_1315_1315[50] = "";
  s21_sprintf(test_str_1315, "% f", 1.23e-09);
  sprintf(test_str_1315_1315, "% f", 1.23e-09);
  ck_assert_str_eq(test_str_1315, test_str_1315_1315);
}
END_TEST

START_TEST(sprintf_test_409) {
  char test_str_1325[50] = "";
  char test_str_1325_1325[50] = "";
  s21_sprintf(test_str_1325, "%0f", 0.0);
  sprintf(test_str_1325_1325, "%0f", 0.0);
  ck_assert_str_eq(test_str_1325, test_str_1325_1325);
}
END_TEST

START_TEST(sprintf_test_410) {
  char test_str_1326[50] = "";
  char test_str_1326_1326[50] = "";
  s21_sprintf(test_str_1326, "%0f", 123456789.0);
  sprintf(test_str_1326_1326, "%0f", 123456789.0);
  ck_assert_str_eq(test_str_1326, test_str_1326_1326);
}
END_TEST

START_TEST(sprintf_test_411) {
  char test_str_1327[50] = "";
  char test_str_1327_1327[50] = "";
  s21_sprintf(test_str_1327, "%0f", 0.123456789);
  sprintf(test_str_1327_1327, "%0f", 0.123456789);
  ck_assert_str_eq(test_str_1327, test_str_1327_1327);
}
END_TEST

START_TEST(sprintf_test_412) {
  char test_str_1328[50] = "";
  char test_str_1328_1328[50] = "";
  s21_sprintf(test_str_1328, "%0f", -123456789.0);
  sprintf(test_str_1328_1328, "%0f", -123456789.0);
  ck_assert_str_eq(test_str_1328, test_str_1328_1328);
}
END_TEST

START_TEST(sprintf_test_413) {
  char test_str_1329[50] = "";
  char test_str_1329_1329[50] = "";
  s21_sprintf(test_str_1329, "%0f", -0.123456789);
  sprintf(test_str_1329_1329, "%0f", -0.123456789);
  ck_assert_str_eq(test_str_1329, test_str_1329_1329);
}
END_TEST

START_TEST(sprintf_test_415) {
  char test_str_1330[50] = "";
  char test_str_1330_1330[50] = "";
  s21_sprintf(test_str_1330, "%0f", 123456789.12345679);
  sprintf(test_str_1330_1330, "%0f", 123456789.12345679);
  ck_assert_str_eq(test_str_1330, test_str_1330_1330);
}
END_TEST

START_TEST(sprintf_test_416) {
  char test_str_1331[50] = "";
  char test_str_1331_1331[50] = "";
  s21_sprintf(test_str_1331, "%0f", -123456789.12345678);
  sprintf(test_str_1331_1331, "%0f", -123456789.12345678);
  ck_assert_str_eq(test_str_1331, test_str_1331_1331);
}
END_TEST

START_TEST(sprintf_test_417) {
  char test_str_1332[50] = "";
  char test_str_1332_1332[50] = "";
  s21_sprintf(test_str_1332, "%0f", 1.23e-09);
  sprintf(test_str_1332_1332, "%0f", 1.23e-09);
  ck_assert_str_eq(test_str_1332, test_str_1332_1332);
}
END_TEST

START_TEST(sprintf_test_418) {
  char test_str_1333[50] = "";
  char test_str_1333_1333[50] = "";
  s21_sprintf(test_str_1333, "%0f", 1.23e-09);
  sprintf(test_str_1333_1333, "%0f", 1.23e-09);
  ck_assert_str_eq(test_str_1333, test_str_1333_1333);
}
END_TEST

START_TEST(sprintf_test_419) {
  char test_str_1334[50] = "";
  char test_str_1334_1334[50] = "";
  s21_sprintf(test_str_1334, "%0f", 0.0);
  sprintf(test_str_1334_1334, "%0f", 0.0);
  ck_assert_str_eq(test_str_1334, test_str_1334_1334);
}
END_TEST

START_TEST(sprintf_test_420) {
  char test_str_1335[50] = "";
  char test_str_1335_1335[50] = "";
  s21_sprintf(test_str_1335, "%0f", 123456789.0);
  sprintf(test_str_1335_1335, "%0f", 123456789.0);
  ck_assert_str_eq(test_str_1335, test_str_1335_1335);
}
END_TEST

START_TEST(sprintf_test_421) {
  char test_str_1336[50] = "";
  char test_str_1336_1336[50] = "";
  s21_sprintf(test_str_1336, "%0f", 0.123456789);
  sprintf(test_str_1336_1336, "%0f", 0.123456789);
  ck_assert_str_eq(test_str_1336, test_str_1336_1336);
}
END_TEST

START_TEST(sprintf_test_422) {
  char test_str_1337[50] = "";
  char test_str_1337_1337[50] = "";
  s21_sprintf(test_str_1337, "%0f", -123456789.0);
  sprintf(test_str_1337_1337, "%0f", -123456789.0);
  ck_assert_str_eq(test_str_1337, test_str_1337_1337);
}
END_TEST

START_TEST(sprintf_test_423) {
  char test_str_1338[50] = "";
  char test_str_1338_1338[50] = "";
  s21_sprintf(test_str_1338, "%0f", -0.123456789);
  sprintf(test_str_1338_1338, "%0f", -0.123456789);
  ck_assert_str_eq(test_str_1338, test_str_1338_1338);
}
END_TEST

START_TEST(sprintf_test_424) {
  char test_str_1339[50] = "";
  char test_str_1339_1339[50] = "";
  s21_sprintf(test_str_1339, "%0f", 123456789.12345679);
  sprintf(test_str_1339_1339, "%0f", 123456789.12345679);
  ck_assert_str_eq(test_str_1339, test_str_1339_1339);
}
END_TEST

START_TEST(sprintf_test_425) {
  char test_str_1340[50] = "";
  char test_str_1340_1340[50] = "";
  s21_sprintf(test_str_1340, "%0f", -123456789.12345678);
  sprintf(test_str_1340_1340, "%0f", -123456789.12345678);
  ck_assert_str_eq(test_str_1340, test_str_1340_1340);
}
END_TEST

START_TEST(sprintf_test_426) {
  char test_str_1341[50] = "";
  char test_str_1341_1341[50] = "";
  s21_sprintf(test_str_1341, "%0f", 1.23e-09);
  sprintf(test_str_1341_1341, "%0f", 1.23e-09);
  ck_assert_str_eq(test_str_1341, test_str_1341_1341);
}
END_TEST

START_TEST(sprintf_test_427) {
  char test_str_1342[50] = "";
  char test_str_1342_1342[50] = "";
  s21_sprintf(test_str_1342, "%0f", 1.23e-09);
  sprintf(test_str_1342_1342, "%0f", 1.23e-09);
  ck_assert_str_eq(test_str_1342, test_str_1342_1342);
}
END_TEST

START_TEST(sprintf_test_428) {
  char test_str_1343[50] = "";
  char test_str_1343_1343[50] = "";
  s21_sprintf(test_str_1343, "%10f", 0.0);
  sprintf(test_str_1343_1343, "%10f", 0.0);
  ck_assert_str_eq(test_str_1343, test_str_1343_1343);
}
END_TEST

START_TEST(sprintf_test_429) {
  char test_str_1344[50] = "";
  char test_str_1344_1344[50] = "";
  s21_sprintf(test_str_1344, "%10f", 123456789.0);
  sprintf(test_str_1344_1344, "%10f", 123456789.0);
  ck_assert_str_eq(test_str_1344, test_str_1344_1344);
}
END_TEST

START_TEST(sprintf_test_430) {
  char test_str_1345[50] = "";
  char test_str_1345_1345[50] = "";
  s21_sprintf(test_str_1345, "%10f", 0.123456789);
  sprintf(test_str_1345_1345, "%10f", 0.123456789);
  ck_assert_str_eq(test_str_1345, test_str_1345_1345);
}
END_TEST

START_TEST(sprintf_test_431) {
  char test_str_1346[50] = "";
  char test_str_1346_1346[50] = "";
  s21_sprintf(test_str_1346, "%10f", -123456789.0);
  sprintf(test_str_1346_1346, "%10f", -123456789.0);
  ck_assert_str_eq(test_str_1346, test_str_1346_1346);
}
END_TEST

START_TEST(sprintf_test_432) {
  char test_str_1347[50] = "";
  char test_str_1347_1347[50] = "";
  s21_sprintf(test_str_1347, "%10f", -0.123456789);
  sprintf(test_str_1347_1347, "%10f", -0.123456789);
  ck_assert_str_eq(test_str_1347, test_str_1347_1347);
}
END_TEST

START_TEST(sprintf_test_433) {
  char test_str_1348[50] = "";
  char test_str_1348_1348[50] = "";
  s21_sprintf(test_str_1348, "%10f", 123456789.12345679);
  sprintf(test_str_1348_1348, "%10f", 123456789.12345679);
  ck_assert_str_eq(test_str_1348, test_str_1348_1348);
}
END_TEST

START_TEST(sprintf_test_434) {
  char test_str_1349[50] = "";
  char test_str_1349_1349[50] = "";
  s21_sprintf(test_str_1349, "%10f", -123456789.12345678);
  sprintf(test_str_1349_1349, "%10f", -123456789.12345678);
  ck_assert_str_eq(test_str_1349, test_str_1349_1349);
}
END_TEST

START_TEST(sprintf_test_435) {
  char test_str_1350[50] = "";
  char test_str_1350_1350[50] = "";
  s21_sprintf(test_str_1350, "%10f", 1.23e-09);
  sprintf(test_str_1350_1350, "%10f", 1.23e-09);
  ck_assert_str_eq(test_str_1350, test_str_1350_1350);
}
END_TEST

START_TEST(sprintf_test_436) {
  char test_str_1351[50] = "";
  char test_str_1351_1351[50] = "";
  s21_sprintf(test_str_1351, "%10f", 1.23e-09);
  sprintf(test_str_1351_1351, "%10f", 1.23e-09);
  ck_assert_str_eq(test_str_1351, test_str_1351_1351);
}
END_TEST

START_TEST(sprintf_test_437) {
  char test_str_1352[50] = "";
  char test_str_1352_1352[50] = "";
  s21_sprintf(test_str_1352, "%20f", 0.0);
  sprintf(test_str_1352_1352, "%20f", 0.0);
  ck_assert_str_eq(test_str_1352, test_str_1352_1352);
}
END_TEST

START_TEST(sprintf_test_438) {
  char test_str_1353[50] = "";
  char test_str_1353_1353[50] = "";
  s21_sprintf(test_str_1353, "%20f", 123456789.0);
  sprintf(test_str_1353_1353, "%20f", 123456789.0);
  ck_assert_str_eq(test_str_1353, test_str_1353_1353);
}
END_TEST

START_TEST(sprintf_test_439) {
  char test_str_1354[50] = "";
  char test_str_1354_1354[50] = "";
  s21_sprintf(test_str_1354, "%20f", 0.123456789);
  sprintf(test_str_1354_1354, "%20f", 0.123456789);
  ck_assert_str_eq(test_str_1354, test_str_1354_1354);
}
END_TEST

START_TEST(sprintf_test_440) {
  char test_str_1355[50] = "";
  char test_str_1355_1355[50] = "";
  s21_sprintf(test_str_1355, "%20f", -123456789.0);
  sprintf(test_str_1355_1355, "%20f", -123456789.0);
  ck_assert_str_eq(test_str_1355, test_str_1355_1355);
}
END_TEST

START_TEST(sprintf_test_441) {
  char test_str_1356[50] = "";
  char test_str_1356_1356[50] = "";
  s21_sprintf(test_str_1356, "%20f", -0.123456789);
  sprintf(test_str_1356_1356, "%20f", -0.123456789);
  ck_assert_str_eq(test_str_1356, test_str_1356_1356);
}
END_TEST

START_TEST(sprintf_test_442) {
  char test_str_1357[50] = "";
  char test_str_1357_1357[50] = "";
  s21_sprintf(test_str_1357, "%20f", 123456789.12345679);
  sprintf(test_str_1357_1357, "%20f", 123456789.12345679);
  ck_assert_str_eq(test_str_1357, test_str_1357_1357);
}
END_TEST

START_TEST(sprintf_test_443) {
  char test_str_1358[50] = "";
  char test_str_1358_1358[50] = "";
  s21_sprintf(test_str_1358, "%20f", -123456789.12345678);
  sprintf(test_str_1358_1358, "%20f", -123456789.12345678);
  ck_assert_str_eq(test_str_1358, test_str_1358_1358);
}
END_TEST

START_TEST(sprintf_test_444) {
  char test_str_1359[50] = "";
  char test_str_1359_1359[50] = "";
  s21_sprintf(test_str_1359, "%20f", 1.23e-09);
  sprintf(test_str_1359_1359, "%20f", 1.23e-09);
  ck_assert_str_eq(test_str_1359, test_str_1359_1359);
}
END_TEST

START_TEST(sprintf_test_445) {
  char test_str_1360[50] = "";
  char test_str_1360_1360[50] = "";
  s21_sprintf(test_str_1360, "%20f", 1.23e-09);
  sprintf(test_str_1360_1360, "%20f", 1.23e-09);
  ck_assert_str_eq(test_str_1360, test_str_1360_1360);
}
END_TEST

START_TEST(sprintf_test_446) {
  char test_str_1361[50] = "";
  char test_str_1361_1361[50] = "";
  s21_sprintf(test_str_1361, "%-10f", 0.0);
  sprintf(test_str_1361_1361, "%-10f", 0.0);
  ck_assert_str_eq(test_str_1361, test_str_1361_1361);
}
END_TEST

// проходит в мейне, но не через мейк
START_TEST(sprintf_test_447) {
  char test_str_1362[50] = "";
  char test_str_1362_1362[50] = "";
  s21_sprintf(test_str_1362, "%-10f", 123456789.0);
  sprintf(test_str_1362_1362, "%-10f", 123456789.0);
  ck_assert_str_eq(test_str_1362, test_str_1362_1362);
}
END_TEST

START_TEST(sprintf_test_448) {
  char test_str_1363[50] = "";
  char test_str_1363_1363[50] = "";
  s21_sprintf(test_str_1363, "%-10f", 0.123456789);
  sprintf(test_str_1363_1363, "%-10f", 0.123456789);
  ck_assert_str_eq(test_str_1363, test_str_1363_1363);
}
END_TEST

START_TEST(sprintf_test_449) {
  char test_str_1364[50] = "";
  char test_str_1364_1364[50] = "";
  s21_sprintf(test_str_1364, "%-10f", -123456789.0);
  sprintf(test_str_1364_1364, "%-10f", -123456789.0);
  ck_assert_str_eq(test_str_1364, test_str_1364_1364);
}
END_TEST

START_TEST(sprintf_test_450) {
  char test_str_1365[50] = "";
  char test_str_1365_1365[50] = "";
  s21_sprintf(test_str_1365, "%-10f", -0.123456789);
  sprintf(test_str_1365_1365, "%-10f", -0.123456789);
  ck_assert_str_eq(test_str_1365, test_str_1365_1365);
}
END_TEST

START_TEST(sprintf_test_451) {
  char test_str_1366[50] = "";
  char test_str_1366_1366[50] = "";
  s21_sprintf(test_str_1366, "%-10f", 123456789.12345679);
  sprintf(test_str_1366_1366, "%-10f", 123456789.12345679);
  ck_assert_str_eq(test_str_1366, test_str_1366_1366);
}
END_TEST

START_TEST(sprintf_test_452) {
  char test_str_1367[50] = "";
  char test_str_1367_1367[50] = "";
  s21_sprintf(test_str_1367, "%-10f", -123456789.12345678);
  sprintf(test_str_1367_1367, "%-10f", -123456789.12345678);
  ck_assert_str_eq(test_str_1367, test_str_1367_1367);
}
END_TEST

START_TEST(sprintf_test_453) {
  char test_str_1368[50] = "";
  char test_str_1368_1368[50] = "";
  s21_sprintf(test_str_1368, "%-10f", 1.23e-09);
  sprintf(test_str_1368_1368, "%-10f", 1.23e-09);
  ck_assert_str_eq(test_str_1368, test_str_1368_1368);
}
END_TEST

START_TEST(sprintf_test_454) {
  char test_str_1369[50] = "";
  char test_str_1369_1369[50] = "";
  s21_sprintf(test_str_1369, "%-10f", 1.23e-09);
  sprintf(test_str_1369_1369, "%-10f", 1.23e-09);
  ck_assert_str_eq(test_str_1369, test_str_1369_1369);
}
END_TEST

START_TEST(sprintf_test_456) {
  char test_str_1370[50] = "";
  char test_str_1370_1370[50] = "";
  s21_sprintf(test_str_1370, "%-20f", 0.0);
  sprintf(test_str_1370_1370, "%-20f", 0.0);
  ck_assert_str_eq(test_str_1370, test_str_1370_1370);
}
END_TEST

START_TEST(sprintf_test_457) {
  char test_str_1371[50] = "";
  char test_str_1371_1371[50] = "";
  s21_sprintf(test_str_1371, "%-20f", 123456789.0);
  sprintf(test_str_1371_1371, "%-20f", 123456789.0);
  ck_assert_str_eq(test_str_1371, test_str_1371_1371);
}
END_TEST

START_TEST(sprintf_test_458) {
  char test_str_1372[50] = "";
  char test_str_1372_1372[50] = "";
  s21_sprintf(test_str_1372, "%-20f", 0.123456789);
  sprintf(test_str_1372_1372, "%-20f", 0.123456789);
  ck_assert_str_eq(test_str_1372, test_str_1372_1372);
}
END_TEST

START_TEST(sprintf_test_459) {
  char test_str_1373[50] = "";
  char test_str_1373_1373[50] = "";
  s21_sprintf(test_str_1373, "%-20f", -123456789.0);
  sprintf(test_str_1373_1373, "%-20f", -123456789.0);
  ck_assert_str_eq(test_str_1373, test_str_1373_1373);
}
END_TEST

START_TEST(sprintf_test_460) {
  char test_str_1374[50] = "";
  char test_str_1374_1374[50] = "";
  s21_sprintf(test_str_1374, "%-20f", -0.123456789);
  sprintf(test_str_1374_1374, "%-20f", -0.123456789);
  ck_assert_str_eq(test_str_1374, test_str_1374_1374);
}
END_TEST

START_TEST(sprintf_test_461) {
  char test_str_1375[50] = "";
  char test_str_1375_1375[50] = "";
  s21_sprintf(test_str_1375, "%-20f", 123456789.12345679);
  sprintf(test_str_1375_1375, "%-20f", 123456789.12345679);
  ck_assert_str_eq(test_str_1375, test_str_1375_1375);
}
END_TEST

START_TEST(sprintf_test_462) {
  char test_str_1376[50] = "";
  char test_str_1376_1376[50] = "";
  s21_sprintf(test_str_1376, "%-20f", -123456789.12345678);
  sprintf(test_str_1376_1376, "%-20f", -123456789.12345678);
  ck_assert_str_eq(test_str_1376, test_str_1376_1376);
}
END_TEST

START_TEST(sprintf_test_463) {
  char test_str_1377[50] = "";
  char test_str_1377_1377[50] = "";
  s21_sprintf(test_str_1377, "%-20f", 1.23e-09);
  sprintf(test_str_1377_1377, "%-20f", 1.23e-09);
  ck_assert_str_eq(test_str_1377, test_str_1377_1377);
}
END_TEST

START_TEST(sprintf_test_464) {
  char test_str_1378[50] = "";
  char test_str_1378_1378[50] = "";
  s21_sprintf(test_str_1378, "%-20f", 1.23e-09);
  sprintf(test_str_1378_1378, "%-20f", 1.23e-09);
  ck_assert_str_eq(test_str_1378, test_str_1378_1378);
}
END_TEST

START_TEST(sprintf_test_510) {
  char test_str_1424[50] = "";
  char test_str_1424_1424[50] = "";
  s21_sprintf(test_str_1424, "%.10f", 0.0);
  sprintf(test_str_1424_1424, "%.10f", 0.0);
  ck_assert_str_eq(test_str_1424, test_str_1424_1424);
}
END_TEST

START_TEST(sprintf_test_511) {
  char test_str_1425[50] = "";
  char test_str_1425_1425[50] = "";
  s21_sprintf(test_str_1425, "%.10f", 123456789.0);
  sprintf(test_str_1425_1425, "%.10f", 123456789.0);
  ck_assert_str_eq(test_str_1425, test_str_1425_1425);
}
END_TEST

START_TEST(sprintf_test_512) {
  char test_str_1426[50] = "";
  char test_str_1426_1426[50] = "";
  s21_sprintf(test_str_1426, "%.10f", 0.123456789);
  sprintf(test_str_1426_1426, "%.10f", 0.123456789);
  ck_assert_str_eq(test_str_1426, test_str_1426_1426);
}
END_TEST

START_TEST(sprintf_test_513) {
  char test_str_1427[50] = "";
  char test_str_1427_1427[50] = "";
  s21_sprintf(test_str_1427, "%.10f", -123456789.0);
  sprintf(test_str_1427_1427, "%.10f", -123456789.0);
  ck_assert_str_eq(test_str_1427, test_str_1427_1427);
}
END_TEST

START_TEST(sprintf_test_514) {
  char test_str_1428[50] = "";
  char test_str_1428_1428[50] = "";
  s21_sprintf(test_str_1428, "%.10f", -0.123456789);
  sprintf(test_str_1428_1428, "%.10f", -0.123456789);
  ck_assert_str_eq(test_str_1428, test_str_1428_1428);
}
END_TEST

START_TEST(sprintf_test_515) {
  char test_str_1429[50] = "";
  char test_str_1429_1429[50] = "";
  s21_sprintf(test_str_1429, "%.10f", 123456789.12345679);
  sprintf(test_str_1429_1429, "%.10f", 123456789.12345679);
  ck_assert_str_eq(test_str_1429, test_str_1429_1429);
}
END_TEST

START_TEST(sprintf_test_516) {
  char test_str_1430[50] = "";
  char test_str_1430_1430[50] = "";
  s21_sprintf(test_str_1430, "%.10f", -123456789.12345678);
  sprintf(test_str_1430_1430, "%.10f", -123456789.12345678);
  ck_assert_str_eq(test_str_1430, test_str_1430_1430);
}
END_TEST

START_TEST(sprintf_test_517) {
  char test_str_1431[50] = "";
  char test_str_1431_1431[50] = "";
  s21_sprintf(test_str_1431, "%.10f", 1.23e-09);
  sprintf(test_str_1431_1431, "%.10f", 1.23e-09);
  ck_assert_str_eq(test_str_1431, test_str_1431_1431);
}
END_TEST

START_TEST(sprintf_test_518) {
  char test_str_1432[50] = "";
  char test_str_1432_1432[50] = "";
  s21_sprintf(test_str_1432, "%.10f", 1.23e-09);
  sprintf(test_str_1432_1432, "%.10f", 1.23e-09);
  ck_assert_str_eq(test_str_1432, test_str_1432_1432);
}
END_TEST

START_TEST(sprintf_test_519) {
  char test_str_1433[50] = "";
  char test_str_1433_1433[50] = "";
  s21_sprintf(test_str_1433, "%.14f", 0.0);
  sprintf(test_str_1433_1433, "%.14f", 0.0);
  ck_assert_str_eq(test_str_1433, test_str_1433_1433);
}
END_TEST

// START_TEST(sprintf_test_520) {
//   char test_str_1434[50] = "";
//   char test_str_1434_1434[50] = "";
//   s21_sprintf(test_str_1434, "%.14f", 123456789.0);
//   sprintf(test_str_1434_1434, "%.14f", 123456789.0);
//   ck_assert_str_eq(test_str_1434, test_str_1434_1434);
// }
// END_TEST

START_TEST(sprintf_test_521) {
  char test_str_1435[50] = "";
  char test_str_1435_1435[50] = "";
  s21_sprintf(test_str_1435, "%.14f", 0.123456789);
  sprintf(test_str_1435_1435, "%.14f", 0.123456789);
  ck_assert_str_eq(test_str_1435, test_str_1435_1435);
}
END_TEST

START_TEST(sprintf_test_522) {
  char test_str_1436[50] = "";
  char test_str_1436_1436[50] = "";
  s21_sprintf(test_str_1436, "%.14f", -123456789.0);
  sprintf(test_str_1436_1436, "%.14f", -123456789.0);
  ck_assert_str_eq(test_str_1436, test_str_1436_1436);
}
END_TEST

START_TEST(sprintf_test_523) {
  char test_str_1437[50] = "";
  char test_str_1437_1437[50] = "";
  s21_sprintf(test_str_1437, "%.14f", -0.123456789);
  sprintf(test_str_1437_1437, "%.14f", -0.123456789);
  ck_assert_str_eq(test_str_1437, test_str_1437_1437);
}
END_TEST

// START_TEST(sprintf_test_524) {
//   char test_str_1438[50] = "";
//   char test_str_1438_1438[50] = "";
//   s21_sprintf(test_str_1438, "%.14f", 123456789.12345679);
//   sprintf(test_str_1438_1438, "%.14f", 123456789.12345679);
//   ck_assert_str_eq(test_str_1438, test_str_1438_1438);
// }
// END_TEST

START_TEST(sprintf_test_525) {
  char test_str_1439[50] = "";
  char test_str_1439_1439[50] = "";
  s21_sprintf(test_str_1439, "%.14f", -123456789.12345678);
  sprintf(test_str_1439_1439, "%.14f", -123456789.12345678);
  ck_assert_str_eq(test_str_1439, test_str_1439_1439);
}
END_TEST

START_TEST(sprintf_test_526) {
  char test_str_1440[50] = "";
  char test_str_1440_1440[50] = "";
  s21_sprintf(test_str_1440, "%.14f", 1.23e-09);
  sprintf(test_str_1440_1440, "%.14f", 1.23e-09);
  ck_assert_str_eq(test_str_1440, test_str_1440_1440);
}
END_TEST

START_TEST(sprintf_test_527) {
  char test_str_1441[50] = "";
  char test_str_1441_1441[50] = "";
  s21_sprintf(test_str_1441, "%.14f", 1.23e-09);
  sprintf(test_str_1441_1441, "%.14f", 1.23e-09);
  ck_assert_str_eq(test_str_1441, test_str_1441_1441);
}
END_TEST

START_TEST(sprintf_test_528) {
  char test_str_1442[50] = "";
  char test_str_1442_1442[50] = "";
  s21_sprintf(test_str_1442, "%.1f", 0.0);
  sprintf(test_str_1442_1442, "%.1f", 0.0);
  ck_assert_str_eq(test_str_1442, test_str_1442_1442);
}
END_TEST

START_TEST(sprintf_test_529) {
  char test_str_1443[50] = "";
  char test_str_1443_1443[50] = "";
  s21_sprintf(test_str_1443, "%.1f", 123456789.0);
  sprintf(test_str_1443_1443, "%.1f", 123456789.0);
  ck_assert_str_eq(test_str_1443, test_str_1443_1443);
}
END_TEST

START_TEST(sprintf_test_530) {
  char test_str_1444[50] = "";
  char test_str_1444_1444[50] = "";
  s21_sprintf(test_str_1444, "%.1f", 0.123456789);
  sprintf(test_str_1444_1444, "%.1f", 0.123456789);
  ck_assert_str_eq(test_str_1444, test_str_1444_1444);
}
END_TEST

START_TEST(sprintf_test_531) {
  char test_str_1445[50] = "";
  char test_str_1445_1445[50] = "";
  s21_sprintf(test_str_1445, "%.1f", -123456789.0);
  sprintf(test_str_1445_1445, "%.1f", -123456789.0);
  ck_assert_str_eq(test_str_1445, test_str_1445_1445);
}
END_TEST

START_TEST(sprintf_test_532) {
  char test_str_1446[50] = "";
  char test_str_1446_1446[50] = "";
  s21_sprintf(test_str_1446, "%.1f", -0.123456789);
  sprintf(test_str_1446_1446, "%.1f", -0.123456789);
  ck_assert_str_eq(test_str_1446, test_str_1446_1446);
}
END_TEST

START_TEST(sprintf_test_533) {
  char test_str_1447[50] = "";
  char test_str_1447_1447[50] = "";
  s21_sprintf(test_str_1447, "%.1f", 123456789.12345679);
  sprintf(test_str_1447_1447, "%.1f", 123456789.12345679);
  ck_assert_str_eq(test_str_1447, test_str_1447_1447);
}
END_TEST

START_TEST(sprintf_spec_double_minus_25) {
  float ans = -0.05;
  sprintf(buff, "%f", ans);
  s21_sprintf(buff2, "%f", ans);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

//___________________________%I_____________________

START_TEST(sprintf_test_10) {
  char test_str_10[50] = "";
  char test_str_10_10[50] = "";
  s21_sprintf(test_str_10, "%-i", 0);
  sprintf(test_str_10_10, "%-i", 0);
  ck_assert_str_eq(test_str_10, test_str_10_10);
}
END_TEST

START_TEST(sprintf_test_11) {
  char test_str_11[50] = "";
  char test_str_11_11[50] = "";
  s21_sprintf(test_str_11, "%-i", 1);
  sprintf(test_str_11_11, "%-i", 1);
  ck_assert_str_eq(test_str_11, test_str_11_11);
}
END_TEST

START_TEST(sprintf_test_12) {
  char test_str_12[50] = "";
  char test_str_12_12[50] = "";
  s21_sprintf(test_str_12, "%-i", 10);
  sprintf(test_str_12_12, "%-i", 10);
  ck_assert_str_eq(test_str_12, test_str_12_12);
}
END_TEST

START_TEST(sprintf_test_13) {
  char test_str_13[50] = "";
  char test_str_13_13[50] = "";
  s21_sprintf(test_str_13, "%-i", 123456);
  sprintf(test_str_13_13, "%-i", 123456);
  ck_assert_str_eq(test_str_13, test_str_13_13);
}
END_TEST

START_TEST(sprintf_test_14) {
  char test_str_14[50] = "";
  char test_str_14_14[50] = "";
  s21_sprintf(test_str_14, "%-i", -67890123);
  sprintf(test_str_14_14, "%-i", -67890123);
  ck_assert_str_eq(test_str_14, test_str_14_14);
}
END_TEST

START_TEST(sprintf_test_15) {
  char test_str_15[50] = "";
  char test_str_15_15[50] = "";
  s21_sprintf(test_str_15, "%-i", 4343);
  sprintf(test_str_15_15, "%-i", 4343);
  ck_assert_str_eq(test_str_15, test_str_15_15);
}
END_TEST

START_TEST(sprintf_test_16) {
  char test_str_16[50] = "";
  char test_str_16_16[50] = "";
  s21_sprintf(test_str_16, "%-i", -1);
  sprintf(test_str_16_16, "%-i", -1);
  ck_assert_str_eq(test_str_16, test_str_16_16);
}
END_TEST

START_TEST(sprintf_test_17) {
  char test_str_17[50] = "";
  char test_str_17_17[50] = "";
  s21_sprintf(test_str_17, "%-i", -10);
  sprintf(test_str_17_17, "%-i", -10);
  ck_assert_str_eq(test_str_17, test_str_17_17);
}
END_TEST

START_TEST(sprintf_test_18) {
  char test_str_18[50] = "";
  char test_str_18_18[50] = "";
  s21_sprintf(test_str_18, "%-i", 43);
  sprintf(test_str_18_18, "%-i", 43);
  ck_assert_str_eq(test_str_18, test_str_18_18);
}
END_TEST

START_TEST(sprintf_test_37) {
  char test_str_64[50] = "";
  char test_str_64_64[50] = "";
  s21_sprintf(test_str_64, "%+i", 0);
  sprintf(test_str_64_64, "%+i", 0);
  ck_assert_str_eq(test_str_64, test_str_64_64);
}
END_TEST

START_TEST(sprintf_test_38) {
  char test_str_65[50] = "";
  char test_str_65_65[50] = "";
  s21_sprintf(test_str_65, "%+i", 1);
  sprintf(test_str_65_65, "%+i", 1);
  ck_assert_str_eq(test_str_65, test_str_65_65);
}
END_TEST

START_TEST(sprintf_test_39) {
  char test_str_66[50] = "";
  char test_str_66_66[50] = "";
  s21_sprintf(test_str_66, "%+i", 10);
  sprintf(test_str_66_66, "%+i", 10);
  ck_assert_str_eq(test_str_66, test_str_66_66);
}
END_TEST

START_TEST(sprintf_test_40) {
  char test_str_67[50] = "";
  char test_str_67_67[50] = "";
  s21_sprintf(test_str_67, "%+i", 123456);
  sprintf(test_str_67_67, "%+i", 123456);
  ck_assert_str_eq(test_str_67, test_str_67_67);
}
END_TEST

START_TEST(sprintf_test_41) {
  char test_str_68[50] = "";
  char test_str_68_68[50] = "";
  s21_sprintf(test_str_68, "%+i", -67890123);
  sprintf(test_str_68_68, "%+i", -67890123);
  ck_assert_str_eq(test_str_68, test_str_68_68);
}
END_TEST

START_TEST(sprintf_test_42) {
  char test_str_69[50] = "";
  char test_str_69_69[50] = "";
  s21_sprintf(test_str_69, "%+i", 4343);
  sprintf(test_str_69_69, "%+i", 4343);
  ck_assert_str_eq(test_str_69, test_str_69_69);
}
END_TEST

START_TEST(sprintf_test_43) {
  char test_str_70[50] = "";
  char test_str_70_70[50] = "";
  s21_sprintf(test_str_70, "%+i", -1);
  sprintf(test_str_70_70, "%+i", -1);
  ck_assert_str_eq(test_str_70, test_str_70_70);
}
END_TEST

START_TEST(sprintf_test_44) {
  char test_str_71[50] = "";
  char test_str_71_71[50] = "";
  s21_sprintf(test_str_71, "%+i", -10);
  sprintf(test_str_71_71, "%+i", -10);
  ck_assert_str_eq(test_str_71, test_str_71_71);
}
END_TEST

START_TEST(sprintf_test_45) {
  char test_str_72[50] = "";
  char test_str_72_72[50] = "";
  s21_sprintf(test_str_72, "%+i", 43);
  sprintf(test_str_72_72, "%+i", 43);
  ck_assert_str_eq(test_str_72, test_str_72_72);
}
END_TEST

START_TEST(sprintf_test_64) {
  char test_str_118[50] = "";
  char test_str_118_118[50] = "";
  s21_sprintf(test_str_118, "% i", 0);
  sprintf(test_str_118_118, "% i", 0);
  ck_assert_str_eq(test_str_118, test_str_118_118);
}
END_TEST

START_TEST(sprintf_test_65) {
  char test_str_119[50] = "";
  char test_str_119_119[50] = "";
  s21_sprintf(test_str_119, "% i", 1);
  sprintf(test_str_119_119, "% i", 1);
  ck_assert_str_eq(test_str_119, test_str_119_119);
}
END_TEST

START_TEST(sprintf_test_66) {
  char test_str_120[50] = "";
  char test_str_120_120[50] = "";
  s21_sprintf(test_str_120, "% i", 10);
  sprintf(test_str_120_120, "% i", 10);
  ck_assert_str_eq(test_str_120, test_str_120_120);
}
END_TEST

START_TEST(sprintf_test_67) {
  char test_str_121[50] = "";
  char test_str_121_121[50] = "";
  s21_sprintf(test_str_121, "% i", 123456);
  sprintf(test_str_121_121, "% i", 123456);
  ck_assert_str_eq(test_str_121, test_str_121_121);
}
END_TEST

START_TEST(sprintf_test_68) {
  char test_str_122[50] = "";
  char test_str_122_122[50] = "";
  s21_sprintf(test_str_122, "% i", -67890123);
  sprintf(test_str_122_122, "% i", -67890123);
  ck_assert_str_eq(test_str_122, test_str_122_122);
}
END_TEST

START_TEST(sprintf_test_69) {
  char test_str_123[50] = "";
  char test_str_123_123[50] = "";
  s21_sprintf(test_str_123, "% i", 4343);
  sprintf(test_str_123_123, "% i", 4343);
  ck_assert_str_eq(test_str_123, test_str_123_123);
}
END_TEST

START_TEST(sprintf_test_70) {
  char test_str_124[50] = "";
  char test_str_124_124[50] = "";
  s21_sprintf(test_str_124, "% i", -1);
  sprintf(test_str_124_124, "% i", -1);
  ck_assert_str_eq(test_str_124, test_str_124_124);
}
END_TEST

START_TEST(sprintf_test_71) {
  char test_str_125[50] = "";
  char test_str_125_125[50] = "";
  s21_sprintf(test_str_125, "% i", -10);
  sprintf(test_str_125_125, "% i", -10);
  ck_assert_str_eq(test_str_125, test_str_125_125);
}
END_TEST

START_TEST(sprintf_test_72) {
  char test_str_126[50] = "";
  char test_str_126_126[50] = "";
  s21_sprintf(test_str_126, "% i", 43);
  sprintf(test_str_126_126, "% i", 43);
  ck_assert_str_eq(test_str_126, test_str_126_126);
}
END_TEST

START_TEST(sprintf_test_90) {
  char test_str_172[50] = "";
  char test_str_172_172[50] = "";
  s21_sprintf(test_str_172, "%i", 0);
  sprintf(test_str_172_172, "%i", 0);
  ck_assert_str_eq(test_str_172, test_str_172_172);
}
END_TEST

START_TEST(sprintf_test_91) {
  char test_str_173[50] = "";
  char test_str_173_173[50] = "";
  s21_sprintf(test_str_173, "%i", 1);
  sprintf(test_str_173_173, "%i", 1);
  ck_assert_str_eq(test_str_173, test_str_173_173);
}
END_TEST

START_TEST(sprintf_test_92) {
  char test_str_174[50] = "";
  char test_str_174_174[50] = "";
  s21_sprintf(test_str_174, "%i", 10);
  sprintf(test_str_174_174, "%i", 10);
  ck_assert_str_eq(test_str_174, test_str_174_174);
}
END_TEST

START_TEST(sprintf_test_93) {
  char test_str_175[50] = "";
  char test_str_175_175[50] = "";
  s21_sprintf(test_str_175, "%i", 123456);
  sprintf(test_str_175_175, "%i", 123456);
  ck_assert_str_eq(test_str_175, test_str_175_175);
}
END_TEST

START_TEST(sprintf_test_94) {
  char test_str_176[50] = "";
  char test_str_176_176[50] = "";
  s21_sprintf(test_str_176, "%i", -67890123);
  sprintf(test_str_176_176, "%i", -67890123);
  ck_assert_str_eq(test_str_176, test_str_176_176);
}
END_TEST

START_TEST(sprintf_test_95) {
  char test_str_177[50] = "";
  char test_str_177_177[50] = "";
  s21_sprintf(test_str_177, "%i", 4343);
  sprintf(test_str_177_177, "%i", 4343);
  ck_assert_str_eq(test_str_177, test_str_177_177);
}
END_TEST

START_TEST(sprintf_test_96) {
  char test_str_178[50] = "";
  char test_str_178_178[50] = "";
  s21_sprintf(test_str_178, "%i", -1);
  sprintf(test_str_178_178, "%i", -1);
  ck_assert_str_eq(test_str_178, test_str_178_178);
}
END_TEST

START_TEST(sprintf_test_97) {
  char test_str_179[50] = "";
  char test_str_179_179[50] = "";
  s21_sprintf(test_str_179, "%i", -10);
  sprintf(test_str_179_179, "%i", -10);
  ck_assert_str_eq(test_str_179, test_str_179_179);
}
END_TEST

START_TEST(sprintf_test_98) {
  char test_str_180[50] = "";
  char test_str_180_180[50] = "";
  s21_sprintf(test_str_180, "%i", 43);
  sprintf(test_str_180_180, "%i", 43);
  ck_assert_str_eq(test_str_180, test_str_180_180);
}
END_TEST

START_TEST(sprintf_test_217) {
  char test_str_226[50] = "";
  char test_str_226_226[50] = "";
  s21_sprintf(test_str_226, "%0i", 0);
  sprintf(test_str_226_226, "%0i", 0);
  ck_assert_str_eq(test_str_226, test_str_226_226);
}
END_TEST

START_TEST(sprintf_test_218) {
  char test_str_227[50] = "";
  char test_str_227_227[50] = "";
  s21_sprintf(test_str_227, "%0i", 1);
  sprintf(test_str_227_227, "%0i", 1);
  ck_assert_str_eq(test_str_227, test_str_227_227);
}
END_TEST

START_TEST(sprintf_test_219) {
  char test_str_228[50] = "";
  char test_str_228_228[50] = "";
  s21_sprintf(test_str_228, "%0i", 10);
  sprintf(test_str_228_228, "%0i", 10);
  ck_assert_str_eq(test_str_228, test_str_228_228);
}
END_TEST

START_TEST(sprintf_test_220) {
  char test_str_229[50] = "";
  char test_str_229_229[50] = "";
  s21_sprintf(test_str_229, "%0i", 123456);
  sprintf(test_str_229_229, "%0i", 123456);
  ck_assert_str_eq(test_str_229, test_str_229_229);
}
END_TEST

START_TEST(sprintf_test_221) {
  char test_str_230[50] = "";
  char test_str_230_230[50] = "";
  s21_sprintf(test_str_230, "%0i", -67890123);
  sprintf(test_str_230_230, "%0i", -67890123);
  ck_assert_str_eq(test_str_230, test_str_230_230);
}
END_TEST

START_TEST(sprintf_test_222) {
  char test_str_231[50] = "";
  char test_str_231_231[50] = "";
  s21_sprintf(test_str_231, "%0i", 4343);
  sprintf(test_str_231_231, "%0i", 4343);
  ck_assert_str_eq(test_str_231, test_str_231_231);
}
END_TEST

START_TEST(sprintf_test_223) {
  char test_str_232[50] = "";
  char test_str_232_232[50] = "";
  s21_sprintf(test_str_232, "%0i", -1);
  sprintf(test_str_232_232, "%0i", -1);
  ck_assert_str_eq(test_str_232, test_str_232_232);
}
END_TEST

START_TEST(sprintf_test_224) {
  char test_str_233[50] = "";
  char test_str_233_233[50] = "";
  s21_sprintf(test_str_233, "%0i", -10);
  sprintf(test_str_233_233, "%0i", -10);
  ck_assert_str_eq(test_str_233, test_str_233_233);
}
END_TEST

START_TEST(sprintf_test_225) {
  char test_str_234[50] = "";
  char test_str_234_234[50] = "";
  s21_sprintf(test_str_234, "%0i", 43);
  sprintf(test_str_234_234, "%0i", 43);
  ck_assert_str_eq(test_str_234, test_str_234_234);
}
END_TEST

START_TEST(sprintf_test_256) {
  char test_str_1144[50] = "";
  char test_str_1144_1144[50] = "";
  s21_sprintf(test_str_1144, "%i", 0);
  sprintf(test_str_1144_1144, "%i", 0);
  ck_assert_str_eq(test_str_1144, test_str_1144_1144);
}
END_TEST

START_TEST(sprintf_test_257) {
  char test_str_1145[50] = "";
  char test_str_1145_1145[50] = "";
  s21_sprintf(test_str_1145, "%i", 1);
  sprintf(test_str_1145_1145, "%i", 1);
  ck_assert_str_eq(test_str_1145, test_str_1145_1145);
}
END_TEST

START_TEST(sprintf_test_258) {
  char test_str_1146[50] = "";
  char test_str_1146_1146[50] = "";
  s21_sprintf(test_str_1146, "%i", 10);
  sprintf(test_str_1146_1146, "%i", 10);
  ck_assert_str_eq(test_str_1146, test_str_1146_1146);
}
END_TEST

START_TEST(sprintf_test_259) {
  char test_str_1147[50] = "";
  char test_str_1147_1147[50] = "";
  s21_sprintf(test_str_1147, "%i", 123456);
  sprintf(test_str_1147_1147, "%i", 123456);
  ck_assert_str_eq(test_str_1147, test_str_1147_1147);
}
END_TEST

START_TEST(sprintf_test_260) {
  char test_str_1148[50] = "";
  char test_str_1148_1148[50] = "";
  s21_sprintf(test_str_1148, "%i", -678901);
  sprintf(test_str_1148_1148, "%i", -678901);
  ck_assert_str_eq(test_str_1148, test_str_1148_1148);
}
END_TEST

START_TEST(sprintf_test_261) {
  char test_str_1149[50] = "";
  char test_str_1149_1149[50] = "";
  s21_sprintf(test_str_1149, "%i", 4343);
  sprintf(test_str_1149_1149, "%i", 4343);
  ck_assert_str_eq(test_str_1149, test_str_1149_1149);
}
END_TEST

START_TEST(sprintf_test_262) {
  char test_str_1150[50] = "";
  char test_str_1150_1150[50] = "";
  s21_sprintf(test_str_1150, "%i", -1);
  sprintf(test_str_1150_1150, "%i", -1);
  ck_assert_str_eq(test_str_1150, test_str_1150_1150);
}
END_TEST

START_TEST(sprintf_test_263) {
  char test_str_1151[50] = "";
  char test_str_1151_1151[50] = "";
  s21_sprintf(test_str_1151, "%i", -10);
  sprintf(test_str_1151_1151, "%i", -10);
  ck_assert_str_eq(test_str_1151, test_str_1151_1151);
}
END_TEST

START_TEST(sprintf_test_264) {
  char test_str_1152[50] = "";
  char test_str_1152_1152[50] = "";
  s21_sprintf(test_str_1152, "%i", 43);
  sprintf(test_str_1152_1152, "%i", 43);
  ck_assert_str_eq(test_str_1152, test_str_1152_1152);
}
END_TEST

START_TEST(sprintf_3_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%i Test %i Test %i";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%li Test %li Test %hi GOD %hi";
  long int val = 3088675747373646;
  signed long val2 = -125;
  short int val3 = -22600;
  short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%3i Test %5i Test %10i";
  int val = -3015;
  int val2 = -11234;
  int val3 = -99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_signed_i) {
  char str1[200] = {'\0'};
  char str2[200] = {'\0'};
  char *str3 = "%6.5i Test %.24i Test %3.i TEST %.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5i Test %-.8i Test %-7i TEST %-.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%0i Test %0.i Test %0.0i TEST %0i GOD %.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%+i Test %+3.i Test %+5.7i TEST %+10i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "% i Test % 3.i Test % 5.7i TEST % 10i GOD %.i";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%+i Test %+3.i Test %+5.7i TEST %+10i GOD %+.i";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %06i Test %05.7i TEST %0.7i Oof %0.i";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_signed_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%i";
  int val = 12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_17_signed_i) {
//   char str1[200];
//   char str2[200];
//   char *str3 = "%- i Test %- 15i sdasda %- 15i sdsad %- i";
//   int val = -3231;
//   int val2 = -3231;
//   int val3 = 3231;
//   int val4 = 3231;
//   sprintf(str1, str3, val, val2, val3, val4);
//   s21_sprintf(str2, str3, val, val2, val3, val4);
//   ck_assert_str_eq(str1, str2);
//   // ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
//   //                  s21_sprintf(str2, str3, val, val2, val3, val4));
//   // ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

//_____________________________%S________________________

START_TEST(sprintf_test_274) {
  char test_str_1189[50] = "";
  char test_str_1189_1189[50] = "";
  s21_sprintf(test_str_1189, "%-s", "1234567");
  sprintf(test_str_1189_1189, "%-s", "1234567");
  ck_assert_str_eq(test_str_1189, test_str_1189_1189);
}
END_TEST

START_TEST(sprintf_test_275) {
  char test_str_1190[50] = "";
  char test_str_1190_1190[50] = "";
  s21_sprintf(test_str_1190, "%-s", "dffdsfsf");
  sprintf(test_str_1190_1190, "%-s", "dffdsfsf");
  ck_assert_str_eq(test_str_1190, test_str_1190_1190);
}
END_TEST

START_TEST(sprintf_test_276) {
  char test_str_1191[50] = "";
  char test_str_1191_1191[50] = "";
  s21_sprintf(test_str_1191, "%-s", "");
  sprintf(test_str_1191_1191, "%-s", "");
  ck_assert_str_eq(test_str_1191, test_str_1191_1191);
}
END_TEST

START_TEST(sprintf_test_277) {
  char test_str_1192[50] = "";
  char test_str_1192_1192[50] = "";
  s21_sprintf(test_str_1192, "%-s", "eefwfweweffwefw");
  sprintf(test_str_1192_1192, "%-s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1192, test_str_1192_1192);
}
END_TEST

START_TEST(sprintf_test_278) {
  char test_str_1193[50] = "";
  char test_str_1193_1193[50] = "";
  s21_sprintf(test_str_1193, "%s", "1234567");
  sprintf(test_str_1193_1193, "%s", "1234567");
  ck_assert_str_eq(test_str_1193, test_str_1193_1193);
}
END_TEST

START_TEST(sprintf_test_279) {
  char test_str_1194[50] = "";
  char test_str_1194_1194[50] = "";
  s21_sprintf(test_str_1194, "%s", "dffdsfsf");
  sprintf(test_str_1194_1194, "%s", "dffdsfsf");
  ck_assert_str_eq(test_str_1194, test_str_1194_1194);
}
END_TEST

START_TEST(sprintf_test_280) {
  char test_str_1195[50] = "";
  char test_str_1195_1195[50] = "";
  s21_sprintf(test_str_1195, "%s", "");
  sprintf(test_str_1195_1195, "%s", "");
  ck_assert_str_eq(test_str_1195, test_str_1195_1195);
}
END_TEST

START_TEST(sprintf_test_281) {
  char test_str_1196[50] = "";
  char test_str_1196_1196[50] = "";
  s21_sprintf(test_str_1196, "%s", "eefwfweweffwefw");
  sprintf(test_str_1196_1196, "%s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1196, test_str_1196_1196);
}
END_TEST

START_TEST(sprintf_test_282) {
  char test_str_1197[50] = "";
  char test_str_1197_1197[50] = "";
  s21_sprintf(test_str_1197, "%s", "1234567");
  sprintf(test_str_1197_1197, "%s", "1234567");
  ck_assert_str_eq(test_str_1197, test_str_1197_1197);
}
END_TEST

START_TEST(sprintf_test_283) {
  char test_str_1198[50] = "";
  char test_str_1198_1198[50] = "";
  s21_sprintf(test_str_1198, "%s", "dffdsfsf");
  sprintf(test_str_1198_1198, "%s", "dffdsfsf");
  ck_assert_str_eq(test_str_1198, test_str_1198_1198);
}
END_TEST

START_TEST(sprintf_test_284) {
  char test_str_1199[50] = "";
  char test_str_1199_1199[50] = "";
  s21_sprintf(test_str_1199, "%s", "");
  sprintf(test_str_1199_1199, "%s", "");
  ck_assert_str_eq(test_str_1199, test_str_1199_1199);
}
END_TEST

START_TEST(sprintf_test_285) {
  char test_str_1200[50] = "";
  char test_str_1200_1200[50] = "";
  s21_sprintf(test_str_1200, "%s", "eefwfweweffwefw");
  sprintf(test_str_1200_1200, "%s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1200, test_str_1200_1200);
}
END_TEST

START_TEST(sprintf_test_286) {
  char test_str_1201[50] = "";
  char test_str_1201_1201[50] = "";
  s21_sprintf(test_str_1201, "%s", "1234567");
  sprintf(test_str_1201_1201, "%s", "1234567");
  ck_assert_str_eq(test_str_1201, test_str_1201_1201);
}
END_TEST

START_TEST(sprintf_test_287) {
  char test_str_1202[50] = "";
  char test_str_1202_1202[50] = "";
  s21_sprintf(test_str_1202, "%s", "dffdsfsf");
  sprintf(test_str_1202_1202, "%s", "dffdsfsf");
  ck_assert_str_eq(test_str_1202, test_str_1202_1202);
}
END_TEST

START_TEST(sprintf_test_288) {
  char test_str_1203[50] = "";
  char test_str_1203_1203[50] = "";
  s21_sprintf(test_str_1203, "%s", "");
  sprintf(test_str_1203_1203, "%s", "");
  ck_assert_str_eq(test_str_1203, test_str_1203_1203);
}
END_TEST

START_TEST(sprintf_test_289) {
  char test_str_1204[50] = "";
  char test_str_1204_1204[50] = "";
  s21_sprintf(test_str_1204, "%s", "eefwfweweffwefw");
  sprintf(test_str_1204_1204, "%s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1204, test_str_1204_1204);
}
END_TEST

START_TEST(sprintf_test_290) {
  char test_str_1205[50] = "";
  char test_str_1205_1205[50] = "";
  s21_sprintf(test_str_1205, "%s", "1234567");
  sprintf(test_str_1205_1205, "%s", "1234567");
  ck_assert_str_eq(test_str_1205, test_str_1205_1205);
}
END_TEST

START_TEST(sprintf_test_291) {
  char test_str_1206[50] = "";
  char test_str_1206_1206[50] = "";
  s21_sprintf(test_str_1206, "%s", "dffdsfsf");
  sprintf(test_str_1206_1206, "%s", "dffdsfsf");
  ck_assert_str_eq(test_str_1206, test_str_1206_1206);
}
END_TEST

START_TEST(sprintf_test_292) {
  char test_str_1207[50] = "";
  char test_str_1207_1207[50] = "";
  s21_sprintf(test_str_1207, "%s", "");
  sprintf(test_str_1207_1207, "%s", "");
  ck_assert_str_eq(test_str_1207, test_str_1207_1207);
}
END_TEST

START_TEST(sprintf_test_293) {
  char test_str_1208[50] = "";
  char test_str_1208_1208[50] = "";
  s21_sprintf(test_str_1208, "%s", "eefwfweweffwefw");
  sprintf(test_str_1208_1208, "%s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1208, test_str_1208_1208);
}
END_TEST

START_TEST(sprintf_test_294) {
  char test_str_1209[50] = "";
  char test_str_1209_1209[50] = "";
  s21_sprintf(test_str_1209, "%20s", "1234567");
  sprintf(test_str_1209_1209, "%20s", "1234567");
  ck_assert_str_eq(test_str_1209, test_str_1209_1209);
}
END_TEST

START_TEST(sprintf_test_295) {
  char test_str_1210[50] = "";
  char test_str_1210_1210[50] = "";
  s21_sprintf(test_str_1210, "%20s", "dffdsfsf");
  sprintf(test_str_1210_1210, "%20s", "dffdsfsf");
  ck_assert_str_eq(test_str_1210, test_str_1210_1210);
}
END_TEST

START_TEST(sprintf_test_296) {
  char test_str_1211[50] = "";
  char test_str_1211_1211[50] = "";
  s21_sprintf(test_str_1211, "%20s", "");
  sprintf(test_str_1211_1211, "%20s", "");
  ck_assert_str_eq(test_str_1211, test_str_1211_1211);
}
END_TEST

START_TEST(sprintf_test_297) {
  char test_str_1212[50] = "";
  char test_str_1212_1212[50] = "";
  s21_sprintf(test_str_1212, "%20s", "eefwfweweffwefw");
  sprintf(test_str_1212_1212, "%20s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1212, test_str_1212_1212);
}
END_TEST

START_TEST(sprintf_test_298) {
  char test_str_1213[50] = "";
  char test_str_1213_1213[50] = "";
  s21_sprintf(test_str_1213, "%s", "1234567");
  sprintf(test_str_1213_1213, "%s", "1234567");
  ck_assert_str_eq(test_str_1213, test_str_1213_1213);
}
END_TEST

START_TEST(sprintf_test_299) {
  char test_str_1214[50] = "";
  char test_str_1214_1214[50] = "";
  s21_sprintf(test_str_1214, "%s", "dffdsfsf");
  sprintf(test_str_1214_1214, "%s", "dffdsfsf");
  ck_assert_str_eq(test_str_1214, test_str_1214_1214);
}
END_TEST

START_TEST(sprintf_test_300) {
  char test_str_1215[50] = "";
  char test_str_1215_1215[50] = "";
  s21_sprintf(test_str_1215, "%s", "");
  sprintf(test_str_1215_1215, "%s", "");
  ck_assert_str_eq(test_str_1215, test_str_1215_1215);
}
END_TEST

START_TEST(sprintf_test_301) {
  char test_str_1216[50] = "";
  char test_str_1216_1216[50] = "";
  s21_sprintf(test_str_1216, "%s", "eefwfweweffwefw");
  sprintf(test_str_1216_1216, "%s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1216, test_str_1216_1216);
}
END_TEST

START_TEST(sprintf_test_302) {
  char test_str_1217[50] = "";
  char test_str_1217_1217[50] = "";
  s21_sprintf(test_str_1217, "%.0s", "1234567");
  sprintf(test_str_1217_1217, "%.0s", "1234567");
  ck_assert_str_eq(test_str_1217, test_str_1217_1217);
}
END_TEST

START_TEST(sprintf_test_303) {
  char test_str_1218[50] = "";
  char test_str_1218_1218[50] = "";
  s21_sprintf(test_str_1218, "%.0s", "dffdsfsf");
  sprintf(test_str_1218_1218, "%.0s", "dffdsfsf");
  ck_assert_str_eq(test_str_1218, test_str_1218_1218);
}
END_TEST

START_TEST(sprintf_test_304) {
  char test_str_1219[50] = "";
  char test_str_1219_1219[50] = "";
  s21_sprintf(test_str_1219, "%.0s", "");
  sprintf(test_str_1219_1219, "%.0s", "");
  ck_assert_str_eq(test_str_1219, test_str_1219_1219);
}
END_TEST

START_TEST(sprintf_test_305) {
  char test_str_1220[50] = "";
  char test_str_1220_1220[50] = "";
  s21_sprintf(test_str_1220, "%.0s", "eefwfweweffwefw");
  sprintf(test_str_1220_1220, "%.0s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1220, test_str_1220_1220);
}
END_TEST

START_TEST(sprintf_test_306) {
  char test_str_1221[50] = "";
  char test_str_1221_1221[50] = "";
  s21_sprintf(test_str_1221, "%10s", "1234567");
  sprintf(test_str_1221_1221, "%10s", "1234567");
  ck_assert_str_eq(test_str_1221, test_str_1221_1221);
}
END_TEST

START_TEST(sprintf_test_307) {
  char test_str_1222[50] = "";
  char test_str_1222_1222[50] = "";
  s21_sprintf(test_str_1222, "%10s", "dffdsfsf");
  sprintf(test_str_1222_1222, "%10s", "dffdsfsf");
  ck_assert_str_eq(test_str_1222, test_str_1222_1222);
}
END_TEST

START_TEST(sprintf_test_308) {
  char test_str_1223[50] = "";
  char test_str_1223_1223[50] = "";
  s21_sprintf(test_str_1223, "%10s", "");
  sprintf(test_str_1223_1223, "%10s", "");
  ck_assert_str_eq(test_str_1223, test_str_1223_1223);
}
END_TEST

START_TEST(sprintf_test_309) {
  char test_str_1224[50] = "";
  char test_str_1224_1224[50] = "";
  s21_sprintf(test_str_1224, "%10s", "eefwfweweffwefw");
  sprintf(test_str_1224_1224, "%10s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1224, test_str_1224_1224);
}
END_TEST

START_TEST(sprintf_test_310) {
  char test_str_1225[50] = "";
  char test_str_1225_1225[50] = "";
  s21_sprintf(test_str_1225, "%-10s", "1234567");
  sprintf(test_str_1225_1225, "%-10s", "1234567");
  ck_assert_str_eq(test_str_1225, test_str_1225_1225);
}
END_TEST

START_TEST(sprintf_test_311) {
  char test_str_1226[50] = "";
  char test_str_1226_1226[50] = "";
  s21_sprintf(test_str_1226, "%-10s", "dffdsfsf");
  sprintf(test_str_1226_1226, "%-10s", "dffdsfsf");
  ck_assert_str_eq(test_str_1226, test_str_1226_1226);
}
END_TEST

START_TEST(sprintf_test_312) {
  char test_str_1227[50] = "";
  char test_str_1227_1227[50] = "";
  s21_sprintf(test_str_1227, "%-10s", "");
  sprintf(test_str_1227_1227, "%-10s", "");
  ck_assert_str_eq(test_str_1227, test_str_1227_1227);
}
END_TEST

START_TEST(sprintf_test_313) {
  char test_str_1228[50] = "";
  char test_str_1228_1228[50] = "";
  s21_sprintf(test_str_1228, "%-10s", "eefwfweweffwefw");
  sprintf(test_str_1228_1228, "%-10s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1228, test_str_1228_1228);
}
END_TEST

START_TEST(sprintf_1_string) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %s Test";
  char *val = "Why am I here?!";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "I'm so tired";
  char *val2 = "Who invented this?";
  char *val3 = "This project gave me hemmoroids";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "Don't need this test";
  char *val2 = "Just for the kicks";
  char *val3 = "Lol";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%3s Test %5s Test %10s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore";
  char *val3 = "PPAP";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5s Test %.23s Test %3.s TEST %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5s Test %-.8s Test %-7s TEST %-.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%0s Test %0.s Test %0.0s TEST %0s GOD %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3.s Test %5.7s TEST %10s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "abcd";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_string) {
  char str1[200];
  char str2[200];
  char *str3 = "% s Test % 3.s Test % 5.7s TEST % 10s GOD %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3.s Test %+5.7s TEST %+10s GOD %+.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s %s %s %% %d";
  char *val = "This";
  char *val2 = "\0";
  int val3 = 65;
  char *val4 = "string";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val4, val3),
                   s21_sprintf(str2, str3, val, val2, val4, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

int main(void) {
  Suite *suite = suite_create("COLLECTION");  // test suite - это набор тестов
  TCase *tcase = tcase_create("TESTS");  // test case — это конкретный тест кейс
  SRunner *srunner = srunner_create(suite);

  int result = 0;

  suite_add_tcase(suite, tcase);

  tcase_add_test(tcase, test_strlen);
  tcase_add_test(tcase, test_strncpy);
  tcase_add_test(tcase, test_strcmp);
  tcase_add_test(tcase, test_strncat);
  tcase_add_test(tcase, test_strtok);
  tcase_add_test(tcase, test_strncmp);

  tcase_add_test(tcase, test_memcmp);
  tcase_add_test(tcase, test_strchr);
  tcase_add_test(tcase, test_strerror);
  tcase_add_test(tcase, test_strstr);
  tcase_add_test(tcase, test_strrchr);

  tcase_add_test(tcase, test_strcpy);
  tcase_add_test(tcase, test_strcat);

  tcase_add_test(tcase, test_memchr);
  tcase_add_test(tcase, test_memcpy);
  tcase_add_test(tcase, test_memset);
  tcase_add_test(tcase, test_strpbrk);
  tcase_add_test(tcase, test_strcspn);

  //__________UPPER_________________
  tcase_add_test(tcase, test_to_upper);

  //__________LOWER_________________
  tcase_add_test(tcase, test_to_lower);

  //__________INSERT________________
  tcase_add_test(tcase, test_insert_1);
  tcase_add_test(tcase, test_insert_2);
  tcase_add_test(tcase, test_insert_3);
  tcase_add_test(tcase, test_insert_4);
  tcase_add_test(tcase, test_insert_5);
  tcase_add_test(tcase, test_insert_6);
  tcase_add_test(tcase, test_insert_7);
  tcase_add_test(tcase, test_insert_8);
  tcase_add_test(tcase, test_insert_9);
  tcase_add_test(tcase, test_insert_10);

  //__________TRIM___________________
  tcase_add_test(tcase, test_trim_1);
  tcase_add_test(tcase, test_trim_2);
  tcase_add_test(tcase, test_trim_3);
  tcase_add_test(tcase, test_trim_4);
  tcase_add_test(tcase, test_trim_5);
  tcase_add_test(tcase, test_trim_6);
  tcase_add_test(tcase, test_trim_7);
  tcase_add_test(tcase, test_trim_8);
  tcase_add_test(tcase, test_trim_9);
  tcase_add_test(tcase, test_trim_10);

  /*----------------------SPRINTF----------------------*/

  tcase_add_test(tcase, sprintf_spec_double_minus_25);
  tcase_add_test(tcase, sprintf_spec_double_with_width_zero);
  tcase_add_test(tcase, sprintf_spec_int_minus_zero);
  tcase_add_test(tcase, sprintf_spec_double_with_minus);
  tcase_add_test(tcase, sprintf_spec_string_with_width_space);
  tcase_add_test(tcase, sprintf_spec_string_with_width_and_minus);
  tcase_add_test(tcase, sprintf_spec_h_for_int);
  tcase_add_test(tcase, sprintf_spec_int_precision_bigger_with);
  tcase_add_test(tcase, sprintf_spec_uint_precision_bigger_with);
  tcase_add_test(tcase, sprintf_spec_double_with_width_space);
  tcase_add_test(tcase, sprintf_spec_char_with_width);
  tcase_add_test(tcase, sprintf_spec_char_with_width_and_minus);
  tcase_add_test(tcase, sprintf_flag_float);
  tcase_add_test(tcase, sprintf_flag_float_with_rounding);
  tcase_add_test(tcase, sprintf_spec_prec);
  tcase_add_test(tcase, sprintf_spec_char);
  tcase_add_test(tcase, sprintf_flag_plus);
  tcase_add_test(tcase, sprintf_flag_zero);
  tcase_add_test(tcase, sprintf_flag_space);
  tcase_add_test(tcase, sprintf_flag_procent);
  tcase_add_test(tcase, sprintf_flag_minus);
  tcase_add_test(tcase, sprintf_width_neg);
  tcase_add_test(tcase, sprintf_width_2);
  tcase_add_test(tcase, sprintf_width);
  tcase_add_test(tcase, sprintf_spec_u_neg);
  tcase_add_test(tcase, sprintf_spec_u);
  tcase_add_test(tcase, sprintf_spec_d_plus1);
  tcase_add_test(tcase, sprintf_spec_d_plus2);
  tcase_add_test(tcase, sprintf_spec_d_space1);
  tcase_add_test(tcase, sprintf_spec_d_space2);
  tcase_add_test(tcase, sprintf_spec_d2);
  tcase_add_test(tcase, sprintf_spec_d1);
  tcase_add_test(tcase, sprintf_spec_c);
  // tcase_add_test(tcase, sprintf_char1);
  tcase_add_test(tcase, sprintf_precent);

  //___________part2_________
  tcase_add_test(tcase, sprintf_test_1);
  tcase_add_test(tcase, sprintf_test_2);
  tcase_add_test(tcase, sprintf_test_3);
  tcase_add_test(tcase, sprintf_test_4);
  tcase_add_test(tcase, sprintf_test_5);
  tcase_add_test(tcase, sprintf_test_6);
  tcase_add_test(tcase, sprintf_test_7);
  tcase_add_test(tcase, sprintf_test_8);
  tcase_add_test(tcase, sprintf_test_9);
  tcase_add_test(tcase, sprintf_test_10);
  tcase_add_test(tcase, sprintf_test_11);
  tcase_add_test(tcase, sprintf_test_12);
  tcase_add_test(tcase, sprintf_test_13);
  tcase_add_test(tcase, sprintf_test_14);
  tcase_add_test(tcase, sprintf_test_15);
  tcase_add_test(tcase, sprintf_test_16);
  tcase_add_test(tcase, sprintf_test_17);
  tcase_add_test(tcase, sprintf_test_18);
  tcase_add_test(tcase, sprintf_test_19);
  tcase_add_test(tcase, sprintf_test_20);
  tcase_add_test(tcase, sprintf_test_21);
  tcase_add_test(tcase, sprintf_test_22);
  tcase_add_test(tcase, sprintf_test_23);
  tcase_add_test(tcase, sprintf_test_24);
  tcase_add_test(tcase, sprintf_test_25);
  tcase_add_test(tcase, sprintf_test_26);
  tcase_add_test(tcase, sprintf_test_27);
  tcase_add_test(tcase, sprintf_test_28);
  tcase_add_test(tcase, sprintf_test_29);
  tcase_add_test(tcase, sprintf_test_30);
  tcase_add_test(tcase, sprintf_test_31);
  tcase_add_test(tcase, sprintf_test_32);
  tcase_add_test(tcase, sprintf_test_33);
  tcase_add_test(tcase, sprintf_test_34);
  tcase_add_test(tcase, sprintf_test_35);
  tcase_add_test(tcase, sprintf_test_36);
  tcase_add_test(tcase, sprintf_test_37);
  tcase_add_test(tcase, sprintf_test_38);
  tcase_add_test(tcase, sprintf_test_39);
  tcase_add_test(tcase, sprintf_test_40);
  tcase_add_test(tcase, sprintf_test_41);
  tcase_add_test(tcase, sprintf_test_42);
  tcase_add_test(tcase, sprintf_test_43);
  tcase_add_test(tcase, sprintf_test_44);
  tcase_add_test(tcase, sprintf_test_45);
  tcase_add_test(tcase, sprintf_test_46);
  tcase_add_test(tcase, sprintf_test_47);
  tcase_add_test(tcase, sprintf_test_48);
  tcase_add_test(tcase, sprintf_test_49);
  tcase_add_test(tcase, sprintf_test_50);
  tcase_add_test(tcase, sprintf_test_51);
  tcase_add_test(tcase, sprintf_test_52);
  tcase_add_test(tcase, sprintf_test_53);
  tcase_add_test(tcase, sprintf_test_54);
  tcase_add_test(tcase, sprintf_test_56);
  tcase_add_test(tcase, sprintf_test_57);
  tcase_add_test(tcase, sprintf_test_58);
  tcase_add_test(tcase, sprintf_test_59);
  tcase_add_test(tcase, sprintf_test_60);
  tcase_add_test(tcase, sprintf_test_61);
  tcase_add_test(tcase, sprintf_test_62);
  tcase_add_test(tcase, sprintf_test_63);
  tcase_add_test(tcase, sprintf_test_64);
  tcase_add_test(tcase, sprintf_test_65);
  tcase_add_test(tcase, sprintf_test_66);
  tcase_add_test(tcase, sprintf_test_67);
  tcase_add_test(tcase, sprintf_test_68);
  tcase_add_test(tcase, sprintf_test_69);
  tcase_add_test(tcase, sprintf_test_70);
  tcase_add_test(tcase, sprintf_test_71);
  tcase_add_test(tcase, sprintf_test_72);
  tcase_add_test(tcase, sprintf_test_73);
  tcase_add_test(tcase, sprintf_test_74);
  tcase_add_test(tcase, sprintf_test_75);
  tcase_add_test(tcase, sprintf_test_76);
  tcase_add_test(tcase, sprintf_test_77);
  tcase_add_test(tcase, sprintf_test_78);
  tcase_add_test(tcase, sprintf_test_79);
  tcase_add_test(tcase, sprintf_test_80);
  tcase_add_test(tcase, sprintf_test_81);
  tcase_add_test(tcase, sprintf_test_82);
  tcase_add_test(tcase, sprintf_test_83);
  tcase_add_test(tcase, sprintf_test_84);
  tcase_add_test(tcase, sprintf_test_85);
  tcase_add_test(tcase, sprintf_test_86);
  tcase_add_test(tcase, sprintf_test_87);
  tcase_add_test(tcase, sprintf_test_88);
  tcase_add_test(tcase, sprintf_test_89);
  tcase_add_test(tcase, sprintf_test_90);
  tcase_add_test(tcase, sprintf_test_91);
  tcase_add_test(tcase, sprintf_test_92);
  tcase_add_test(tcase, sprintf_test_93);
  tcase_add_test(tcase, sprintf_test_94);
  tcase_add_test(tcase, sprintf_test_95);
  tcase_add_test(tcase, sprintf_test_96);
  tcase_add_test(tcase, sprintf_test_97);
  tcase_add_test(tcase, sprintf_test_98);
  tcase_add_test(tcase, sprintf_test_100);
  tcase_add_test(tcase, sprintf_test_101);
  tcase_add_test(tcase, sprintf_test_102);
  tcase_add_test(tcase, sprintf_test_103);
  tcase_add_test(tcase, sprintf_test_104);
  tcase_add_test(tcase, sprintf_test_105);
  tcase_add_test(tcase, sprintf_test_106);
  tcase_add_test(tcase, sprintf_test_107);
  tcase_add_test(tcase, sprintf_test_208);
  tcase_add_test(tcase, sprintf_test_209);
  tcase_add_test(tcase, sprintf_test_210);
  tcase_add_test(tcase, sprintf_test_211);
  tcase_add_test(tcase, sprintf_test_212);
  tcase_add_test(tcase, sprintf_test_213);
  tcase_add_test(tcase, sprintf_test_214);
  tcase_add_test(tcase, sprintf_test_215);
  tcase_add_test(tcase, sprintf_test_216);
  tcase_add_test(tcase, sprintf_test_217);
  tcase_add_test(tcase, sprintf_test_218);
  tcase_add_test(tcase, sprintf_test_219);
  tcase_add_test(tcase, sprintf_test_220);
  tcase_add_test(tcase, sprintf_test_221);
  tcase_add_test(tcase, sprintf_test_222);
  tcase_add_test(tcase, sprintf_test_223);
  tcase_add_test(tcase, sprintf_test_224);
  tcase_add_test(tcase, sprintf_test_225);
  tcase_add_test(tcase, sprintf_test_226);
  tcase_add_test(tcase, sprintf_test_227);
  tcase_add_test(tcase, sprintf_test_228);
  tcase_add_test(tcase, sprintf_test_229);
  tcase_add_test(tcase, sprintf_test_230);
  tcase_add_test(tcase, sprintf_test_231);
  tcase_add_test(tcase, sprintf_test_247);
  tcase_add_test(tcase, sprintf_test_248);
  tcase_add_test(tcase, sprintf_test_249);
  tcase_add_test(tcase, sprintf_test_250);
  tcase_add_test(tcase, sprintf_test_251);
  tcase_add_test(tcase, sprintf_test_252);
  tcase_add_test(tcase, sprintf_test_253);
  tcase_add_test(tcase, sprintf_test_254);
  tcase_add_test(tcase, sprintf_test_255);
  tcase_add_test(tcase, sprintf_test_256);
  tcase_add_test(tcase, sprintf_test_257);
  tcase_add_test(tcase, sprintf_test_258);
  tcase_add_test(tcase, sprintf_test_259);
  tcase_add_test(tcase, sprintf_test_260);
  tcase_add_test(tcase, sprintf_test_261);
  tcase_add_test(tcase, sprintf_test_262);
  tcase_add_test(tcase, sprintf_test_263);
  tcase_add_test(tcase, sprintf_test_264);
  tcase_add_test(tcase, sprintf_test_265);
  tcase_add_test(tcase, sprintf_test_266);
  tcase_add_test(tcase, sprintf_test_267);
  tcase_add_test(tcase, sprintf_test_268);
  tcase_add_test(tcase, sprintf_test_269);
  tcase_add_test(tcase, sprintf_test_270);
  tcase_add_test(tcase, sprintf_test_271);
  tcase_add_test(tcase, sprintf_test_272);
  tcase_add_test(tcase, sprintf_test_273);
  tcase_add_test(tcase, sprintf_test_274);
  tcase_add_test(tcase, sprintf_test_275);
  tcase_add_test(tcase, sprintf_test_276);
  tcase_add_test(tcase, sprintf_test_277);
  tcase_add_test(tcase, sprintf_test_278);
  tcase_add_test(tcase, sprintf_test_279);
  tcase_add_test(tcase, sprintf_test_280);
  tcase_add_test(tcase, sprintf_test_281);
  tcase_add_test(tcase, sprintf_test_282);
  tcase_add_test(tcase, sprintf_test_283);
  tcase_add_test(tcase, sprintf_test_284);
  tcase_add_test(tcase, sprintf_test_285);
  tcase_add_test(tcase, sprintf_test_286);
  tcase_add_test(tcase, sprintf_test_287);
  tcase_add_test(tcase, sprintf_test_288);
  tcase_add_test(tcase, sprintf_test_289);
  tcase_add_test(tcase, sprintf_test_290);
  tcase_add_test(tcase, sprintf_test_291);
  tcase_add_test(tcase, sprintf_test_292);
  tcase_add_test(tcase, sprintf_test_293);
  tcase_add_test(tcase, sprintf_test_294);
  tcase_add_test(tcase, sprintf_test_295);
  tcase_add_test(tcase, sprintf_test_296);
  tcase_add_test(tcase, sprintf_test_297);
  tcase_add_test(tcase, sprintf_test_298);
  tcase_add_test(tcase, sprintf_test_299);
  tcase_add_test(tcase, sprintf_test_300);
  tcase_add_test(tcase, sprintf_test_301);
  tcase_add_test(tcase, sprintf_test_302);
  tcase_add_test(tcase, sprintf_test_303);
  tcase_add_test(tcase, sprintf_test_304);
  tcase_add_test(tcase, sprintf_test_305);
  tcase_add_test(tcase, sprintf_test_306);
  tcase_add_test(tcase, sprintf_test_307);
  tcase_add_test(tcase, sprintf_test_308);
  tcase_add_test(tcase, sprintf_test_309);
  tcase_add_test(tcase, sprintf_test_310);
  tcase_add_test(tcase, sprintf_test_311);
  tcase_add_test(tcase, sprintf_test_312);
  tcase_add_test(tcase, sprintf_test_313);
  tcase_add_test(tcase, sprintf_test_324);
  tcase_add_test(tcase, sprintf_test_325);
  tcase_add_test(tcase, sprintf_test_326);
  tcase_add_test(tcase, sprintf_test_327);
  tcase_add_test(tcase, sprintf_test_328);
  tcase_add_test(tcase, sprintf_test_329);
  tcase_add_test(tcase, sprintf_test_330);
  tcase_add_test(tcase, sprintf_test_331);
  tcase_add_test(tcase, sprintf_test_332);
  tcase_add_test(tcase, sprintf_test_333);
  tcase_add_test(tcase, sprintf_test_334);
  tcase_add_test(tcase, sprintf_test_335);
  tcase_add_test(tcase, sprintf_test_336);
  tcase_add_test(tcase, sprintf_test_337);
  tcase_add_test(tcase, sprintf_test_338);
  tcase_add_test(tcase, sprintf_test_339);
  tcase_add_test(tcase, sprintf_test_340);
  tcase_add_test(tcase, sprintf_test_341);
  tcase_add_test(tcase, sprintf_test_342);
  tcase_add_test(tcase, sprintf_test_343);
  tcase_add_test(tcase, sprintf_test_344);
  tcase_add_test(tcase, sprintf_test_345);
  tcase_add_test(tcase, sprintf_test_346);
  tcase_add_test(tcase, sprintf_test_347);
  tcase_add_test(tcase, sprintf_test_348);
  tcase_add_test(tcase, sprintf_test_349);
  tcase_add_test(tcase, sprintf_test_350);
  tcase_add_test(tcase, sprintf_test_351);
  tcase_add_test(tcase, sprintf_test_352);
  tcase_add_test(tcase, sprintf_test_353);
  tcase_add_test(tcase, sprintf_test_354);
  tcase_add_test(tcase, sprintf_test_355);
  tcase_add_test(tcase, sprintf_test_356);
  tcase_add_test(tcase, sprintf_test_357);
  tcase_add_test(tcase, sprintf_test_358);
  tcase_add_test(tcase, sprintf_test_359);
  tcase_add_test(tcase, sprintf_test_360);
  tcase_add_test(tcase, sprintf_test_361);
  tcase_add_test(tcase, sprintf_test_362);
  tcase_add_test(tcase, sprintf_test_363);
  tcase_add_test(tcase, sprintf_test_441);
  tcase_add_test(tcase, sprintf_test_442);
  tcase_add_test(tcase, sprintf_test_443);
  tcase_add_test(tcase, sprintf_test_444);
  tcase_add_test(tcase, sprintf_test_445);
  tcase_add_test(tcase, sprintf_test_446);
  tcase_add_test(tcase, sprintf_test_447);
  tcase_add_test(tcase, sprintf_test_448);
  tcase_add_test(tcase, sprintf_test_449);
  tcase_add_test(tcase, sprintf_test_450);
  tcase_add_test(tcase, sprintf_test_451);
  tcase_add_test(tcase, sprintf_test_452);
  tcase_add_test(tcase, sprintf_test_453);
  tcase_add_test(tcase, sprintf_test_454);
  tcase_add_test(tcase, sprintf_test_456);
  tcase_add_test(tcase, sprintf_test_457);
  tcase_add_test(tcase, sprintf_test_458);
  tcase_add_test(tcase, sprintf_test_459);
  tcase_add_test(tcase, sprintf_test_460);
  tcase_add_test(tcase, sprintf_test_461);
  tcase_add_test(tcase, sprintf_test_462);
  tcase_add_test(tcase, sprintf_test_463);
  tcase_add_test(tcase, sprintf_test_464);
  tcase_add_test(tcase, sprintf_test_510);
  tcase_add_test(tcase, sprintf_test_511);
  tcase_add_test(tcase, sprintf_test_512);
  tcase_add_test(tcase, sprintf_test_513);
  tcase_add_test(tcase, sprintf_test_514);
  tcase_add_test(tcase, sprintf_test_515);
  tcase_add_test(tcase, sprintf_test_516);
  tcase_add_test(tcase, sprintf_test_517);
  tcase_add_test(tcase, sprintf_test_518);
  tcase_add_test(tcase, sprintf_test_519);
  // tcase_add_test(tcase, sprintf_test_520);
  tcase_add_test(tcase, sprintf_test_521);
  tcase_add_test(tcase, sprintf_test_522);
  tcase_add_test(tcase, sprintf_test_523);
  // tcase_add_test(tcase, sprintf_test_524);
  tcase_add_test(tcase, sprintf_test_525);
  tcase_add_test(tcase, sprintf_test_526);
  tcase_add_test(tcase, sprintf_test_527);
  tcase_add_test(tcase, sprintf_test_528);
  tcase_add_test(tcase, sprintf_test_529);
  tcase_add_test(tcase, sprintf_test_530);
  tcase_add_test(tcase, sprintf_test_531);
  tcase_add_test(tcase, sprintf_test_532);
  tcase_add_test(tcase, sprintf_test_533);

  //_______________________part3-________________

  tcase_add_test(tcase, sprintf_1_c);
  tcase_add_test(tcase, sprintf_2_c);
  tcase_add_test(tcase, sprintf_3_c);
  tcase_add_test(tcase, sprintf_4_c);
  tcase_add_test(tcase, sprintf_5_c);
  tcase_add_test(tcase, sprintf_7_c);
  tcase_add_test(tcase, sprintf_9_c);
  tcase_add_test(tcase, sprintf_10_c);
  tcase_add_test(tcase, sprintf_12_c);
  tcase_add_test(tcase, sprintf_13_c);
  tcase_add_test(tcase, sprintf_14_c);
  tcase_add_test(tcase, sprintf_16_c);
  tcase_add_test(tcase, sprintf_19_c);
  tcase_add_test(tcase, sprintf_1_signed);
  tcase_add_test(tcase, sprintf_2_signed);
  tcase_add_test(tcase, sprintf_3_signed);
  tcase_add_test(tcase, sprintf_4_signed);
  tcase_add_test(tcase, sprintf_5_signed);
  tcase_add_test(tcase, sprintf_6_signed);
  tcase_add_test(tcase, sprintf_7_signed);
  tcase_add_test(tcase, sprintf_8_signed);
  tcase_add_test(tcase, sprintf_9_signed);
  // tcase_add_test(tcase, sprintf_10_signed);
  tcase_add_test(tcase, sprintf_11_signed);
  tcase_add_test(tcase, sprintf_12_signed);
  tcase_add_test(tcase, sprintf_14_signed);
  tcase_add_test(tcase, sprintf_16_signed);
  tcase_add_test(tcase, sprintf_17_signed);
  // tcase_add_test(tcase, sprintf_18_signed);
  // tcase_add_test(tcase, sprintf_19_signed);
  tcase_add_test(tcase, sprintf_1_f);
  // tcase_add_test(tcase, sprintf_4_f);
  tcase_add_test(tcase, sprintf_8_f);
  tcase_add_test(tcase, sprintf_19_f);
  tcase_add_test(tcase, sprintf_24_f);

  tcase_add_test(tcase, sprintf_1_signed_i);
  tcase_add_test(tcase, sprintf_2_signed_i);
  tcase_add_test(tcase, sprintf_3_signed_i);
  tcase_add_test(tcase, sprintf_4_signed_i);
  tcase_add_test(tcase, sprintf_5_signed_i);
  tcase_add_test(tcase, sprintf_6_signed_i);
  tcase_add_test(tcase, sprintf_7_signed_i);
  tcase_add_test(tcase, sprintf_8_signed_i);
  tcase_add_test(tcase, sprintf_9_signed_i);
  tcase_add_test(tcase, sprintf_11_signed_i);
  tcase_add_test(tcase, sprintf_12_signed_i);
  tcase_add_test(tcase, sprintf_14_signed_i);
  tcase_add_test(tcase, sprintf_16_signed_i);
  // tcase_add_test(tcase, sprintf_17_signed_i);
  tcase_add_test(tcase, sprintf_1_percent);
  tcase_add_test(tcase, sprintf_2_percent);
  tcase_add_test(tcase, sprintf_3_percent);
  tcase_add_test(tcase, sprintf_1_string);
  tcase_add_test(tcase, sprintf_2_string);
  tcase_add_test(tcase, sprintf_3_string);
  tcase_add_test(tcase, sprintf_5_string);
  tcase_add_test(tcase, sprintf_6_string);
  tcase_add_test(tcase, sprintf_7_string);
  tcase_add_test(tcase, sprintf_8_string);
  tcase_add_test(tcase, sprintf_9_string);
  tcase_add_test(tcase, sprintf_11_string);
  tcase_add_test(tcase, sprintf_12_string);
  tcase_add_test(tcase, sprintf_16_string);
  tcase_add_test(tcase, sprintf_1_unsigned);
  tcase_add_test(tcase, sprintf_2_unsigned);
  tcase_add_test(tcase, sprintf_3_unsigned);
  // tcase_add_test(tcase, sprintf_4_unsigned);
  tcase_add_test(tcase, sprintf_5_unsigned);
  tcase_add_test(tcase, sprintf_6_unsigned);
  tcase_add_test(tcase, sprintf_7_unsigned);
  tcase_add_test(tcase, sprintf_8_unsigned);
  tcase_add_test(tcase, sprintf_9_unsigned);
  tcase_add_test(tcase, sprintf_11_unsigned);
  tcase_add_test(tcase, sprintf_12_unsigned);
  tcase_add_test(tcase, sprintf_14_unsigned);
  tcase_add_test(tcase, sprintf_16_unsigned);
  tcase_add_test(tcase, sprintf_17_unsigned);

  srunner_run_all(srunner, CK_NORMAL);
  result = srunner_ntests_failed(srunner);

  srunner_free(srunner);  // чистка памяти srunner

  return result == 0 ? 0 : 1;
}
