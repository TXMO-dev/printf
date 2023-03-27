#include <unistd.h>
#include "main.h"
/**
 * _putchar - writes a character to stdout
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
 * _printf - Custom printf function
 * @format: String to be printed, with optional format specifiers
 *
 * Return: Number of characters printed (excluding null byte used to end output
 * to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0, len = 0;
	char *str, *s;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			len++;
			i++;
			continue;
		}

		i++;

		switch (format[i])
		{
			case '%':
				_putchar('%');
				len++;
				break;

			case 'c':
				_putchar(va_arg(args, int));
				len++;
				break;

			case 's':
				s = va_arg(args, char *);
				if (!s)
					s = "(null)";
				while (s[j])
				{
					_putchar(s[j]);
					len++;
					j++;
				}
				j = 0;
				break;

			case 'd':
			case 'i':
				len += print_number(va_arg(args, int));
				break;

			default:
				_putchar('%');
				_putchar(format[i]);
				len += 2;
		}

		i++;
	}

	va_end(args);

	return (len);
}

/**
 * print_number - Prints an integer
 * @n: Integer to be printed
 *
 * Return: Number of digits printed
 */
int print_number(int n)
{
	unsigned int num;
	int digits = 0;

	if (n < 0)
	{
		_putchar('-');
		digits++;
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		digits += print_number(num / 10);

	_putchar('0' + (num % 10));
	digits++;

	return (digits);
}
