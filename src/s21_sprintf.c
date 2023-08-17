#include <math.h>
#include <stdarg.h>

#include "s21_string.h"

typedef struct {
  int minus;  // флаг - (выравнивание по левому краю)
  int plus;   // флаг + (явное указывание на знак)
  int space;  // флаг space (вставляется пробел перед значением)
  int hash;   // флаг # (0, 0x, 0X для o, x, X; . для e, E, f)
  int zero;   // флаг 0
  int width;  // ширина
  int accuracy;       // точность
  char length;        // длина (%lf/%hf/...)
  int number_system;  // основание системы счисления
  int dot;            // наличие точки в числе
  int with_accuracy;  // вспомогательный для float
} opt;

void init_struct(opt *params);
const char *parse_params(const char *ptr, opt *params, va_list *args);
const char *parse_flags(const char *ptr, opt *params);
const char *parse_width_accuracy(const char *ptr, opt *params, va_list *args,
                                 int flag);
int flag0(opt params, int size_mas, char *mas);
int add_space_by_width(opt params, int size_mas, char *mas, long int num);
int add_space_by_width_u(opt params, int size_mas, char *mas);
char *reverse_and_space_minus(opt params, char *str, int size_mas, char *mas);

char *spec_c(char *str, opt params, va_list *args);
char *spec_d(char *str, opt params, long int d_i_u_sym);
char *spec_u(char *str, opt params, va_list *args);
char *spec_s(char *str, opt params, va_list *args);
char *spec_f(char *str, opt params, va_list *args);
s21_size_t calc_size_float(long double f_sym, opt params);
char *ftoa(char *str_to_float, long double f_sym, opt params,
           s21_size_t size_float);

int s21_sprintf(char *str, const char *format, ...) {
  char *ptr_start = str;
  s21_memset(str, '\0', s21_strlen(str));
  const char *symb = S21_NULL;
  opt params;
  va_list args;
  long int d_i_u_sym;
  va_start(args, format);
  for (symb = format; *symb; symb++) {
    if (symb[0] == '%' && symb[1] == '%') {
      *str = '%';
      str++;
    }
    if (*symb != '%') {
      *str = *symb;
      str++;
    } else {
      init_struct(&params);
      symb++;
      symb = parse_params(symb, &params, &args);

      switch (*symb) {  // тут пойдет добавление в буффер
        case 'c':
          str = spec_c(str, params, &args);
          break;
        case 's':
          str = spec_s(str, params, &args);
          break;
        case 'f':
          str = spec_f(str, params, &args);
          break;
        case 'd':
        case 'i':
          d_i_u_sym = (long int)va_arg(args, long int);
          str = spec_d(str, params, d_i_u_sym);
          break;
        case 'u':
          str = spec_u(str, params, &args);
          break;
      }
    }
  }
  va_end(args);
  int length = str - ptr_start;
  return length;
}

void init_struct(opt *params) {
  params->minus = 0;
  params->plus = 0;
  params->space = 0;
  params->hash = 0;
  params->zero = 0;
  params->width = 0;
  params->accuracy = 0;
  params->length = 0;
  params->number_system = 10;
  params->dot = 0;
  params->with_accuracy = 0;
}

const char *parse_params(const char *ptr, opt *params, va_list *args) {
  ptr = parse_flags(ptr, params);
  ptr = parse_width_accuracy(ptr, params, args, 1);  // 1 - ширина, 0 - точность
  if (*ptr == '.') {
    params->dot = 1;
    params->zero = 0;
    ptr++;
    ptr = parse_width_accuracy(ptr, params, args, 0);
  }
  if (*ptr == 'h') {  // длина
    params->length = 'h';
    ptr++;
  } else if (*ptr == 'l') {
    params->length = 'l';
    ptr++;
  } else if (*ptr == 'L') {
    params->length = 'L';
    ptr++;
  }
  return ptr;
}

