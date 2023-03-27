#include <stdio.h>
#include <stdarg.h>
#include <string.h>
/**
* print_char - Print a single character to stdout.
* @c: The character to print.
*
* Return: Always 1.
*/
int print_char(char c)
{
putchar(c);
return (1);
}
/**
 * print_string - Print a null-terminated string to stdout.
 * @s: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(char *s)
{
int len = strlen(s);
fputs(s, stdout);
return (len);
}
typedef int (*print_fn)(void *);
/**
 * _printf - Print formatted output to stdout.
 * @format: The format string.
 * @...: The arguments to format into the string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
va_list args;
int printed_chars = 0;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
print_fn printers[] = { print_char, print_string, print_char };
char specifiers[] = { 'c', 's', '%' };
char *specifier = strchr(specifiers, *format);
if (specifier)
{
int index = specifier - specifiers;
void *arg = va_arg(args, void *);
printed_chars += printers[index](arg);
}
}
else
{
printed_chars += print_char(*format);
}
format++;
}
va_end(args);
return (printed_chars);
}
