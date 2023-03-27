#include <stdio.h>
#include <stdarg.h>
/**
* _printf - print output according to a format
* @format: format string
*
* Return: number of characters printed
*         -1 if an error occurs
*/
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;
char c;
while ((c = *format++) != '\0')
{
if (c == '%')
{
c = *format++;
switch (c)
{
case 'c':
putchar(va_arg(args, int));
count++;
break;
case 's':
{
const char *str = va_arg(args, const char *);
while (*str != '\0')
{
putchar(*str++);
count++;
}
break;
}
case '%':
putchar('%');
count++;
break;
default:
fprintf(stderr, "error: invalid conversion specifier %c\n", c);
va_end(args);
return (-1);
}
} else
{
putchar(c);
count++;
}
}
va_end(args);
return (count);
}