const char *parse_flags(const char *ptr, opt *params) {
  while (ptr) {
    if (*ptr == '-')
      params->minus = 1;
    else if (*ptr == '+')
      params->plus = 1;
    else if (*ptr == ' ')
      params->space = 1;
    else if (*ptr == '#')
      params->hash = 1;
    else if (*ptr == '0')
      params->zero = 1;
    else
      break;
    ptr++;
  }
  params->space = params->space ? !params->plus : params->space;
  params->zero = params->zero ? !params->minus : params->zero;
  return ptr;
}

const char *parse_width_accuracy(const char *ptr, opt *params, va_list *args,
                                 int flag) {
  if (!flag) params->with_accuracy = 1;
  if (*ptr == '*') {
    if (flag)
      params->width = va_arg(*args, int);
    else
      params->accuracy = va_arg(*args, int);
    ptr++;
  }
  while (ptr) {
    if (*ptr >= '0' && *ptr <= '9') {
      if (flag) {
        params->width *= 10;
        params->width += *ptr - '0';
      } else {
        params->accuracy *= 10;
        params->accuracy += *ptr - '0';
      }
    } else {
      break;
    }
    ptr++;
  }
  return ptr;
}

char *spec_c(char *str, opt params, va_list *args) {
  int c_sym = va_arg(*args, int);
  while (params.width - 1 > 0 && !params.minus) {
    *str = ' ';
    str++;
    params.width--;
  }
  *str = c_sym;
  str++;
  while (params.width - 1 > 0 && params.minus) {
    *str = ' ';
    str++;
    params.width--;
  }
  *str = '\0';
  return str;
}

char *spec_d(char *str, opt params, long int d_i_u_sym) {
  //////////////////Проверка на длину значения//////////////////
  if (params.length == 'h') {
    d_i_u_sym = (short)d_i_u_sym;
  } else if (!params.length) {
    d_i_u_sym = (int)d_i_u_sym;
  }

  //////////////////Выделение памяти для числа с параметрами//////////////////

  s21_size_t size_for_d_i_u_sym = 0;

  long int dublicate_num = d_i_u_sym;
  if (dublicate_num < 0) {
    dublicate_num = -dublicate_num;
  }
  while (dublicate_num > 0) {
    dublicate_num /= 10;
    size_for_d_i_u_sym++;
  }
  int len = size_for_d_i_u_sym;
  if ((s21_size_t)params.width > size_for_d_i_u_sym) {
    size_for_d_i_u_sym = params.width;
  }
  if ((s21_size_t)params.accuracy > size_for_d_i_u_sym) {
    size_for_d_i_u_sym = params.accuracy;
  }
  if (params.space && !params.plus && d_i_u_sym >= 0) {
    size_for_d_i_u_sym++;
  }
  if (d_i_u_sym < 0 || params.plus) {
    size_for_d_i_u_sym++;
  }
  if (d_i_u_sym == 0 && dublicate_num == 0 &&
      (!params.width || !params.accuracy || !params.space || !params.dot)) {
    size_for_d_i_u_sym++;
  }
  // Создание массива под число с параметрами
  // char *number_for_str = malloc(sizeof(char) * size_for_d_i_u_sym);
  char *number_for_str = (char *)calloc(size_for_d_i_u_sym, sizeof(char));
  if (params.width > len && params.minus && d_i_u_sym < 0) {
    size_for_d_i_u_sym--;
  }
  if (d_i_u_sym < 0) {
    d_i_u_sym = -d_i_u_sym;
    s21_itoa(d_i_u_sym, number_for_str);  // запись числа в массив
    d_i_u_sym = -d_i_u_sym;
  } else {
    s21_itoa(d_i_u_sym, number_for_str);  // запись числа в массив
  }
  // int length_num = s21_strlen(number_for_str);

  // Flag - 0
  size_for_d_i_u_sym = flag0(params, size_for_d_i_u_sym, number_for_str);

  // Обработка параметров +/-/' '

  if (d_i_u_sym < 0 && size_for_d_i_u_sym > 0) {
    number_for_str = s21_strcat(number_for_str, "-");
    size_for_d_i_u_sym--;
  }
  if (d_i_u_sym >= 0 && params.plus && size_for_d_i_u_sym) {
    number_for_str = s21_strcat(number_for_str, "+");
    size_for_d_i_u_sym--;
  }

  if (params.space == 1 && d_i_u_sym >= 0 && !params.plus &&
      size_for_d_i_u_sym > 0) {
    number_for_str = s21_strcat(number_for_str, " ");
    size_for_d_i_u_sym--;
  }

  // Add_space_by_width
  size_for_d_i_u_sym =
      add_space_by_width(params, size_for_d_i_u_sym, number_for_str, d_i_u_sym);

  // Reverse and space with flag minus
  str =
      reverse_and_space_minus(params, str, size_for_d_i_u_sym, number_for_str);

  free(number_for_str);
  return str;
}

