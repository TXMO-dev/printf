#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
* _putchar - writes a character to stdout
* @c: The character to print
*
* Return: 1 on success, -1 on error
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
* _printf - produces output according to a format
* @format: character string containing directives
*
* Return: the number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
count += _putchar(va_arg(args, int));
}
else if (*format == 's')
{
count += printf("%s", va_arg(args, char *));
}
else if (*format == 'd' || *format == 'i')
{
count += printf("%d", va_arg(args, int));
}
else if (*format == 'b')
{
unsigned int num = va_arg(args, unsigned int);
int bit = 0;
char binary[32];
if (num == 0)
{
count += _putchar('0');
}
else
{
while (num > 0)
{
binary[bit++] = (num & 1) ? '1' : '0';
num >>= 1;
}
while (bit--)
{
count += _putchar(binary[bit]);
}
}
}
else if (*format == '%')
{
count += _putchar('%');
}
else
{
_putchar('%');
_putchar(*format);
count += 2;
}
}
else
{
_putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
