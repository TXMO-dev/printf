#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
/**
* _printf - prints output according to a format.
* @format: the format string
*
* Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;
va_start(args, format);
if (!format)
{
return (-1);
}
while (format[i])
{
if (format[i] == '%')
{
i++;
if (format[i] == '%')
{
putchar('%');
count++;
}
else if (format[i] == 'c')
{
char c = va_arg(args, int);
putchar(c);
count++;
}
else if (format[i] == 's')
{
char *str = va_arg(args, char *);
if (!str)
{
str = "(null)";
}
while (*str)
{
putchar(*str);
count++;
str++;
}
}
else
{
putchar('%');
putchar(format[i]);
count += 2;
}
}
else
{
putchar(format[i]);
count++;
}
i++;
}
va_end(args);
return (count);
}