char *spec_u(char *str, opt params, va_list *args) {
  //////////////////Проверка на длину значения//////////////////
  unsigned long u_sym = 0;

  if (params.length == 'l') {
    u_sym = (unsigned long)va_arg(*args, unsigned long);
  } else {
    u_sym = (unsigned int)va_arg(*args, unsigned int);
  }
  s21_size_t size_for_u_sym = 0;

  unsigned long dubl_u = u_sym;

  while (dubl_u > 0) {
    dubl_u /= 10;
    size_for_u_sym++;
  }

  if ((s21_size_t)params.width > size_for_u_sym) {
    size_for_u_sym = params.width;
  }
  if ((s21_size_t)params.accuracy > size_for_u_sym) {
    size_for_u_sym = params.accuracy;
  }
  if (u_sym == 0 && dubl_u == 0 && (!params.width && !params.accuracy)) {
    size_for_u_sym++;
  }
  char *u_for_str = (char *)calloc(size_for_u_sym, sizeof(char));

  s21_uitoa(u_sym, u_for_str);

  // Flag - 0
  size_for_u_sym = flag0(params, size_for_u_sym, u_for_str);

  // Add_space_by_width
  size_for_u_sym = add_space_by_width_u(params, size_for_u_sym, u_for_str);

  // Reverse and space with flag minus
  str = reverse_and_space_minus(params, str, size_for_u_sym, u_for_str);

  free(u_for_str);
  return str;
}

char *spec_s(char *str, opt params, va_list *args) {
  char *s_string = va_arg(*args, char *);
  if (s_string) {
    int s_len = (int)s21_strlen(s_string), spaces = 0, n = 0;

    if (params.width > 0 && params.dot && params.width > params.accuracy) {
      spaces = params.width - params.accuracy;
    } else {
      if (params.width < s_len) params.width = s_len;

      spaces = params.width - s_len;
    }
    if ((params.accuracy == 0 && !params.dot) || params.accuracy >= s_len)
      n = s_len;
    else {
      n = (params.accuracy);
    }

    while (spaces && !params.minus) {
      *str = ' ';
      spaces--;
      str++;
    }

    while (n > 0 && *s_string != '\0') {
      *str = *s_string;
      str++;
      s_string++;
      n--;
    }
    while (spaces && params.minus) {
      *str = ' ';
      spaces--;
      str++;
    }
  } else {
    str = s21_strcat(str, "(null)");
  }
  *str = '\0';
  return str;
}

int flag0(opt params, int size_mas, char *mas) {
  int accuracy_static = params.accuracy;  // если точность < кол-во символов в
                                          // числе ? запрет на печать нулей

  int length_num = s21_strlen(mas);  // кол-во символов числа в
                                     // массиве
  size_mas -= length_num;
  // if(params.zero == true)
  // if(params.accuracy > params.width)

  if (params.accuracy > length_num) {
    params.accuracy -= length_num;
  }
  if (length_num == 1 && params.zero == 1 && params.width == 0 &&
      params.accuracy == 0) {
    params.zero = 0;
  }
  // Обработка параметра - 0
  while (params.accuracy > 0 && size_mas > 0) {
    if ((size_mas == 1 && params.plus && params.space) ||
        accuracy_static < length_num) {
      break;
    }
    mas = s21_strcat(mas, "0");
    params.accuracy--;
    size_mas--;
  }
  return size_mas;
}

