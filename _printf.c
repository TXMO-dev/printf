#include <stdarg.h>
#include "main.h"
/**
  * _printf - function that prints output according to a format
  * @format: format (c, s, d, %)
  *
  * Return: the number of characters printed
  */

int _printf(const char* format, ...) {
    va_list args;
    va_start(args, format);


    for (const char* p = format; *p != '\0'; p++) {
        if (*p == '%') {

            p++;
            switch (*p) {
                case 'c':
                    putchar(va_arg(args, int));
                    break;
                case 'i':
                case 'd':
                    {
                        int num = va_arg(args, int);
                        if (num < 0) {
                            putchar('-');
                            num = -num;
                        }
                        if (num == 0) {
                            putchar('0');
                        }
                        else {
                            int digits[10];
                            int i = 0;
                            while (num > 0) {
                                digits[i++] = num % 10;
                                num /= 10;
                            }
                            while (i > 0) {
                                putchar(digits[--i] + '0');
                            }
                        }
                    }
                    break;
                case 's':

                    {
                        const char* str = va_arg(args, const char*);
                        while (*str != '\0') {
                            putchar(*str++);
                        }
                    }
                    break;
                default

                    putchar(*p);
                    break;
            }
        }
        else {

            putchar(*p);
        }
    }

    va_end(args);
}
