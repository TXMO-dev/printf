#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

int _printf(const char *format, ...) {
    int chars_printed = 0;
    int precision = -1;
    int field_width = -1;
    int zero_flag = 0;
    int minus_flag = 0;
    int plus_flag = 0;
    int space_flag = 0;
    int hash_flag = 0;
    int length_modifier = 0;
    int base = 0;
    int uppercase = 0;
    int reverse = 0;
    int rot13 = 0;
    char buffer[BUF_SIZE];
    char *buffer_ptr = buffer;
    const char *format_ptr = format;
    va_list arg_list;
    va_start(arg_list, format);

    while (*format_ptr != '\0') {
        if (*format_ptr != '%') {
            *buffer_ptr++ = *format_ptr++;
            chars_printed++;
            continue;
        }
        format_ptr++;
        precision = -1;
        field_width = -1;
        zero_flag = 0;
        minus_flag = 0;
        plus_flag = 0;
        space_flag = 0;
        hash_flag = 0;
        length_modifier = 0;
        base = 10;
        uppercase = 0;
        reverse = 0;
        rot13 = 0;

        while (*format_ptr != '\0') {
            if (*format_ptr == '0' && field_width == -1 && precision == -1 && !minus_flag) {
                zero_flag = 1;
                format_ptr++;
            } else if (*format_ptr == '-') {
                minus_flag = 1;
                zero_flag = 0;
                format_ptr++;
            } else if (*format_ptr == '+') {
                plus_flag = 1;
                space_flag = 0;
                format_ptr++;
            } else if (*format_ptr == ' ') {
                space_flag = (!plus_flag) ? 1 : 0;
                format_ptr++;
            } else if (*format_ptr == '#') {
                hash_flag = 1;
                format_ptr++;
            } else {
                break;
            }
        }

        if (*format_ptr == '*') {
            field_width = va_arg(arg_list, int);
            if (field_width < 0) {
                minus_flag = 1;
                field_width = -field_width;
            }
            format_ptr++;
        } else {
            field_width = 0;
            while (*format_ptr >= '0' && *format_ptr <= '9') {
                field_width = field_width * 10 + (*format_ptr - '0');
                format_ptr++;
            }
        }

        if (*format_ptr == '.') {
            format_ptr++;
            if (*format_ptr == '*') {
                precision = va_arg(arg_list, int);
                format_ptr++;
            } else {
                precision = 0;
                while (*format_ptr >= '0' && *format_ptr <= '9') {
                    precision = precision * 10 + (*format_ptr - '0');
                    format_ptr++;
                }
            }
        }

        while (*format_ptr != '\)
	{
	if (*format_ptr == 'h' || *format_ptr == 'l' || *format_ptr == 'L') {
            if (*format_ptr == 'h') {
                length_modifier = -1;
            } else if (*format_ptr == 'l') {
                length_modifier = 1;
            } else if (*format_ptr == 'L') {
                length_modifier = 2;
            }
            format_ptr++;
        }

        if (*format_ptr == 'c') {
            char c = va_arg(arg_list, int);
            *buffer_ptr++ = c;
            chars_printed++;
        } else if (*format_ptr == 's') {
            const char *s = va_arg(arg_list, const char *);
            if (s == NULL) {
                s = "(null)";
            }
            int len = 0;
            while (s[len] != '\0' && (precision == -1 || len < precision)) {
                len++;
            }
            field_width -= len;
            if (!minus_flag) {
                while (field_width-- > 0) {
                    *buffer_ptr++ = zero_flag ? '0' : ' ';
                    chars_printed++;
                }
            }
            for (int i = 0; i < len; i++) {
                *buffer_ptr++ = s[i];
                chars_printed++;
            }
            if (minus_flag) {
                while (field_width-- > 0) {
                    *buffer_ptr++ = ' ';
                    chars_printed++;
                }
            }
        } else if (*format_ptr == 'd' || *format_ptr == 'i' || *format_ptr == 'u' || *format_ptr == 'x' || *format_ptr == 'X' || *format_ptr == 'o') {
            if (*format_ptr == 'd' || *format_ptr == 'i') {
                base = 10;
            } else if (*format_ptr == 'u') {
                base = 10;
                unsigned long long_value = va_arg(arg_list, unsigned);
                long_value = (long)long_value;
            } else if (*format_ptr == 'x' || *format_ptr == 'X') {
                base = 16;
                uppercase = (*format_ptr == 'X');
            } else if (*format_ptr == 'o') {
                base = 8;
            }
            if (length_modifier == -1) {
                int short_value = va_arg(arg_list, int);
                long_value = (long)short_value;
            } else if (length_modifier == 1) {
                long_value = va_arg(arg_list, long);
            } else {
                long_value = va_arg(arg_list, int);
            }
            if (long_value < 0 && base == 10) {
                *buffer_ptr++ = '-';
                chars_printed++;
                long_value = -long_value;
            }
            if (hash_flag && long_value != 0 && (base == 8 || base == 16)) {
                if (base == 8) {
                    *buffer_ptr++ = '0';
                    chars_printed++;
                } else if (base == 16) {
                    *buffer_ptr++ = '0';
                    *buffer_ptr++ = uppercase ? 'X' : 'x';
                    chars_printed += 2;
                }
            }
            int digits = 0;
            do {
                int digit = long_value % base;
                if (digit < 10) {
                    *buffer_ptr++ = '0' + digit;
                } else {
		
		}
	}