int add_space_by_width(opt params, int size_mas, char *mas, long int num) {
  // Запись пустого пространства(длина больше, чем число)
  if (size_mas > 0 && params.minus == 0) {
    if (num < 0 || params.plus) {  // убирает пробел, если есть знак
      size_mas--;
    }
    while (size_mas > 0 && mas) {
      if (params.zero == 1) {
        mas = s21_strcat(mas, "0");
      } else
        mas = s21_strcat(mas, " ");
      size_mas--;
    }
  }
  return size_mas;
}

int add_space_by_width_u(opt params, int size_mas, char *mas) {
  // Запись пустого пространства(длина больше, чем число)
  if (params.minus == 0) {
    while (size_mas > 0 && mas) {
      if (params.zero == 1) {
        mas = s21_strcat(mas, "0");
      } else
        mas = s21_strcat(mas, " ");
      size_mas--;
    }
  }
  return size_mas;
}

char *reverse_and_space_minus(opt params, char *str, int size_mas, char *mas) {
  // Переворачиваем массив и заносим в str
  char *last_char =
      mas + s21_strlen(mas) - 1;  // указатель на последний символ массива
  short leng = s21_strlen(mas);
  for (; leng > 0; last_char--, leng--) {
    *str = *last_char;
    str++;
  }
  if (size_mas > 0 && params.minus == 1) {
    if (params.plus) {
      size_mas--;
    }
    for (; size_mas > 0; str++) {
      *str = ' ';
      size_mas--;
    }
  }
  *str = '\0';
  return str;
}

char *spec_f(char *str, opt params, va_list *args) {
  long double f_sym;
  if (params.length == 'L')
    f_sym = va_arg(*args, long double);
  else
    f_sym = va_arg(*args, double);

  // поиск длины числа
  s21_size_t size_float = calc_size_float(f_sym, params);
  s21_size_t temp_len = 0;
  char *str_to_double = calloc(size_float, sizeof(char));
  if (str_to_double) {
    str_to_double = ftoa(str_to_double, f_sym, params, size_float);
    // переворачиваем массив, добавляем оставшиеся пробелы

    temp_len = s21_strlen(str_to_double);

    char *last_char = str_to_double + s21_strlen(str_to_double) -
                      1;  // указатель на последний символ массива
    short leng = s21_strlen(str_to_double);
    for (; leng > 0; last_char--, leng--) {
      *str = *last_char;
      str++;
    }
    size_float -= temp_len;
    while (params.minus && size_float > 0) {
      *str = ' ';
      str++;
      size_float--;
    }

    free(str_to_double);
  }
  *str = '\0';
  return str;
}

s21_size_t calc_size_float(long double f_sym, opt params) {
  s21_size_t size_float = 1;  // 1 под точку

  // отражаем число если отрицательное
  long double copy_f_sym = f_sym;
  if (f_sym < 0) copy_f_sym = -f_sym;

  long int int_part = (long int)copy_f_sym;
  if (int_part == 0) size_float++;  // место под 0
  long double fract_part = copy_f_sym - int_part;

  // поиск длины целой части
  int size_int = 0;
  while (int_part > 0) {
    size_float++;
    size_int++;
    int_part /= 10;
    if (size_int) continue;
  }

  // считаем длину дробной части. если точность не указана, берем стандартно 6
  int size_fract = 0;
  int cur_accuracy = params.with_accuracy ? params.accuracy : 6;
  while (size_fract < cur_accuracy) {
    size_float++;  // добавляем в длину всего числа
    size_fract++;  // и отдельно дробной части
    fract_part *= 10;
    if (fract_part) continue;
  }
  // проверки на флаги
  if (copy_f_sym == 0 && size_float == 0 &&
      (params.accuracy || params.width || params.space))
    size_float++;

  if ((s21_size_t)params.width > size_float && !params.minus) {
    size_float = params.width;
  }
  if (params.accuracy > size_fract)
    size_float += (params.accuracy - size_fract);

  if (params.space || params.plus || f_sym < 0) {
    size_float++;
  }
  if ((s21_size_t)params.width > size_float && params.minus) {
    size_float = params.width;
  }

  if (size_float == 1 && copy_f_sym == 0 && !params.accuracy && !params.width &&
      !params.space && !params.dot) {
    size_float++;
  }
  return size_float;
}

