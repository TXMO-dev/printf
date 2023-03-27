#include <stdarg.h>
#include <unistd.h>
/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
* _printf - prints output according to a format
* @format: character string containing format specifiers
*
* Return: the number of characters printed (excluding the null byte used to
* end output to strings)
*/
int _printf(const char *format, ...)
{
va_list args;
int i, len = 0, temp_int, negative = 0;
va_start(args, format);
for (i = 0; format && format[i]; i++)
{
if (format[i] == '%')
{
i++;
if (format[i] == 'd' || format[i] == 'i')
{
temp_int = va_arg(args, int);
if (temp_int < 0)
{
negative = 1;
temp_int = -temp_int;
}
len += _putchar(negative ? '-' : '0') + count_digit(temp_int);
print_number(temp_int);
}
else if (format[i] == '%')
{
len += _putchar('%');
}
else
{
len += _putchar('%') + _putchar(format[i]);
}
}
else
{
len += _putchar(format[i]);
}
}
va_end(args);
return (len);
}
/**
* count_digit - counts the number of digits in an integer
* @n: integer to count digits of
*
* Return: number of digits in n
*/
int count_digit(int n)
{
int count = 0;
if (n == 0)
{
return (1);
}
while (n > 0)
{
count++;
n /= 10;
}
return (count);
}
/**
* print_number - prints an integer
* @n: integer to print
*
* Return: void
*/
void print_number(int n)
{
if (n / 10)
{
print_number(n / 10);
}
_putchar(n % 10 + '0');
}
