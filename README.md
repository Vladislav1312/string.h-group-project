# string.h-group-project

Разработка основных функций string.h Проект включает в себя:

string.h Типы: 
- size_t
  
string.h Макросы:
- NULL

string.h Функции:
- void *memchr(const void *str, int c, size_t n)
- int memcmp(const void *str1, const void *str2, size_t n)
- void *memcpy(void *dest, const void *src, size_t n)
- void *memset(void *str, int c, size_t n)
- char *strncat(char *dest, const char *src, size_t n)
- char *strchr(const char *str, int c)
- int strncmp(const char *str1, const char *str2, size_t n)
- char *strncpy(char *dest, const char *src, size_t n)
- size_t strcspn(const char *str1, const char *str2)
- char *strerror(int errnum)
- size_t strlen(const char *str)
- char *strpbrk(const char *str1, const char *str2)
- char *strrchr(const char *str, int c)
- char *strstr(const char *haystack, const char *needle)
- char *strtok(char *str, const char *delim)

- void *to_upper(const char *str)
- void *to_lower(const char *str)
- void *insert(const char *src, const char *str, size_t start_index)
- void *trim(const char *src, const char *trim_chars)
  
А также тестовый и заголовочный файлы:

s21_check.c
s21_math.h
Для тестирование кода и создания отчета о покрытии - создаются обьектые файлы и статическая библиотека s21_string.a