char *ftoa(char *str_to_float, long double f_sym, opt params,
           s21_size_t size_float) {
  long double num = f_sym;
  if (f_sym < 0) num = -f_sym;

  // целая и дробная части
  long int int_part = (long int)num;
  long double fract_part_float = num - int_part;

  // если точность не задана, по умолчанию 6
  int cur_accuracy = params.with_accuracy ? params.accuracy : 6;
  fract_part_float += 1;
  while (cur_accuracy > 0) {
    fract_part_float *= 10;
    cur_accuracy--;
  }
  cur_accuracy = params.with_accuracy ? params.accuracy : 6;

  // округление
  long long int fract_part = (long long int)(fract_part_float + 0.500002);
  // добавление и перевод чисел в строку
  // обработка дробной части
  int i = 0;
  for (; fract_part && size_float && str_to_float && cur_accuracy;
       i++, fract_part /= 10, size_float--, cur_accuracy--) {
    char sym = fract_part % 10 + '0';
    str_to_float[i] = sym;
  }
  //  обработка точки

  cur_accuracy = params.with_accuracy ? params.accuracy : 6;
  if ((params.with_accuracy && cur_accuracy != 0) || !params.with_accuracy) {
    str_to_float[i] = '.';
    i++;
    size_float--;
  } else if (params.width >= (int)size_float && (params.dot || params.minus)) {
    size_float = params.width;
  } else {
    size_float--;
  }
  // если число в целой части - 0
  if (int_part == 0) {
    str_to_float[i] = '0';
    str_to_float[i + 1] = '\0';
    i++;
    size_float--;
  }

  //  обработка целой части
  int_part = params.with_accuracy && !params.accuracy
                 ? (long int)(num + 0.500002)
                 : int_part;

  for (; int_part > 0 && size_float > 0 && str_to_float;
       i++, int_part /= 10, size_float--) {
    char sym = int_part % 10 + '0';
    str_to_float[i] = sym;
    if (size_float == 1) {
      str_to_float[i] = int_part % 10 + '0';
      str_to_float[i + 1] = '\0';
      size_float--;
      i++;
      break;
    }
  }

  // проверка на обработку параметра - 0
  int flag = (params.space || params.plus || f_sym < 0) ? 1 : 0;
  int flag_zero = 0;
  if (cur_accuracy - i > 0) {
    cur_accuracy -= i;
    params.zero = 1;
  } else
    flag_zero = 1;
  if (size_float == 1 && params.zero == 1 && flag) params.zero = 0;

  // обработка параметров +/-/' '
  if (f_sym < 0 && size_float) {
    str_to_float[i] = '-';
    i++;
    size_float--;
  }
  if (f_sym > 0 && params.plus && size_float) {
    str_to_float[i] = '+';
    i++;
    size_float--;
  }
  if (params.space && f_sym >= 0 && size_float) {
    str_to_float[i] = ' ';
    i++;
    size_float--;
  }

  // обработка параметра - 0
  while (params.zero && str_to_float && (size_float - flag > 0) &&
         (cur_accuracy || flag_zero) && !params.plus) {
    if (size_float == 1 && flag) break;
    str_to_float[i] = '0';
    i++;
    cur_accuracy--;
    size_float--;
  }
  // запись пустого пространства (нет п.минус и осталась длина)
  if (size_float > 0 && !params.minus) {
    while (size_float - flag > 0 && str_to_float) {
      str_to_float[i] = ' ';
      i++;
      size_float--;
    }
  }
  return str_to_float;
}
